#ifndef WORDCONTAINER
#define WORDCONTAINER
#include <QVector>
#include <QObject>
#include <QFile>
#include "word.h"
#include "send.h"
#include "recv.h"

class wordContainer : public QObject
{
    Q_OBJECT
public:
    wordContainer(QString _fileName = "wordList.txt",QObject* parent = 0);
    void addWord(Word _word);
private:
    QString fileName;
    QVector<Word> wordList;
    Recv* myRecv;
private slots:
    //void recvMessage(QStringList);
};

#endif // WORDCONTAINER

