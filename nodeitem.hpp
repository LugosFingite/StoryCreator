/*  nodeitem.hpp NodeItem - Yann BOUCHER (yann) 19/06/2017
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
#ifndef NODEITEM_HPP
#define NODEITEM_HPP

#include <QGraphicsItem>

#include "util.hpp"

class NodeItem : public QGraphicsItem
{
    public:
        NodeItem(QGraphicsItem *parent = nullptr) : QGraphicsItem(parent)
        {
            setFlag(QGraphicsItem::ItemIsMovable);
            setFlag(QGraphicsItem::ItemIsSelectable);

            setAcceptHoverEvents(true);
        }

    public:
        void updateInfo()
        {
            update();
        }

    protected:
        virtual QRectF boundingRect() const;

        virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget* widget = nullptr);

    public:
        NodeInfo info;

    private:

};

#endif // NODEITEM_HPP
