#ifndef MARKOVNODE_HPP
#define MARKOVNODE_HPP

#include <QJsonObject>
#include "MarkovLink.hpp"

class MarkovNode
{
private:
    QString mWord;
    QList<MarkovLink> mLinks;
public:
    MarkovNode();
    void read(const QJsonObject& json);
};

#endif // MARKOVNODE_HPP
