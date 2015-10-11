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
        if(flag == "BIBI_similar")
            B_similar(data);
        data = "";
    }
}

void Recv::B_search(QString mess)
{
    qDebug() << "B_search";
    QRegExp sep("[)(]");
    QString word = mess.section(sep,2,2);
    if(word == "0")
    {
        emit searchSignal(Word());
        return;
    }
    //ret.push_back(word);
    
    QString soundmark = mess.section(sep,4,4);
    soundmark = soundmark.replace("<*","(");
    soundmark = soundmark.replace("*>",")");
    //ret.push_back(soundmark);
    
    QString meaning = mess.section(sep,6,6);  
    meaning = meaning.replace("<*","(");
    meaning = meaning.replace("*>",")");
    //ret.push_back(meaning);
    
    QString example = mess.section(sep,8,8);
    example = example.replace('|'," ");
    example = example.replace("<*","(");
    example = example.replace("*>",")");
    //ret.push_back(example);
    
    emit searchSignal(Word(word,soundmark,meaning,example));
}

void Recv::B_fuzzy(QString mess)
{
    qDebug() << "B_fuzzy";
    QVector<Word> ret;
    QStringList data;
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
    
    data = mess.split(";");
    for(int i = 0;i < data.size()-1;i++)
    {
        //data[i] = data[i].replace(",",":");
        ret.push_back(Word(data[i].split(",")[0],"",data[i].split(",")[1],""));
    }
    qDebug() << "emit fuzzy";
    emit fuzzySignal(ret);
}

void Recv::B_similar(QString mess)
{
    qDebug() << "B_similar";
    QVector<Word> ret;
    QRegExp sep("[)(]");
    mess = mess.section(sep,1,1);
    if(mess == "0")
    {
        qDebug() << "emit similar";
        emit similarSignal("",ret);
        return;
    }
    QString tmpword = mess.split(":")[0];
    mess = mess.split(":")[1];
    QStringList tmp = mess.split(",");
    for(int i = 0;i < tmp.size()-1;i++)
    {
        ret.push_back(Word(tmp[i],"","",""));
    }
    qDebug() << "emit similar";
    emit similarSignal(tmpword,ret);
}
