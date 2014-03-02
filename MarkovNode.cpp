#include "MarkovNode.hpp"
#include <QJsonArray>

MarkovNode::MarkovNode()
{
}
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
