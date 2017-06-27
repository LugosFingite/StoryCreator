/*  graphview.cpp GraphView - Yann BOUCHER (yann) 19/06/2017
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
#include "graphview.hpp"

#include <QRegExp>
#include <QWheelEvent>
#include <QTimeLine>

GraphView::GraphView(QWidget *parent)
    : QGraphicsView(parent)
{
    setScene(&m_scene);

    setViewportUpdateMode(QGraphicsView::FullViewportUpdate); // prevent artifacts

    connect(&m_scene, &QGraphicsScene::selectionChanged, this, &GraphView::handleNewSelection);
}

GraphView::~GraphView()
{
    blockSignals(true);

    std::vector<QString> nodeToRemove;
    for (auto& node : m_nodes)
    {
        nodeToRemove.push_back(node->info.page);
    }
    for (const auto& name : nodeToRemove)
    {
        removeNode(name);
    }
}

void GraphView::addNode(const QString& name, const QString& origin)
{
    NodeItem* item = new NodeItem;
    item->info.page = name;
    m_nodes.push_back(item);

    m_scene.addItem(item);

    if (!origin.isEmpty())
    {
        addEdge(origin, name);

        item->setPos(findNode(origin)->scenePos() + QPointF(0, 2*findNode(origin)->sceneBoundingRect().height()));
    }

    m_scene.clearSelection();

    item->setSelected(true);

    m_scene.update(m_scene.sceneRect());
}

void GraphView::addEdge(const QString &left, const QString &right)
{
    EdgeItem* item = new EdgeItem(*findNode(left), *findNode(right));
    m_edges.push_back(item);

    m_scene.addItem(item);

    m_scene.update(m_scene.sceneRect());
}

void GraphView::removeNode(const QString &name)
{
    for (auto iter = m_edges.begin(); iter != m_edges.end();)
    {
        if ((*iter)->from() == name || (*iter)->to() == name)
        {
            if (findEdge((*iter)->from(), (*iter)->to()))
            {
                removeEdge((*iter)->from(), (*iter)->to());
            }
            else if (findEdge((*iter)->to(), (*iter)->from()))
            {
                removeEdge((*iter)->to(), (*iter)->from());
            }

            if (m_edges.empty())
            {
                break;
            }
            iter = m_edges.begin();
        }
        else
        {
            ++iter;
        }
    }

    m_scene.removeItem(findNode(name));
    auto ptr = findNode(name);

    m_nodes.erase(std::find_if(m_nodes.begin(), m_nodes.end(), [name](NodeItem* item)
    {
                      return item->info.page == name;
                  }));

    delete ptr;

    m_scene.update(m_scene.sceneRect());

    handleNewSelection();
}

void GraphView::removeEdge(const QString &from, const QString &to)
{
    m_scene.removeItem(findEdge(from, to));
    auto ptr = findEdge(from, to);

    m_edges.erase(std::find_if(m_edges.begin(), m_edges.end(), [from, to](EdgeItem* item)
    {
        return item->from() == from && item->to() == to;
    }));

    delete ptr;

    m_scene.update(m_scene.sceneRect());
}

std::vector<NodeItem *> GraphView::selectedNodes()
{
    std::vector<NodeItem *> vector;

    for (const auto& node : m_nodes)
    {
        if (node->isSelected())
        {
            vector.emplace_back(node);
        }
    }

    return vector;
}

std::vector<EdgeItem *> GraphView::selectedEdges()
{
    std::vector<EdgeItem *> vector;

    for (const auto& edge : m_edges)
    {
        if (edge->isSelected())
        {
            vector.emplace_back(edge);
        }
    }

    return vector;
}

QString GraphView::findFreeName(QString basis) const
{
    auto list = getNodeNames();

    if (std::find(list.begin(), list.end(), basis) != list.end())
    {
        QRegExp rx_basis("[^_]*");
        rx_basis.indexIn(basis);
        basis = rx_basis.cap(0);

        QRegExp rx(QRegExp::escape(basis) + "_[0-9]+");

        std::vector<QString> matches;
        for (const auto& name : list)
        {
            if (rx.exactMatch(name))
            {
                matches.emplace_back(name);
            }
        }

        if (matches.empty())
        {
            return basis + "_2";
        }

        std::sort(matches.begin(), matches.end(), [](const QString& lhs, const QString& rhs)
        {
            QRegExp rxlhs("[0-9]+");
            QRegExp rxrhs = rxlhs;

            rxlhs.indexIn(lhs);
            rxrhs.indexIn(rhs);

            return rxlhs.capturedTexts().back().toUInt() < rxrhs.capturedTexts().back().toUInt();
        });

        auto string = matches.back();
        int number = string[string.size()-1].digitValue();
        string.chop(1); // remove digit at end
        return string + QString::number(number + 1);
    }
    else
    {
        return basis;
    }
}



void GraphView::wheelEvent(QWheelEvent *event)
{
    QGraphicsView::wheelEvent(event);

    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15; // see QWheelEvent documentation

    m_numScheduledScalings += numSteps;
    if (m_numScheduledScalings * numSteps < 0) // if user moved the wheel in another direction, we reset previously scheduled scalings
        m_numScheduledScalings = numSteps;

    QTimeLine *anim = new QTimeLine(350, this);
    anim->setUpdateInterval(20);

    connect(anim, SIGNAL (valueChanged(qreal)), SLOT (scalingTime(qreal)));
    connect(anim, SIGNAL (finished()), SLOT (animFinished()));
    anim->start();

    event->accept();
}

void GraphView::keyPressEvent(QKeyEvent *event)
{
    QGraphicsView::keyPressEvent(event);

    switch (event->key())
    {
        case Qt::Key_Delete:
        case Qt::Key_Backspace:
            removeSelection();
            event->accept();
            break;
    }
}

void GraphView::scalingTime(qreal)
{
    qreal factor = 1.0 + qreal(m_numScheduledScalings) / 300.0 * zoomFactor;
    scale(factor, factor);
}

void GraphView::animFinished()
{
    if (m_numScheduledScalings > 0)
    {
        m_numScheduledScalings--;
    }
    else
    {
        m_numScheduledScalings++;
    }
    sender()->~QObject();
}

void GraphView::handleNewSelection()
{
    if (!selectedNodes().empty())
    {
        for (auto& edge : m_edges)
        {
            edge->setSelected(false);
        }
    }
    else if (!selectedEdges().empty())
    {
        for (auto& node : m_nodes)
        {
            node->setSelected(false);
        }
    }
    emit focusChanged();
}


std::vector<QString> GraphView::getNodeNames() const
{
    std::vector<QString> vector;

    for (const auto& node : m_nodes)
    {
        vector.emplace_back(node->info.page);
    }

    return vector;
}

void GraphView::removeSelection()
{
    auto nodes = selectedNodes();
    for (auto iter = nodes.begin(); iter != nodes.end();)
    {
        if (m_nodes.size() > 1)
        {
            removeNode((*iter)->info.page);

            nodes = selectedNodes();
            iter = nodes.begin();
        }
        else
        {
            break;
        }
    }

    auto edges = selectedEdges();
    for (auto iter = edges.begin(); iter != edges.end();)
    {
        removeEdge((*iter)->from(), (*iter)->to());

        edges = selectedEdges();
        iter = edges.begin();
    }
}

void GraphView::removeAll()
{
    auto nodes = getNodeNames();
    for (const auto& node : nodes)
    {
        removeNode(node);
    }
}

Graph GraphView::buildGraph() const
{
    Graph graph;

    for (const auto& node : m_nodes)
    {
        NodeInfo info = node->info;
        graph[info.page].info = info;
        graph[info.page].pos = node->pos();
    }

    for (const auto& edge : m_edges)
    {
        graph[edge->from()].actions[edge->to()] = edge->desc;
    }

    return graph;
}

void GraphView::loadFromGraph(const Graph &graph)
{
    removeAll();

    std::multimap<QString, std::pair<QString, QString>> edges;

    for (const auto& pair : graph)
    {
        const auto& node = pair.second;
        addNode(node.info.page);
        auto nodePtr = findNode(node.info.page);
        nodePtr->info = node.info;
        nodePtr->setPos(node.pos);

        for (const auto& action : node.actions)
        {
            edges.insert({node.info.page, action});
        }
    }

    for (const auto& edge : edges)
    {
        addEdge(edge.first, edge.second.first);
        auto edgePtr = findEdge(edge.first, edge.second.first);
        edgePtr->desc = edge.second.second;
    }
}

NodeItem *GraphView::findNode(const QString &name)
{
    auto result = std::find_if(m_nodes.begin(), m_nodes.end(), [name](NodeItem* item)
    {
                  return item->info.page == name;
});
    if (result != m_nodes.end())
    {
        return *result;
    }
    else
    {
        return nullptr;
    }
}

EdgeItem *GraphView::findEdge(const QString &from, const QString &to)
{
    auto result = std::find_if(m_edges.begin(), m_edges.end(), [from, to](EdgeItem* item)
    {
        return item->from() == from && item->to() == to;
    });
    if (result != m_edges.end())
    {
        return *result;
    }
    else
    {
        return nullptr;
    }
}

void GraphView::unselectAll()
{
    for (auto& item : m_scene.selectedItems())
    {
        item->setSelected(false);
    }
}
