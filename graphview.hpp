/*  graphview.hpp GraphView - Yann BOUCHER (yann) 19/06/2017
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
#ifndef GRAPHVIEW_HPP
#define GRAPHVIEW_HPP

#include <map>
#include <vector>

#include <QGraphicsScene>
#include <QGraphicsView>

#include "nodeitem.hpp"
#include "edgeitem.hpp"
#include "graph.hpp"

class GraphView : public QGraphicsView
{

        Q_OBJECT

    public:
        GraphView(QWidget* parent = nullptr);
        ~GraphView();

    public:
        void addNode(const QString& name, const QString &origin = "");
        void addEdge(const QString& left, const QString& right);

        void removeNode(const QString& name);
        void removeEdge(const QString& from, const QString& to);

        std::vector<NodeItem *> selectedNodes();
        std::vector<EdgeItem *> selectedEdges();

        QString findFreeName(QString basis) const;

        NodeItem *findNode(const QString& name);
        EdgeItem *findEdge(const QString& from, const QString &to);

        void unselectAll();

        void removeSelection();
        void removeAll();

        Graph buildGraph() const;

        void loadFromGraph(const Graph& graph);

    signals:
        void focusChanged();

    public:
        double zoomFactor { 1.25 };

    protected:
        void wheelEvent(QWheelEvent* event) override;
        void keyPressEvent(QKeyEvent* event) override;

    private:
        std::vector<QString> getNodeNames() const;


    private slots:
        void scalingTime(qreal);
        void animFinished();
        void handleNewSelection();

    private:
        QGraphicsScene m_scene;
        std::vector<NodeItem*> m_nodes;
        std::vector<EdgeItem*> m_edges;

        int m_numScheduledScalings { 0 };
};

#endif // GRAPHVIEW_HPP
