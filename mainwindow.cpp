/*  mainwindow.cpp MainWindow - Yann BOUCHER (yann) 19/06/2017
**
**
**            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
**                    Version 2, December 2004
**
** Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
**
** Everyone is permitted to copy and distribute verbatim or modified
** copies of this license document, and changing it is allowed as long
** as the name is changed.
**
**            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
**   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
**
**  0. You just DO WHAT THE FUCK YOU WANT TO.
*/
#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <QPalette>

#include "jsonloading.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->link1Button->hide();
    ui->link2Button->hide();

    connect(ui->pageEdit, &QLineEdit::textChanged, this, &MainWindow::handleNodeInfoChange);
    connect(ui->imageEdit, &QLineEdit::textChanged, this, &MainWindow::handleNodeInfoChange);
    connect(ui->sonEdit, &QLineEdit::textChanged, this, &MainWindow::handleNodeInfoChange);
    connect(ui->descEdit, &QTextEdit::textChanged, this, &MainWindow::handleNodeInfoChange);
    connect(ui->textColorButton, &QPushButton::clicked, this, &MainWindow::handleNodeInfoChange);
    connect(ui->musicLoopCheck, &QCheckBox::clicked, this, &MainWindow::handleNodeInfoChange);

    connect(this, &MainWindow::nodeInfoChanged, this, &MainWindow::updateNodeInfo);

    connect(ui->edgeDescEdit, &QTextEdit::textChanged, this, &MainWindow::updateEdgeInfo);

    connect(ui->graphView, &GraphView::focusChanged, this, &MainWindow::handleNodeFocus);

    ui->graphView->addNode("Intro");

    ui->graphView->unselectAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addLinkButton_clicked()
{
    // if this signal is sent, we can assert that only one node is selected
    NodeItem& item = *ui->graphView->selectedNodes().back();

    ui->graphView->addNode(ui->graphView->findFreeName(item.info.page), item.info.page);
}

void MainWindow::on_link1Button_clicked()
{
    NodeItem& from = *ui->graphView->selectedNodes()[0];
    NodeItem& to = *ui->graphView->selectedNodes()[1];

    ui->graphView->addEdge(from.info.page, to.info.page);

    updateNodePage();
}

void MainWindow::on_link2Button_clicked()
{
    NodeItem& from = *ui->graphView->selectedNodes()[1];
    NodeItem& to = *ui->graphView->selectedNodes()[0];

    ui->graphView->addEdge(from.info.page, to.info.page);

    updateNodePage();
}

void MainWindow::on_deleteEdgeButton_clicked()
{
    ui->graphView->removeSelection();

    handleNodeFocus();
}

void MainWindow::on_textColorButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, tr("Choisir la couleur du texte"));

    if (color.isValid())
    {
        setTextColor(color);
    }
}

void MainWindow::on_edgeColorButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, tr("Choisir la couleur du texte"));

    if (color.isValid())
    {
        setEdgeColor(color);
    }
}

void MainWindow::on_imageButton_clicked()
{
    QString image = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier image"), "",
                                                 tr("Images (*.png *.bmp *.pcx *.tga *.tif *.xpm *.jpg *.gif *.jpeg)"));

    ui->imageEdit->setText(image);
}

void MainWindow::on_sonButton_clicked()
{
    QString son = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier son"), "",
                                               tr("Son (*.ogg *.wav)"));

    ui->sonEdit->setText(son);
}

void MainWindow::on_action_Save_triggered()
{
    try
    {
        QString dir = QFileDialog::getExistingDirectory(this, tr("Sélectionner un dossier à écrire"), "",
                                                        QFileDialog::ShowDirsOnly);

        if (!dir.isEmpty())
        {

            jsonloading::save(ui->graphView->buildGraph(), dir);

            statusBar()->showMessage(tr("Projet sauvegardé."), 10000);

        }
    }
    catch (const std::exception& e)
    {
        QMessageBox::critical(this, tr("Erreur lors de la sauvegarde !"), tr("Erreur : ") + e.what());
        statusBar()->showMessage(tr("Erreur lors de la sauvegarde"), 10000);
    }
}

void MainWindow::on_action_Open_triggered()
{
    try
    {
        QString dir = QFileDialog::getExistingDirectory(this, tr("Sélectionner un dossier à ouvrir"), "",
                                                        QFileDialog::ShowDirsOnly | QFileDialog::ReadOnly);

        if (!dir.isEmpty())
        {

            Graph graph = jsonloading::load(dir);

            ui->graphView->loadFromGraph(graph);

            statusBar()->showMessage(tr("Projet chargé."), 10000);

        }
    }
    catch (const std::exception& e)
    {
        QMessageBox::critical(this, tr("Erreur lors du chargement !"), tr("Erreur : ") + e.what());
        statusBar()->showMessage(tr("Erreur lors du chargement"), 10000);
    }
}

