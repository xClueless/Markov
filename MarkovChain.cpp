#include "MarkovChain.hpp"
#include "MarkovNode.hpp"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

MarkovChain::MarkovChain(QString dbPath, QObject* parent) : QObject(parent)
{

}
MarkovChain::~MarkovChain()
{

}

void MarkovChain::initDB()
{

    mHeader.setFormatSignature("xclueless.MarkovChain:1");
}

bool MarkovChain::loadDB()
{
    if(!dbFile.open(QIODevice::ReadWrite))
    {
        qWarning("Couldn't open DB.");
        return false;
    }

    QJsonDocument db = QJsonDocument::fromJson(dbFile.readAll());
    dbFile.close();
    read(db.object());

    return true;
}
bool MarkovChain::writeDB()
{
    if (!dbFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open DB.");
        return false;
    }

    QJsonObject chainObject;
    write(chainObject);
    QJsonDocument chainDoc(chainObject);
    dbFile.write(chainDoc.toJson());
    dbFile.close();

    return true;
}

void MarkovChain::read(const QJsonObject& json)
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
void MarkovChain::write(QJsonObject& json) const
{
    QJsonObject headerObject;
    mHeader.write(headerObject);
    json["Header"] = headerObject;

    QJsonArray nodeArray;
    foreach (const MarkovNode node, mNodes) {
        QJsonObject nodeObject;
        node.write(nodeObject);
        nodeArray.append(nodeObject);
    }
    json["Nodes"] = nodeArray;
}
MarkovNode& MarkovChain::operator[](const QString& nodeStr)
{
    return node(nodeStr);
}
MarkovNode& MarkovChain::node(const QString& nodeStr)
{
    for(MarkovNode& node : mNodes)
    {
        if(node == nodeStr)
        {
            return node;
        }
    }
    mNodes.append(MarkovNode(nodeStr));
    return mNodes.last();
}
