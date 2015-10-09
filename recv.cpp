#include "recv.h"

Recv::Recv(QTcpSocket *s, QObject *parent):
    QObject(parent),
    socket(s)
{
    connect(socket,SIGNAL(readyRead()),this,SLOT(recvMessage()));
    data = "";
}

Recv::~Recv()
{
    
}

void Recv::recvMessage()
{
    
}

void Recv::B_search(QString mess)
{
    QStringList ret;
    QRegExp sep("[)(]");
    QString word = mess.section(sep,2,2);
    if(word == "0")
    {
        emit sendMessageSignal(ret);
        return;
    }
    ret.push_back(word);
    QString soundmark = mess.section(sep,4,4);
    ret.push_back(soundmark);
    //QStringList soundmarkList = soundmark.split("; ");
    QString meaning = mess.section(sep,6,6);  
    ret.push_back(meaning);
    QString example = mess.section(sep,8,8);
    example = example.replace(']',"").replace('|'," ");
    ret.push_back(example);
    //QStringList exampleList = example.split("[");
    emit sendMessageSignal(ret);
}

void Recv::B_fuzzysearch(QString mess)
{
    
}
