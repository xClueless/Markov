#ifndef MARKOVHEADER_HPP
#define MARKOVHEADER_HPP

#include "markov_global.hpp"
#include <QJsonObject>

class MARKOVSHARED_EXPORT MarkovHeader
{
private:
    QString mFormatSignature;
    int mWords;
    int mContexts;
public:
    MarkovHeader();
    QString formatSignature() const;
    MarkovHeader(QString FormatSignature, int Words=0, int Contexts=0);
    int words() const;
    int contexts() const;
    void setFormatSignature(const QString& FormatSignature);
    void read(const QJsonObject& json);
    void write(QJsonObject& json) const;
};

#endif // MARKOVHEADER_HPP
