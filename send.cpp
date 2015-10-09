#include "send.h"
#include <QDebug>

void Send::B_search(QTcpSocket* socket,QString word)
{
    QString mess = "BIBI_search(" + word + ")";
    qDebug() << mess;
    socket->write(mess.toStdString().c_str());
    socket->flush();
}

void Send::B_fuzzysearch(QTcpSocket *socket,QString word,int len)
{
    QString mess = "BIBI_fuzzy(";
    if(len > 0)
    {
        mess += "(";
        mess += QString::number(len);
        mess += ")";
    }
    mess += word;
    qDebug() << mess;
    socket->write(mess.toStdString().c_str());
    socket->flush();
}

void Send::B_quit(QTcpSocket *socket)
{
    qDebug() << "BIBI_quit";
    socket->write("BIBI_quit");
    socket->flush();
}
