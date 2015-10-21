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
    int checkRead();
    QVector<Word> getWords();
    void addWord(Word _word);
    void deleteWord(int index);
public slots:
    void readin(QString _fileName);
    void readin();
private:
    int readFlag;
    QVector<Word> wordList;
    Recv* myRecv;
private slots:
    void recvMessage(QVector<Word>);
signals:
    void updateWordSignal();
};

#endif // WORDCONTAINER