void MainWindow::on_action_New_triggered()
{
    auto result = QMessageBox::question(this, tr("Attention"), tr("Voulez-vous sauvegarder avant de créer un nouveau scénario ?"),
                                        QMessageBox::Close, QMessageBox::No, QMessageBox::Yes);
    if (result == QMessageBox::Yes)
    {
        ui->action_Save->trigger();
    }
    else if (result == QMessageBox::Close)
    {
        return;
    }

    ui->graphView->removeAll();
    ui->graphView->addNode("Intro");
}

void MainWindow::handleNodeFocus()
{
    if (!ui->graphView->selectedNodes().empty())
    {
        setNodePage();
        updateNodePage();
    }
    else if (ui->graphView->selectedEdges().size() == 1)
    {
        setEdgePage();
        updateEdgePage();

    }
    else
    {
        setNoPage();
    }
}

void MainWindow::handleNodeInfoChange()
{
    NodeInfo info;
    info.page = ui->pageEdit->text();
    info.image = ui->imageEdit->text();
    info.son = ui->sonEdit->text();
    info.desc = ui->descEdit->toPlainText();
    info.color = ui->textColorPixmap->pixmap()->toImage().pixel(0, 0);
    info.loopMusic = ui->musicLoopCheck->isChecked();

    emit nodeInfoChanged(info);
}

void MainWindow::updateNodeInfo(NodeInfo info)
{
    if (!ui->graphView->selectedNodes().empty())
    {
        auto& node = *ui->graphView->selectedNodes()[0];
        node.info = info;
        node.updateInfo();
    }
}

void MainWindow::updateEdgeInfo()
{
    if (!ui->graphView->selectedEdges().empty())
    {
        auto& edge = *ui->graphView->selectedEdges()[0];
        edge.info.desc = ui->edgeDescEdit->toPlainText();
    }
}

void MainWindow::setTextColor(const QColor &color)
{
    QPixmap pixmap(1, 1);
    pixmap.fill(color);
    ui->textColorPixmap->setPixmap(pixmap);

    ui->graphView->selectedNodes()[0]->info.color = color;
}

void MainWindow::setEdgeColor(const QColor &color)
{
    QPixmap pixmap(1, 1);
    pixmap.fill(color);
    ui->edgeColorPixmap->setPixmap(pixmap);

    ui->graphView->selectedEdges()[0]->info.color = color;
}

void MainWindow::updateEdgePage()
{
    auto& edge = *ui->graphView->selectedEdges()[0];
    ui->srcEdgeLabel->setText(edge.from());
    ui->destEdgeLabel->setText(edge.to());
    ui->edgeDescEdit->setText(edge.info.desc);

    setEdgeColor(edge.info.color);
}

void MainWindow::setNodePage()
{
    ui->editor->setCurrentIndex(2);
}

void MainWindow::setEdgePage()
{
    ui->editor->setCurrentIndex(1);
}

void MainWindow::setNoPage()
{
    ui->editor->setCurrentIndex(0);
}

void MainWindow::updateNodePage()
{
    auto nodeInfo = ui->graphView->selectedNodes()[0]->info;
    ui->pageEdit->setText(nodeInfo.page);
    ui->imageEdit->setText(nodeInfo.image);
    ui->sonEdit->setText(nodeInfo.son);
    ui->descEdit->setText(nodeInfo.desc);
    ui->musicLoopCheck->setChecked(nodeInfo.loopMusic);

    if (ui->graphView->selectedNodes().size() == 2)
    {
        if (!ui->graphView->findEdge(ui->graphView->selectedNodes()[0]->info.page, ui->graphView->selectedNodes()[1]->info.page))
        {
            ui->link1Button->setText(tr("Relier '%1' à '%2'").arg(ui->graphView->selectedNodes()[0]->info.page)
                    .arg(ui->graphView->selectedNodes()[1]->info.page));
            ui->link1Button->show();
        }
        else
        {
            ui->link1Button->hide();
        }

        if (!ui->graphView->findEdge(ui->graphView->selectedNodes()[1]->info.page, ui->graphView->selectedNodes()[0]->info.page))
        {
            ui->link2Button->setText(tr("Relier '%2' à '%1'").arg(ui->graphView->selectedNodes()[0]->info.page)
                    .arg(ui->graphView->selectedNodes()[1]->info.page));
            ui->link2Button->show();
        }
        else
        {
            ui->link2Button->hide();
        }
    }
    else
    {
        ui->link1Button->hide();
        ui->link2Button->hide();
    }

    setTextColor(nodeInfo.color);
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void MainWindow::on_pageEdit_textEdited(const QString &txt)
{
    ui->pageEdit->setText(ui->graphView->findFreeName(txt));
}
