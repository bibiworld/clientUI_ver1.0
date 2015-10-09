#include "fuzzysearch.h"
#include <QDebug>
#include <QMessageBox>

fuzzySearch::fuzzySearch(QWidget* p,MainWindow * m)
    : QDialog(p)
{
    parent = m;
    lineEdit = new QLineEdit(parent);
    lineEdit->show();
    lineEdit->setGeometry(100,60,260,40);
    
    label = new QLabel(parent);
    label->show();
    label->setGeometry(370,50,80,25);
    label->setText("单词最大长度");
    
    box = new QComboBox(parent);
    box->show();
    box->setGeometry(370,80,80,25);
    box->addItem("不确定");
    for(int i = 1;i < 12;i++)
    {
        box->addItem(QString::number(i));
    }
    
    button = new QPushButton(parent);
    button->show();
    button->setGeometry(460,60,40,40);
    button->setIcon(QIcon(":/images/search_black.png"));
    connect(button,SIGNAL(clicked(bool)),this,SLOT(searchWord()));
    
    textEdit = new QTextEdit(parent);
    textEdit->show();
    textEdit->setGeometry(100,110,400,280);
    connect(parent->socket,SIGNAL(readyRead()),this,SLOT(recvMessage()));
}

fuzzySearch::~fuzzySearch()
{
    if(lineEdit) delete lineEdit;
    if(textEdit) delete textEdit;
    if(label) delete label;
    if(button) delete button;
    if(box) delete box;
}

void fuzzySearch::searchWord()
{
    int index = box->currentIndex();
    if(lineEdit->text() == "")
    {
        QMessageBox::information(parent,"消息","没有要查询的单词",QMessageBox::Ok);
        return;
    }
    Send::B_fuzzysearch(parent->socket,lineEdit->text(),index);
}

void fuzzySearch::recvMessage()
{
    QString mess = parent->socket->readAll();
    mess = QString(mess);
    QString out = mess;
    qDebug() << "hehe";
    //qDebug() << "recv:" << mess;
    QRegExp sep("[)(]");
    mess = mess.section(sep,1,1);
    //qDebug() << mess;
    if(mess == "0")
    {
        textEdit->setText("对不起，没有满足您要求的单词");
        return;
    }
    QStringList result = mess.split(";");
    
    out = "模糊查询结果:\n";
    
    for(int i = 0;i < result.size()-1;i++)
    {
        out += result[i].split(",")[0];
        out += ":  ";
        out += result[i].split(",")[1];
        out += "\n";
        qDebug() << out;
    }
    
    textEdit->setText(out);
}
