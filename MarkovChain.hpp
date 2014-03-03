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

class MARKOVSHARED_EXPORT MarkovChain : public QObject
{
private:
    Q_OBJECT
    QString mDBPath;
    QFile dbFile;
    MarkovHeader mHeader;
    QList<MarkovNode> mNodes;
public:
    explicit MarkovChain(QString dbPath, QObject* parent=0);
    virtual ~MarkovChain();
    MarkovNode& operator[](const QString& nodeStr);
    MarkovNode& node(const QString& nodeStr);
public slots:
    void read(const QJsonObject& json);
    void write(QJsonObject& json) const;
    void initDB();
    bool loadDB();
    bool writeDB();
};

#endif // MARKOV_HPP
