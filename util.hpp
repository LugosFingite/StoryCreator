/*  util %{Cpp:License:ClassName} - Yann BOUCHER (yann) 20/06/2017
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
#ifndef UTIL_HPP
#define UTIL_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

#include <QRectF>
#include <QLineF>
#include <QString>

#include <cmath>

#define DECLARE_EXCEPTION(name, prettyname)\
    class name##_error : public std::runtime_error \
{ \
    using std::runtime_error::runtime_error; \
    }; \
    \
    [[noreturn]] inline void throw_##name##_error(const std::string& t_why) \
{ \
    throw name##_error(#prettyname + t_why); \
    }


inline bool rectEdge(const QRectF& rect, const QLineF& line, QPointF& intersectionRef)
{
    for (auto side : {QLineF{rect.topLeft(), rect.topRight()}, {rect.topRight(), rect.bottomRight()},
    {rect.bottomRight(), rect.bottomLeft()}, {rect.bottomLeft(), rect.topLeft()}})
    {
        QPointF intersection;
        if (line.intersect(side, &intersection) == QLineF::BoundedIntersection)
        {
            intersectionRef = intersection;

            return true;
        }
    }

    return false;
}

struct NodeInfo
{
    QString page;
    QString image;
    QString son;
    QString desc;
};

#endif // UTIL_HPP
