#ifndef RECV_H
#define RECV_H
#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QStringList>

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
    void searchSignal(QStringList);
    void fuzzySignal(QStringList);
    void similarSignal(QString,QStringList);
};

#endif // RECV_H

