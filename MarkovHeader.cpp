#include "MarkovHeader.hpp"

MarkovHeader::MarkovHeader(){}
MarkovHeader::MarkovHeader(QString FormatSignature, int Words, int Contexts) : mFormatSignature(FormatSignature), mWords(Words), mContexts(Contexts) {}

QString MarkovHeader::formatSignature() const
{
    return mFormatSignature;
}
int MarkovHeader::words() const
{
    return mWords;
}
int MarkovHeader::contexts() const
{
    return mContexts;
}
void MarkovHeader::setFormatSignature(const QString& FormatSignature)
{
    this->formatSignature() = FormatSignature;
}

void MarkovHeader::read(const QJsonObject& json)
{
    mFormatSignature = json["FormatSignature"].toString();
    mWords = json["Words"].toInt();
    mWords = json["Contexts"].toInt();
}
void MarkovHeader::write(QJsonObject& json) const
{
    json["FormatSignature"] = mFormatSignature;
    json["Words"] = mWords;
    json["Contexts"] = mContexts;
}
