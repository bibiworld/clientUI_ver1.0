#include "fuzzysearch.h"

fuzzySearch::fuzzySearch(QWidget* p,MainWindow * m)
    : QDialog(p)
{
    parent = m;
    lineEdit = new QLineEdit(parent);
    lineEdit->show();
    lineEdit->setGeometry(80,45,140,25);
    
    button = new QPushButton(parent);
    button->show();
    button->setGeometry(230,45,25,25);
    button->setIcon(QIcon(":/images/search_black.png"));
    connect(button,SIGNAL(clicked(bool)),this,SLOT(searchWord()));
    
    box = new QComboBox(parent);
    box->show();
    //box->setGeometry();
    box->addItem("不确定");
    for(int i = 1;i < 12;i++)
    {
        box->addItem(QString::number(i));
    }
    
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
}

void fuzzySearch::searchWord()
{
    int index = box->currentIndex();
    QString data;
    if(index > 0)
        data = "BIBI_fuzzy((" + QString::number(index) + ")";
    data += lineEdit->text();
    data += ")";
    parent->socket->write(data.toStdString().c_str());
    parent->socket->flush();
}

void fuzzySearch::recvMessage()
{
    QString mess = parent->socket->readAll();
    mess = QString(mess);
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
