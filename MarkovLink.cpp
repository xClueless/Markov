#include "MarkovLink.hpp"

MarkovLink::MarkovLink()
{
}

QString MarkovLink::word()
{
    return mWord;
}
int MarkovLink::occurances()
{
    return mOccurances;
}

void MarkovLink::read(const QJsonObject& json)
{
    mWord = json["Word"].toString();
    mOccurances = json["Occurances"].toInt();
}
