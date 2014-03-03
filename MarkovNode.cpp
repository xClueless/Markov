#include "MarkovNode.hpp"
#include <QJsonArray>

MarkovNode::MarkovNode() {}
MarkovNode::MarkovNode(QString word) : mWord(word) {}

void MarkovNode::read(const QJsonObject& json)
{
    mWord = json["Word"].toString();

    QJsonArray linkArray = json["Links"].toArray();
    for (int linkIndex = 0; linkIndex < linkArray.size(); ++linkIndex) {
        QJsonObject linkObject = linkArray[linkIndex].toObject();
        MarkovLink link;
        link.read(linkObject);
        mLinks.append(link);
    }
}
void MarkovNode::write(QJsonObject& json) const
{
    json["Word"] = mWord;

    QJsonArray linkArray;
    foreach (const MarkovLink link, mLinks) {
        QJsonObject linkObject;
        link.write(linkObject);
        linkArray.append(linkObject);
    }
    json["Links"] = linkArray;
}

bool MarkovNode::operator==(const QString& nodeWord) const
{
    return mWord == nodeWord;
}
MarkovLink& MarkovNode::operator[](const QString& linkWord)
{
    return link(linkWord);
}
MarkovLink& MarkovNode::link(const QString& linkWord)
{
    for(MarkovLink& link : mLinks)
    {
        if(link == linkWord)
        {
            return link;
        }
    }
    mLinks.append(MarkovLink(linkWord));
    return mLinks.last();
}
