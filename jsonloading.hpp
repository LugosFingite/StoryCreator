/*  jsonloading %{Cpp:License:ClassName} - Yann BOUCHER (yann) 26/06/2017
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
#ifndef JSONLOADING_HPP
#define JSONLOADING_HPP

#include "graph.hpp"

#include "util.hpp"

namespace jsonloading
{

DECLARE_EXCEPTION(json_parse, "Erreur de parsing json");
DECLARE_EXCEPTION(json_fs, "Erreur de fichier json");

void save(const Graph& graph, const QString& directory);

Graph load(const QString& directory);

namespace detail
{
    Node loadNode(const QString& filename);
}

}

#endif // JSONLOADING_HPP
