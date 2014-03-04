#ifndef MARKOVLINK_HPP
#define MARKOVLINK_HPP

#include "markov_global.hpp"
#include <QJsonObject>

class MARKOVSHARED_EXPORT MarkovLink
{
private:
    QString mWord;
    int mOccurances = 0;
public:
    MarkovLink();
    MarkovLink(QString word, int wordOccurances=0);
    QString word() const;
    int occurances() const;
    void read(const QJsonObject& json);
    void write(QJsonObject& json) const;
    MarkovLink& operator++();
    bool operator==(const QString& str) const;
};

#endif // MARKOVLINK_HPP
