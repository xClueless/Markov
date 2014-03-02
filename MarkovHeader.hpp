#ifndef MARKOVHEADER_HPP
#define MARKOVHEADER_HPP

#include <QJsonObject>

class MarkovHeader
{
private:
    QString mFormatSignatature;
    int mWords;
    int mContexts;
public:
    MarkovHeader();
    QString formatSignature() const;
    int words() const;
    int contexts() const;
    void read(const QJsonObject& json);
};

#endif // MARKOVHEADER_HPP
