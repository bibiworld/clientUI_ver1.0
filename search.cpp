#include "search.h"
#include <QTextCodec>
#include <QLineEdit>
#include <QDebug>
#include <QStringList>
#include <QMessageBox>
search::search(QWidget* p,MainWindow * m)
    : QDialog(p)
{
    parent = m;
    lineEdit = new QLineEdit(parent);
    lineEdit->show();
    lineEdit->setGeometry(80,45,140,25);
    
    button = new QPushButton(parent);
    button->show();
    button->setGeometry(240,45,25,25);
    button->setIcon(QIcon(":/images/search_black.png"));
    connect(button,SIGNAL(clicked(bool)),this,SLOT(searchWord()));
    
    addButton = new QPushButton(parent);
    addButton->show();
    addButton->setGeometry(280,45,40,25);
    addButton->setText("添加");
    connect(addButton,SIGNAL(clicked(bool)),this,SLOT(addWord()));
    
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
    if(addButton) delete addButton;
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
    //qDebug() << "ret" << mess;
    //mess = "BIBI_search((push)(p\u028A\u0283; p\u028A\u0283)(n.\u63A8,\u594B\u529B,\u51B3\u5FC3v.\u63A8,\u6324,\u903C\u8FEB)([He|pushed|her|into|making|a|decision.][\u4ED6\u50AC\u4FC3\u5979\u505A\u51FA\u51B3\u5B9A\u3002][You|may|stop|the|machine|by|pushing|this|button.][\u4F60\u6309\u4E0B\u8FD9\u4E2A\u6309\u94AE\u5C31\u53EF\u4EE5\u5173\u673A\u3002]))";
    mess = QString(mess);
    QRegExp sep("[)(]");
    QString word = mess.section(sep,2,2);
    QString soundmark = mess.section(sep,4,4);
    QStringList soundmarkList = soundmark.split("; ");
    QString meaning = mess.section(sep,6,6);    
    QString example = mess.section(sep,8,8);
    example = example.replace(']',"").replace('|'," ");
    QStringList exampleList = example.split("[");
    qDebug() << mess.section(sep,8,8);// << "\n" << mess.section(sep,1,1) << "\n" << meaning << "\n" << example;
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
        for(int i = 0;i < soundmarkList.size();i++)
        {
            out += "/";
            out += soundmarkList[i];
            out += "/";
            if(i < soundmarkList.size() - 1)
                out += " or ";
        }
        out += "\n释义：";
        out += meaning;
        out += "\n例句：";
        for(int i = 0;i < exampleList.size();i++)
        {
             out += exampleList[i];
             out += "\n";
        }
        this->word = word;
        this->meaning = meaning;
    }
    textEdit->setText(out);
}

void search::addWord()
{
    if(this->word == "")
    {
        QMessageBox::information(this,"消息","没有要添加的单词",QMessageBox::Ok);
        return;
    }
    parent->eng.push_back(this->word);
    parent->chi.push_back(this->meaning);
    this->word = "";
    this->meaning = "";
    QMessageBox::information(this,"消息","添加成功",QMessageBox::Ok);
}
