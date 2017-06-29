/*  edgeitem.hpp EdgeItem - Yann BOUCHER (yann) 20/06/2017
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
#ifndef EDGEITEM_HPP
#define EDGEITEM_HPP

#include <QGraphicsItem>

#include "nodeitem.hpp"
#include "util.hpp"

class EdgeItem : public QGraphicsItem
{
    public:
        EdgeItem(NodeItem& from, NodeItem& to)
            : m_from(from), m_to(to)
        {
            setFlag(QGraphicsItem::ItemIsSelectable);

            setAcceptHoverEvents(true);
        }

    public:
        QString from()
        {
            return m_from.info.page;
        }

        QString to()
        {
            return m_to.info.page;
        }

    protected:
        virtual QRectF boundingRect() const;

        QPainterPath shape() const
        {
            QPainterPath path;
            path.addPolygon(m_shape);
            return path;
        }

        virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget* widget = nullptr);

    public:
        size_t arrowSize = 10;
        double thickness = 4;

        EdgeInfo info;

    private:
        NodeItem& m_from;
        NodeItem& m_to;

        QPolygonF m_shape;
};

#endif // EDGEITEM_HPP
