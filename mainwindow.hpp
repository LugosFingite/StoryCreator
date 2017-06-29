/*  mainwindow.hpp MainWindow - Yann BOUCHER (yann) 19/06/2017
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
#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <QGraphicsScene>

#include "graphview.hpp"
#include "util.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    signals:
        void nodeInfoChanged(NodeInfo);

    protected:
        void changeEvent(QEvent *e);

    private slots:
        void on_pageEdit_textEdited(const QString& txt);

        void on_addLinkButton_clicked();
        void on_link1Button_clicked();
        void on_link2Button_clicked();
        void on_deleteEdgeButton_clicked();

        void on_textColorButton_clicked();
        void on_edgeColorButton_clicked();

        void on_imageButton_clicked();
        void on_sonButton_clicked();

        void on_action_Save_triggered();
        void on_action_Open_triggered();
        void on_action_New_triggered();

    private slots:
        void handleNodeFocus();
        void handleNodeInfoChange();
        void updateNodeInfo(NodeInfo);
        void updateEdgeInfo();

        void setTextColor(const QColor& color);
        void setEdgeColor(const QColor& color);

    private:
        void setNodePage();
        void setEdgePage();
        void setNoPage();
        void updateNodePage();
        void updateEdgePage();

    private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
