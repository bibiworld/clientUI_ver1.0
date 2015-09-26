#include "search.h"
#include <QLineEdit>
#include <QDebug>
search::search(QWidget* p,MainWindow * m)
    : QDialog(p)
{
    parent = m;
    lineEdit = new QLineEdit(parent);
    lineEdit->show();
    lineEdit->setGeometry(100,45,160,25);
    
    button = new QPushButton(parent);
    button->show();
    button->setGeometry(275,45,25,25);
    button->setIcon(QIcon(":/images/search_black.png"));
    connect(button,SIGNAL(clicked(bool)),this,SLOT(searchWord()));
    textEdit = new QTextEdit(parent);
    textEdit->show();
    textEdit->setGeometry(80,80,240,210);
    connect(parent->socket,SIGNAL(readyRead()),this,SLOT(recvMessage()));
}

search::~search()
{
    if(lineEdit) delete lineEdit;
    if(textEdit) delete textEdit;
    if(button) delete button;
}

void search::searchWord()
{
    QString word = lineEdit->text();
    QTcpSocket* s = parent->getSocket();
    QString mess = "BIBI_search(";
    mess += word;
    mess += ")";
    qDebug() << "send" << mess;
    s->write(mess.toStdString().c_str());
    s->flush();
}

void search::recvMessage()
{
    QString mess = parent->socket->readAll();
    qDebug() << "ret" << mess;
    QRegExp sep("[)(]");
    QString word = mess.section(sep,2,2);
    QString soundmark = mess.section(sep,4,4);
    QString meaning = mess.section(sep,6,6);    
    QString example = mess.section(sep,8,8);
    qDebug() << word << "\n" << soundmark << "\n" << meaning << "\n" << example;
    QString out;
    if(word == "0")
    {
        out += "词库里无您要查找的单词";
    }
    else
    {
        if(word != lineEdit->text())
        {
            out += "词库里无您要查找的单词，为您查找以下相近单词\n";
        }
        out += word;
        out += "\n读音：";
        out += soundmark;
        out += "\n释义：";
        out += meaning;
        out += "\n例句：";
        out += example;
    }
    textEdit->setText(out);
}
