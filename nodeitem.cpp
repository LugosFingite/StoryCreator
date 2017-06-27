/*  nodeitem.cpp NodeItem - Yann BOUCHER (yann) 19/06/2017
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
#include "nodeitem.hpp"

#include <QFontMetricsF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

QRectF NodeItem::boundingRect() const
{
    return QFontMetricsF(QFont("Verdana", 10, QFont::Bold)).boundingRect(info.page).marginsAdded(QMarginsF(8, 8, 12, 8));
}

void NodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);

    QPen fillPen(Qt::transparent, 10);

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

    painter->setPen(QPen(Qt::black, 2));
    painter->setFont(QFont("Verdana", 10, QFont::Bold));

    QPainterPath path;
    path.addRoundedRect(boundingRect(), 6, 6);

    painter->fillPath(path, fillPen.brush());

    painter->drawText(QPointF{2, 0}, info.page);

    if (isSelected())
    {
        painter->setPen(QPen(Qt::cyan));
    }
    painter->drawPath(path);
}
