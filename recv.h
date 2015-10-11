#ifndef RECV_H
#define RECV_H
#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QStringList>
#include <QVector>
#include "word.h"
#include "wordcontainer.h"

class Recv : public QObject
{
    Q_OBJECT
    
private:
    QTcpSocket* socket;
    QString data;
    int num;
    
    //process different protocol
    void B_search(QString);
    void B_fuzzy(QString);
    void B_similar(QString);
public:
    Recv(QTcpSocket* s,QObject* parent = 0);
    ~Recv();
private slots:
    void recvMessage();    
signals:
    void searchSignal(Word);
    void fuzzySignal(QVector<Word>);
    void similarSignal(QString,QVector<Word>);
};

#endif // RECV_H

