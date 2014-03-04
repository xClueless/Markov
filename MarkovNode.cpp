#include "MarkovNode.hpp"
#include <QJsonArray>

MarkovNode::MarkovNode(){}
MarkovNode::MarkovNode(QString word) : mWord(word) {}

void MarkovNode::read(const QJsonObject& json)
{
    mWord = json["Word"].toString();
    mLinkTotalOccurances = json["LinkTotalOccurances"].toInt();

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
    json["LinkTotalOccurances"] = mLinkTotalOccurances;

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
QString MarkovNode::word() const
{
    return mWord;
}
int MarkovNode::totalLinkOccurances() const
{
    return mLinkTotalOccurances;
}

const QList<MarkovLink> MarkovNode::links() const //Should discourage the use of this;
{
    return mLinks;
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
    ++mLinkTotalOccurances;
    mLinks.append(MarkovLink(linkWord));
    return mLinks.last();
}
