#ifndef MARKOV_HPP
#define MARKOV_HPP

#include "markov_global.hpp"
#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QList>
#include <QStringList>
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
    QFile mDBFile;
    MarkovHeader mHeader;
    QList<MarkovNode> mNodes;
public:
    explicit MarkovChain(QString dbPath, QObject* parent=0);
    virtual ~MarkovChain();

    MarkovHeader& header();

    MarkovNode& node(const QString& nodeStr);
    MarkovNode& operator[](const QString& nodeStr);
    const QList<MarkovNode> nodes() const;

public slots:
    void read(const QJsonObject& json);
    void write(QJsonObject& json) const;

    void initDB();
    void deleteDB();
    bool loadDB();
    bool writeDB();

    void clearNodes();

    void inputSentence(QString input);
    void inputSentence(QStringList words);
    bool inputLogFile(QString filePath);
};

#endif // MARKOV_HPP
