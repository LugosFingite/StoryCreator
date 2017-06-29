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

#include <QFile>
#include <QFileInfo>
#include <QDirIterator>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "jsonloading.hpp"

namespace jsonloading
{

void save(const Graph &graph, const QString &directory)
{
    QDir::setCurrent(directory);

    QDir dir(directory);

    for (const auto& pair : graph)
    {
        auto info = pair.second.info;

        QJsonObject json;
        json["page"] = info.page;
        json["image"] = info.image;
        json["son"] = info.son;
        json["desc"] = info.desc;
        json["color"] = info.color.name();
        json["loop_music"] = info.loopMusic;

        json["editor_pos_x"] = pair.second.pos.x();
        json["editor_pos_y"] = pair.second.pos.y();

        // copy images and sounds into game directory
        if (!info.image.isEmpty())
        {
            QFileInfo imageInfo(info.image);
            dir.mkdir("Graphismes");
            QFile::copy(info.image, "Graphismes/" + imageInfo.fileName());
            json["image"] = "Graphismes/" + imageInfo.fileName();
        }

        if (!info.son.isEmpty())
        {
            QFileInfo sonInfo(info.son);
            dir.mkdir("Musique");
            QFile::copy(info.son, "Musique/" + sonInfo.fileName());
            json["son"] = "Musique/" + sonInfo.fileName();
        }


        QJsonArray actions;
        for (const auto& actionpair : pair.second.actions)
        {
            QJsonObject action;
            action["cible"] = actionpair.first;
            action["desc"] = actionpair.second.desc;
            action["color"] = actionpair.second.color.name();

            actions.push_back(action);
        }

        json["actions"] = actions;

        QFile saveFile(info.page + ".json");

        if (!saveFile.open(QIODevice::WriteOnly))
        {
            throw_json_fs_error(QObject::tr("Impossible de sauvegarder le fichier '").toStdString() + saveFile.fileName().toStdString() + "' !");
        }

        QJsonDocument doc(json);

        saveFile.write(doc.toJson());
    }
}

Graph load(const QString &directory)
{
    Graph graph;

    QDirIterator it(directory, QStringList() << "*.json", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        Node node = detail::loadNode(it.next());

        graph[node.info.page] = node;
    }

    return graph;
}

namespace detail
{

Node loadNode(const QString &filename)
{
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly))
    {
        throw_json_fs_error(QObject::tr("Impossible de charger le fichier de page '").toStdString() + file.fileName().toStdString() + "' !");
    }

    Node node;

    try
    {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject json = doc.object();

        node.info.page = json["page"].toString();
        node.info.image = json["image"].toString("");
        node.info.son = json["son"].toString("");
        node.info.desc = json["desc"].toString("");
        node.info.color = json["color"].toString("white");
        node.info.loopMusic = json["loop_music"].toBool(false);
        node.pos.rx() = json["editor_pos_x"].toDouble(0);
        node.pos.ry() = json["editor_pos_y"].toDouble(0);

        QJsonArray actions = json["actions"].toArray();
        for (const auto& action : actions)
        {
            node.actions[action.toObject()["cible"].toString()] = {action.toObject()["desc"].toString(),
                                                                   QColor(action.toObject()["color"].toString())};
        }
    }
    catch (const QJsonParseError& err)
    {
        throw_json_parse_error(QObject::tr("Erreur lors du parsing du fichier '").toStdString() + file.fileName().toStdString()
                               + "' : " + err.errorString().toStdString());
    }

    return node;
}

}

}
