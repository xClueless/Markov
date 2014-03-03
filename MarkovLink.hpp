#ifndef MARKOVLINK_HPP
#define MARKOVLINK_HPP

#include "markov_global.hpp"
#include <QJsonObject>

class MARKOVSHARED_EXPORT MarkovLink
{
private:
    QString mWord;
    int mOccurances;
public:
    MarkovLink();
    MarkovLink(QString word, int wordOccurances=0);
    QString word();
    int occurances();
    void read(const QJsonObject& json);
    void write(QJsonObject& json) const;
    MarkovLink& operator++();
    bool operator==(const QString& str);
};

#endif // MARKOVLINK_HPP
