#include "recv.h"

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
    num = num + tmp.count('(') - tmp.count(')');
    data += tmp;
    if(num == 0)
    {
        QRegExp sep("[)(]");
        QString flag = data.section(sep,0,0);//取出标识字串
        if(flag == "BIBI_search")//normal search
            B_search(data);
        if(flag == "BIBI_fuzzy")//fuzzy search
            B_fuzzysearch(data);
        data = "";
    }
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
    
    emit sendMessageSignal(ret);
}

void Recv::B_fuzzysearch(QString mess)
{
    QStringList ret;
    QRegExp sep("[)(]");
    mess = mess.section(sep,1,1);
    if(mess == "0")
    {
        emit sendMessageSignal(ret);
        return;
    }
    
    ret = mess.split(";");
    for(int i = 0;i < ret.size()-1;i++)
    {
        ret[i] = ret[i].replace(",",":");
    }
    
    emit sendMessageSignal(ret);
}
