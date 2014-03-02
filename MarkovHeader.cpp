#include "MarkovHeader.hpp"

MarkovHeader::MarkovHeader()
{
}

QString MarkovHeader::formatSignature() const
{
    return mFormatSignatature;
}

int MarkovHeader::words() const
{
    return mWords;
}

int MarkovHeader::contexts() const
{
    return mContexts;
}

void MarkovHeader::read(const QJsonObject& json)
{
    mFormatSignatature = json["FormatSignature"].toString();
    mWords = json["Words"].toInt();
    mWords = json["Contexts"].toInt();
}
