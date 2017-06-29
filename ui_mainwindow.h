/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "graphview.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Quitter;
    QAction *action_New;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *editor;
    QWidget *page_3;
    QWidget *page;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLabel *srcEdgeLabel;
    QLabel *label_6;
    QLabel *label_7;
    QTextEdit *edgeDescEdit;
    QPushButton *deleteEdgeButton;
    QLabel *destEdgeLabel;
    QWidget *page_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *pageEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *imageEdit;
    QToolButton *imageButton;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *sonEdit;
    QToolButton *sonButton;
    QLabel *label_4;
    QTextEdit *descEdit;
    QPushButton *addLinkButton;
    QPushButton *link1Button;
    QPushButton *link2Button;
    GraphView *graphView;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(886, 576);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/document-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/document-save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon1);
        action_Quitter = new QAction(MainWindow);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/document-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        editor = new QStackedWidget(centralWidget);
        editor->setObjectName(QStringLiteral("editor"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editor->sizePolicy().hasHeightForWidth());
        editor->setSizePolicy(sizePolicy1);
        editor->setMaximumSize(QSize(400, 16777215));
        editor->setFrameShape(QFrame::Box);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        editor->addWidget(page_3);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        formLayout_2 = new QFormLayout(page);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        srcEdgeLabel = new QLabel(page);
        srcEdgeLabel->setObjectName(QStringLiteral("srcEdgeLabel"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, srcEdgeLabel);

        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_7);

        edgeDescEdit = new QTextEdit(page);
        edgeDescEdit->setObjectName(QStringLiteral("edgeDescEdit"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, edgeDescEdit);

        deleteEdgeButton = new QPushButton(page);
        deleteEdgeButton->setObjectName(QStringLiteral("deleteEdgeButton"));

        formLayout_2->setWidget(3, QFormLayout::SpanningRole, deleteEdgeButton);

        destEdgeLabel = new QLabel(page);
        destEdgeLabel->setObjectName(QStringLiteral("destEdgeLabel"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, destEdgeLabel);

        editor->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        formLayout = new QFormLayout(page_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        pageEdit = new QLineEdit(page_2);
        pageEdit->setObjectName(QStringLiteral("pageEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pageEdit);

        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        imageEdit = new QLineEdit(page_2);
        imageEdit->setObjectName(QStringLiteral("imageEdit"));
        imageEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(imageEdit);

        imageButton = new QToolButton(page_2);
        imageButton->setObjectName(QStringLiteral("imageButton"));

        horizontalLayout_2->addWidget(imageButton);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);

        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sonEdit = new QLineEdit(page_2);
        sonEdit->setObjectName(QStringLiteral("sonEdit"));
        sonEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(sonEdit);

        sonButton = new QToolButton(page_2);
        sonButton->setObjectName(QStringLiteral("sonButton"));

        horizontalLayout_3->addWidget(sonButton);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        descEdit = new QTextEdit(page_2);
        descEdit->setObjectName(QStringLiteral("descEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, descEdit);

        addLinkButton = new QPushButton(page_2);
        addLinkButton->setObjectName(QStringLiteral("addLinkButton"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, addLinkButton);

        link1Button = new QPushButton(page_2);
        link1Button->setObjectName(QStringLiteral("link1Button"));

        formLayout->setWidget(5, QFormLayout::SpanningRole, link1Button);

        link2Button = new QPushButton(page_2);
        link2Button->setObjectName(QStringLiteral("link2Button"));

        formLayout->setWidget(6, QFormLayout::SpanningRole, link2Button);

        editor->addWidget(page_2);

        horizontalLayout->addWidget(editor);

        graphView = new GraphView(centralWidget);
        graphView->setObjectName(QStringLiteral("graphView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(graphView->sizePolicy().hasHeightForWidth());
        graphView->setSizePolicy(sizePolicy2);
        graphView->setMinimumSize(QSize(500, 500));
        graphView->setMouseTracking(true);
        graphView->setDragMode(QGraphicsView::ScrollHandDrag);

        horizontalLayout->addWidget(graphView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 886, 19));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Save);
        menu_File->addSeparator();
        menu_File->addAction(action_Quitter);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_New);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(action_Quitter, SIGNAL(triggered()), MainWindow, SLOT(close()));

        editor->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_Open->setText(QApplication::translate("MainWindow", "&Ouvrir...", Q_NULLPTR));
        action_Open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        action_Save->setText(QApplication::translate("MainWindow", "&Enregister...", Q_NULLPTR));
        action_Save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        action_Quitter->setText(QApplication::translate("MainWindow", "&Quitter", Q_NULLPTR));
        action_Quitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        action_New->setText(QApplication::translate("MainWindow", "&Nouveau...", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "De :", Q_NULLPTR));
        srcEdgeLabel->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Cible :", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Description : ", Q_NULLPTR));
        edgeDescEdit->setPlaceholderText(QApplication::translate("MainWindow", "Entrez le texte du choix...", Q_NULLPTR));
        deleteEdgeButton->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        destEdgeLabel->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Page : ", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Image : ", Q_NULLPTR));
        imageButton->setText(QApplication::translate("MainWindow", "Ouvrir", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Son : ", Q_NULLPTR));
        sonButton->setText(QApplication::translate("MainWindow", "Ouvrir", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Description  :", Q_NULLPTR));
        descEdit->setPlaceholderText(QApplication::translate("MainWindow", "Entrez le texte de la page...", Q_NULLPTR));
        addLinkButton->setText(QApplication::translate("MainWindow", "Ajouter une cible", Q_NULLPTR));
        link1Button->setText(QApplication::translate("MainWindow", "Relier", Q_NULLPTR));
        link2Button->setText(QApplication::translate("MainWindow", "Relier", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindow", "&Fichier", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
