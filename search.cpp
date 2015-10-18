#include "search.h"
#include <QTextCodec>
#include <QLineEdit>
#include <QDebug>
#include <QStringList>
#include <QMessageBox>
#include <QPalette>
#include "word.h"

search::search(QWidget* p,MainWindow * m)
    : QDialog(p)
{
    parent = m;
    myRecv = new Recv(parent->socket);
    connect(myRecv,SIGNAL(searchSignal(Word)),this,SLOT(recvMessage(Word)));
    
    lineEdit = new myQLineEdit(parent);
    lineEdit->show();
    lineEdit->setGeometry(100,60,270,40);
    //lineEdit->setInputMask("AAAAAAAAAAAAAAAA");
    editingFinishedSlot();
    connect(lineEdit,SIGNAL(editingFinished()),this,SLOT(editingFinishedSlot()));
    //connect(lineEdit,SIGNAL(textChanged(QString)),this,SLOT(textEditedSlot()));
    //connect(lineEdit,SIGNAL(textEdited(QString)),this,SLOT(textEditedSlot()));
    
    button = new QPushButton(parent);
    button->show();
    button->setGeometry(380,60,40,40);
    button->setIcon(QIcon(":/images/search_black.png"));
    connect(button,SIGNAL(clicked(bool)),this,SLOT(searchWord()));
    
    addButton = new QPushButton(parent);
    addButton->show();
    addButton->setGeometry(440,60,60,40);
    addButton->setText("收藏单词");
    connect(addButton,SIGNAL(clicked(bool)),this,SLOT(addWord()));
    
    textEdit = new QTextEdit(parent);
    textEdit->show();
    textEdit->setGeometry(100,110,400,280);
}

search::~search()
{
    if(lineEdit) delete lineEdit;
    if(textEdit) delete textEdit;
    if(button) delete button;
    if(addButton) delete addButton;
    disconnect(myRecv,SIGNAL(searchSignal(Word)),this,SLOT(recvMessage(Word)));
    delete myRecv;
}

void search::searchWord()
{
    QString word = lineEdit->text();
    if(word == "")
    {
        QMessageBox::information(this,"消息","没有要查询的单词",QMessageBox::Ok);
        return;
    }
    QTcpSocket* s = parent->getSocket();
    Send::B_search(s,word);
}

void search::recvMessage(Word data)
{
    QString out;
    qDebug() << "searchRecv";
    if(data.getWord() == "0")
    {
        out = "对不起，词库里无您要查找的单词";
    }
    else
    {
        QStringList tmp;
        out += data.getWord();
        out += "\n读音：";
        tmp = data.getSoundmark().split("; ");
        for(int i = 0;i < tmp.size();i++)
        {
            out += "/";
            out += tmp[i];
            out += "/";
            if(i < tmp.size() - 1) out += " or ";
        }
        out += "\n释义：";
        out += data.getMeaning();
        out += "\n例句：";
        tmp = data.getExample().replace("[","").split("]");
        for(int i = 0;i < tmp.size();i++)
        {
            out += "\n";
            out += tmp[i];
        }
        out += "\n";
    }
    textEdit->setText(out);
}

void search::addWord()
{
    if(this->word != lineEdit->text() || this->word == "" || this->meaning == "")
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

void search::editingFinishedSlot()
{
    if(this->lineEdit->text() == "")
    {
        QPalette pal =lineEdit->palette();
        pal.setColor(QPalette::Text,QColor(211,211,211));
        lineEdit->setPalette(pal);
        lineEdit->setText("请输入要查询的单词");
    }
    else
    {
        searchWord();
    }
}
