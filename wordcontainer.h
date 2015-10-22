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
    QVector<Word> & getWords();
    static void addWord(QWidget *parent, Word _word);//直接在文件末尾加上一个单词
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

