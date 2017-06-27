/*  graph %{Cpp:License:ClassName} - Yann BOUCHER (yann) 26/06/2017
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
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>

#include <QPointF>

#include "util.hpp"

struct Node
{
        NodeInfo info;
        QPointF pos;
        std::map<QString, QString> actions;
};

using Graph = std::map<QString, Node>;

#endif // GRAPH_HPP
