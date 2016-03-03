#include "similarword.h"
#include <QDebug>

SimilarWord::SimilarWord(MainWindow* m)
{
    parent = m;
    this->myRecv = new Recv(parent->getSocket());
    connect(this->myRecv,SIGNAL(similarSignal(QString,QVector<Word>)),this,SLOT(recvMessage(QString,QVector<Word>)));

    lineEdit = new myQLineEdit(parent);
    lineEdit->show();
    lineEdit->setGeometry(100,60,270,40);

    connect(lineEdit,SIGNAL(pressEnterSignal()),this,SLOT(searchWord()));

    button = new QPushButton(parent);
    button->show();
    button->setGeometry(380,60,120,40);
    button->setText("查询亲戚单词");
    connect(button,SIGNAL(clicked(bool)),this,SLOT(searchWord()));


    textEdit = new QTextEdit(parent);
    textEdit->show();
    textEdit->setGeometry(100,110,400,280);
}

SimilarWord::~SimilarWord()
{

}

void SimilarWord::searchWord()
{
    QString word = lineEdit->text();
    if(word == "")
    {
        QMessageBox::information(this,"消息","没有要查询的单词",QMessageBox::Ok);
        return;
    }
    QTcpSocket* s = parent->getSocket();
    qDebug() << "LIHAOYANG  SEND";
    Send::B_similar(s,word);
}

void SimilarWord::recvMessage(QString word,QVector<Word> myvc)
{
    //qDebug() << word << "  !!!@@@###" << myvc[0].getWord() ;
    QString data = "";
    data += "您所输入的单词 " + word + " 的亲戚单词有:\n";
    for(int i = 0;i < myvc.size();i++){
        data += QString::number(i+1) + ". " + myvc[i].getWord() + "\n";
    }
    textEdit->setText(data);
}

