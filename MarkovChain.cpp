#include "MarkovChain.hpp"
#include "MarkovNode.hpp"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTextStream>

MarkovChain::MarkovChain(QString dbPath, QObject* parent) : QObject(parent), mDBFile(dbPath)
{
}
MarkovChain::~MarkovChain()
{
}
void MarkovChain::clearNodes()
{
    for(int i=0;i<mNodes.count();++i)
    {
        mNodes.removeAt(i);
    }
}
void MarkovChain::initDB()
{
    mHeader.setFormatSignature("xclueless.MarkovChain:1");
}
void MarkovChain::deleteDB()
{
    mDBFile.remove();
}


bool MarkovChain::loadDB()
{
    if(!mDBFile.open(QIODevice::ReadWrite))
    {
        qWarning("Couldn't open DB.");
        return false;
    }

    QJsonDocument db = QJsonDocument::fromJson(mDBFile.readAll());
    mDBFile.close();
    read(db.object());

    return true;
}
bool MarkovChain::writeDB()
{
    if (!mDBFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open DB.");
        return false;
    }

    QJsonObject chainObject;
    write(chainObject);
    QJsonDocument chainDoc(chainObject);
    mDBFile.write(chainDoc.toJson());
    mDBFile.close();

    return true;
}

void MarkovChain::read(const QJsonObject& json)
{
    mHeader.read(json["Header"].toObject());

    QJsonArray nodeArray = json["Nodes"].toArray();
    for (int nodeIndex = 0; nodeIndex < nodeArray.size(); ++nodeIndex) {
        QJsonObject nodeObject = nodeArray[nodeIndex].toObject();
        MarkovNode node;
        node.read(nodeObject);
        mNodes.append(node);
    }
}
void MarkovChain::write(QJsonObject& json) const
{
    QJsonObject headerObject;
    mHeader.write(headerObject);
    json["Header"] = headerObject;

    QJsonArray nodeArray;
    foreach (const MarkovNode node, mNodes) {
        QJsonObject nodeObject;
        node.write(nodeObject);
        nodeArray.append(nodeObject);
    }
    json["Nodes"] = nodeArray;
}
MarkovNode& MarkovChain::operator[](const QString& nodeStr)
{
    return node(nodeStr);
}
MarkovHeader& MarkovChain::header()
{
    return mHeader;
}
const QList<MarkovNode> MarkovChain::nodes() const
{
    return mNodes;
}
MarkovNode& MarkovChain::node(const QString& nodeStr)
{
    for(MarkovNode& node : mNodes)
    {
        if(node == nodeStr)
        {
            return node;
        }
    }
    mNodes.append(MarkovNode(nodeStr));
    mHeader.setWords(mHeader.words()+1);
    return mNodes.last();
}
void MarkovChain::inputSentence(QString input)
{
    inputSentence(input.split(' '));
}
void MarkovChain::inputSentence(QStringList words)
{
    QString& prevWord = words[0];

    for(int i=1;i<words.size();i++)
    {
        const QString& currentWord = words[i];
        ++node(currentWord).link(prevWord);
        prevWord = currentWord;
    }
}
bool MarkovChain::inputLogFile(QString filePath)
{
//    qDebug() << "[MarkovChain] inputLogFile()";

    QFile logFile(filePath);
    if (logFile.open(QIODevice::ReadOnly))
    {
//       qDebug() << "[MarkovChain] Reading file: " << filePath;

       QTextStream in(&logFile);
       while (!in.atEnd() )
       {
          QString line = in.readLine();
//          qDebug() << "ILF:" << line;
          inputSentence(line);
       }
       logFile.close();
       return true;
    }
    return false;
}
