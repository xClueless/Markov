#include <QCoreApplication>
#include <qmarkov/MarkovChain.hpp>
#include <QStringList>
#include <QDebug>

QString generateRandomSentence(MarkovChain& chain, QString startWord, int maxWords)
{
    QStringList sentence;
    MarkovNode currentNode = chain.node(startWord);

    for(int i=0;i<maxWords;++i)
    {
        QList<MarkovLink> links = currentNode.links();
        if(links.isEmpty())
        {
            break;
        }

        const MarkovLink& chosenLink = links.at(qrand() % currentNode.totalLinkOccurances());
        currentNode = chain.node(chosenLink.word());
        sentence.prepend(currentNode.word());
    }
    return sentence.join(' ') + ".";
}

QString generateRandomSentence(MarkovChain& chain, int maxWords)
{
    int startWord = qrand() % chain.header().words();
    qDebug() << qrand();
    qDebug() << chain.header().words();
    qDebug() << "Start Index: " << startWord;

    return generateRandomSentence(chain, chain.nodes().at(startWord).word(), maxWords);
}

void write(MarkovChain& chain)
{
    qDebug() << "write()";
    chain.deleteDB();
    chain.initDB();

//    chain.inputLogFile("Logs/Nikki.log");
//    chain.inputLogFile("Logs/Ben.log");
    chain.inputLogFile("Logs/Dan.log");
    chain.writeDB();
}
void read(MarkovChain& chain)
{
    chain.loadDB();

    for(const MarkovNode& node : chain.nodes())
    {
        qDebug() << "N: " << node.word();

        for(const MarkovLink& link : node.links())
        {
            qDebug() << "----> " << link.word() << ":" << link.occurances();
        }
    }
}

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);

    qsrand(time(0));

    MarkovChain writeChain("markovDB.json");
    write(writeChain);

    MarkovChain readChain("markovDB.json");
    readChain.loadDB();

    for(int i=0;i<100;i++)
    {
        qDebug() << generateRandomSentence(writeChain, 8);
    }

//    return a.exec();
}
