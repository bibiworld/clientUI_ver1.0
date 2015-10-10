#include "recv.h"
#include <QDebug>

Recv::Recv(QTcpSocket *s, QObject *parent):
    QObject(parent),
    socket(s)
{
    connect(socket,SIGNAL(readyRead()),this,SLOT(recvMessage()));
    data = "";
    num = 0;
}

Recv::~Recv()
{
    
}

void Recv::recvMessage()
{
    QString tmp = socket->readAll();
    //if(tmp == "") return;
    qDebug() << "recv:" << tmp;
    if(tmp != "") data += tmp;
    num = data.count('(') - data.count(')');   
    if(num == 0)
    {
        if(tmp == "")
        {
            data = "";
            return;
        }
        QRegExp sep("[)(]");
        QString flag = data.section(sep,0,0);//取出标识字串
        if(flag == "BIBI_search")//normal search
            B_search(data);
        if(flag == "BIBI_fuzzy")//fuzzy search
            B_fuzzy(data);
        data = "";
    }
}

void Recv::B_search(QString mess)
{
    qDebug() << "B_search";
    QStringList ret;
    QRegExp sep("[)(]");
    QString word = mess.section(sep,2,2);
    if(word == "0")
    {
        emit searchSignal(ret);
        return;
    }
    ret.push_back(word);
    
    QString soundmark = mess.section(sep,4,4);
    soundmark = soundmark.replace("<*","(");
    soundmark = soundmark.replace("*>",")");
    ret.push_back(soundmark);
    
    QString meaning = mess.section(sep,6,6);  
    meaning = meaning.replace("<*","(");
    meaning = meaning.replace("*>",")");
    ret.push_back(meaning);
    
    QString example = mess.section(sep,8,8);
    example = example.replace('|'," ");
    example = example.replace("<*","(");
    example = example.replace("*>",")");
    ret.push_back(example);
    
    emit searchSignal(ret);
}

void Recv::B_fuzzy(QString mess)
{
    qDebug() << "B_fuzzy";
    QStringList ret;
    QRegExp sep("[)(]");
    mess = mess.section(sep,1,1);
    mess = mess.replace("<*","(");
    mess = mess.replace("*>",")");
    if(mess == "0")
    {
        qDebug() << "emit fuzzy";
        emit fuzzySignal(ret);
        return;
    }
    
    ret = mess.split(";");
    for(int i = 0;i < ret.size()-1;i++)
    {
        ret[i] = ret[i].replace(",",":");
    }
    qDebug() << "emit fuzzy";
    emit fuzzySignal(ret);
}
