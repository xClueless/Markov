#ifndef MARKOVHEADER_HPP
#define MARKOVHEADER_HPP

#include "markov_global.hpp"
#include <QJsonObject>

class MARKOVSHARED_EXPORT MarkovHeader
{
private:
    QString mFormatSignature;
    int mWords = 0;
    int mContexts = 0;
public:
    MarkovHeader();
    QString formatSignature() const;
    MarkovHeader(QString FormatSignature, int Words=0, int Contexts=0);
    int words() const;
    int contexts() const;
    void setFormatSignature(const QString& FormatSignature);
    void setWords(int nWords);
    void setContexts(int nContexts);
    void read(const QJsonObject& json);
    void write(QJsonObject& json) const;
};

#endif // MARKOVHEADER_HPP
