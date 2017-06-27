/*  edgeitem.cpp EdgeItem - Yann BOUCHER (yann) 20/06/2017
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
#include "edgeitem.hpp"

#include <QPainter>
#include <QVector2D>

#include <QtDebug>

#include <cmath>
#include <iostream>

#include "util.hpp"

QRectF EdgeItem::boundingRect() const
{
    return QRectF(m_from.sceneBoundingRect().center(), m_to.sceneBoundingRect().center()).normalized().marginsAdded(QMarginsF(4, 4, 4, 4));
}

void EdgeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);

    QPen fillPen(Qt::black, thickness);

    if (isSelected())
    {
        fillPen.setBrush(QBrush(QColor(0xFE, 0xBA, 0x23)));
    }
    else
    {
        if (isUnderMouse())
        {
            fillPen.setBrush(QColor(0x2D8BBE).lighter());
        }
        else
        {
            fillPen.setBrush(QColor(0x2D8BBE));
        }
    }

    painter->setPen(fillPen);

    auto sourcePoint = m_from.sceneBoundingRect().center();

    auto destPoint = m_to.sceneBoundingRect().center();

    auto line = QLineF(sourcePoint, destPoint);

    double angle = std::acos(line.dx() / line.length());
    if (line.dy() >= 0)
    {
        angle = -angle;
    }

    {
        QPointF edge;
        auto hasEdge = rectEdge(m_from.sceneBoundingRect(), line, edge);
        if (hasEdge)
        {
            sourcePoint = edge;
            line = QLineF(sourcePoint, destPoint);
        }
    }
    {
        QPointF edge;
        auto hasEdge = rectEdge(m_to.sceneBoundingRect(), line, edge);
        if (hasEdge)
        {
            destPoint = edge;
            line = QLineF(sourcePoint, destPoint);
        }
    }

    auto offsetVec = line.normalVector().unitVector();
    line.translate(QPointF{offsetVec.dx(), offsetVec.dy()}*5);

    painter->drawLine(line);

    auto adjustedArrowSize = arrowSize;

    if (line.length() <= 25) // resize arrows if source and dest are close
    {
        adjustedArrowSize = arrowSize * line.length()/25;
    }

    QPointF destArrowP1 = line.p2() + QPointF(sin(angle - M_PI / 3) * adjustedArrowSize,
                                              cos(angle - M_PI / 3) * adjustedArrowSize);
    QPointF destArrowP2 = line.p2() + QPointF(sin(angle - M_PI + M_PI / 3) * adjustedArrowSize,
                                              cos(angle - M_PI + M_PI / 3) * adjustedArrowSize);

    auto polygon = QPolygonF() << line.p2() << destArrowP1 << destArrowP2;

    painter->drawPolygon(polygon);

    QVector2D vector(line.normalVector().unitVector().dx(), line.normalVector().unitVector().dy());
    vector *= 6;

    QPolygonF poly;
    poly << line.p1() + vector.toPointF() << line.p1() + (-vector).toPointF();
    poly << line.p2() + (-vector).toPointF() << line.p2() + vector.toPointF();

    m_shape = poly;
}
