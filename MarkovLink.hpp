#ifndef MARKOVLINK_HPP
#define MARKOVLINK_HPP

#include <QObject>
#include <QJsonObject>

class MarkovLink
{
private:
    QString mWord;
    int mOccurances;
public:
    MarkovLink();
    QString word();
    int occurances();
    void read(const QJsonObject& json);
};

#endif // MARKOVLINK_HPP
