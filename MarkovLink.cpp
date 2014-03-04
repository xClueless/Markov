#include "MarkovLink.hpp"

MarkovLink::MarkovLink(){}
MarkovLink::MarkovLink(QString word, int wordOccurances) : mWord(word), mOccurances(wordOccurances){}

QString MarkovLink::word() const
{
    return mWord;
}
int MarkovLink::occurances() const
{
    return mOccurances;
}
void MarkovLink::read(const QJsonObject& json)
{
    mWord = json["Word"].toString();
    mOccurances = json["Occurances"].toInt();
}
void MarkovLink::write(QJsonObject& json) const
{
    json["Word"] = mWord;
    json["Occurances"] = mOccurances;
}
MarkovLink& MarkovLink::operator++()
{
    mOccurances++;
    return *this;
}
bool MarkovLink::operator==(const QString& str) const
{
    return mWord == str;
}
