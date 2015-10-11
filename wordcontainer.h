#ifndef WORDCONTAINER
#define WORDCONTAINER
#include <QVector>
#include <QObject>
#include <QFile>
#include <QVector>
#include "word.h"
#include "send.h"
#include "recv.h"

class wordContainer : public QObject
{
    Q_OBJECT
public:
    enum{HAVE_READ,NOT_READ};
    wordContainer(QObject* parent = 0);
    void readin(QString _fileName = "wordList.txt");
    int checkRead();
    QVector<Word> getWords();
    void addWord(Word _word);
    void deleteWord(int index);
private:
    int readFlag;
    QVector<Word> wordList;
    Recv* myRecv;
private slots:
    void recvMessage(QVector<Word>);
};

#endif // WORDCONTAINER

