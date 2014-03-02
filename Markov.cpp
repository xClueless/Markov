#include "Markov.hpp"
#include <stdio.h>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include "MarkovNode.hpp"

Markov::Markov(QString dbPath) : dbFile(dbPath)
{
}
bool Markov::loadTree()
{
    bool success = false;

    success = dbFile.open(QIODevice::ReadWrite);

    if(success)
    {
        QJsonDocument db = QJsonDocument::fromJson(dbFile.readAll());
        dbFile.close();
        read(db.object());
    }
    return success;
}
void Markov::read(const QJsonObject& json)
{
    mHeader.read(json["Header"].toObject());

    QJsonArray nodeArray = json["Nodes"].toArray();
    for (int nodeIndex = 0; nodeIndex < nodeArray.size(); ++nodeIndex) {
        QJsonObject nodeObject = nodeArray[nodeIndex].toObject();
        MarkovNode node;
        node.read(nodeObject);
        mNodes.append(node);
    }
}
