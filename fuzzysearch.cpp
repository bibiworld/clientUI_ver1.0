#include "fuzzysearch.h"
#include <QDebug>

fuzzySearch::fuzzySearch(QWidget* p,MainWindow * m)
    : QDialog(p)
{
    parent = m;
    lineEdit = new QLineEdit(parent);
    lineEdit->show();
    lineEdit->setGeometry(60,45,100,25);
    
    label = new QLabel(parent);
    label->show();
    label->setGeometry(165,45,100,25);
    label->setText("单词最大长度");
    
    box = new QComboBox(parent);
    box->show();
    box->setGeometry(240,45,60,25);
    box->addItem("不确定");
    for(int i = 1;i < 12;i++)
    {
        box->addItem(QString::number(i));
    }
    
    button = new QPushButton(parent);
    button->show();
    button->setGeometry(310,45,28,25);
    button->setIcon(QIcon(":/images/search_black.png"));
    connect(button,SIGNAL(clicked(bool)),this,SLOT(searchWord()));
    
    textEdit = new QTextEdit(parent);
    textEdit->show();
    textEdit->setGeometry(60,80,280,210);
    connect(parent->socket,SIGNAL(readyRead()),this,SLOT(recvMessage()));
}

fuzzySearch::~fuzzySearch()
{
    if(lineEdit) delete lineEdit;
    if(textEdit) delete textEdit;
    if(button) delete button;
    if(box) delete box;
}

void fuzzySearch::searchWord()
{
    int index = box->currentIndex();
    QString tmpdata = "BIBI_fuzzy(";
    if(index > 0)
        tmpdata = "(" + QString::number(index) + ")";
    tmpdata += lineEdit->text();
    tmpdata += ")";
    qDebug() << "send:" << tmpdata;
    parent->socket->write(tmpdata.toStdString().c_str());
    parent->socket->flush();
}

void fuzzySearch::recvMessage()
{
    QString mess = parent->socket->readAll();
    mess = QString(mess);
    qDebug() << "recv:" << mess;
    QRegExp sep("[)(]");
    mess = mess.section(sep,1,1);
    QStringList result = mess.split(";");
    QString out = "模糊查询结果\n";
    for(QStringList::iterator it = result.begin();it != result.end();it++)
    {
        out += it->split(",")[0];
        out += it->split(",")[1];
        out += "\n";
    }
    textEdit->setText(out);
}
