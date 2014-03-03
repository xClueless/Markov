#ifndef MARKOVNODE_HPP
#define MARKOVNODE_HPP

#include "markov_global.hpp"
#include <QJsonObject>
#include <QList>
#include <QString>
#include "MarkovLink.hpp"

class MARKOVSHARED_EXPORT MarkovNode
{
private:
    QString mWord;
    QList<MarkovLink> mLinks;
public:
    MarkovNode();
    MarkovNode(QString word);
    void read(const QJsonObject& json);
    void write(QJsonObject& json) const;
    bool operator==(const QString& nodeWord) const;
    MarkovLink& operator[](const QString& linkWord);
    MarkovLink& link(const QString& linkWord);
};

#endif // MARKOVNODE_HPP
