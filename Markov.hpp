#ifndef MARKOV_HPP
#define MARKOV_HPP

#include "markov_global.hpp"
#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QList>
#include "MarkovHeader.hpp"
#include "MarkovNode.hpp"

enum markov_db_err
{
    INVALID_HEADER = 1
};

class MARKOVSHARED_EXPORT Markov : public QObject
{
private:
    Q_OBJECT
    QFile dbFile;
    MarkovHeader mHeader;
    QList<MarkovNode> mNodes;

    bool loadTree();
public:
    Markov(QString dbPath);
public slots:
    void read(const QJsonObject& json);
};

#endif // MARKOV_HPP
