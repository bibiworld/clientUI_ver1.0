#include "wordbook.h"

wordBook::wordBook(MainWindow *m, QWidget *p) : QObject(p)
{
    parent = m;
    container = new wordContainer();
    wordWidget = new QListWidget(parent);
    label = new QLabel(parent);
    //readButton = new QPushButton(parent);
    deleteButton = new QPushButton(parent);
    myRecv = new Recv(parent->getSocket());
    connect(myRecv,SIGNAL(searchSignal(Word)),this,SLOT(recvMessage(Word)));
    //connect(readButton,SIGNAL(clicked(bool)),this->container,SLOT(readin()));
    connect(deleteButton,SIGNAL(clicked(bool)),this,SLOT(deleteWord()));
    connect(this->container,SIGNAL(updateWordSignal()),this,SLOT(showWords()));
    connect(this->wordWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(searchWord(QModelIndex)));
    container->readin();
}

wordBook::~wordBook()
{
    disconnect(myRecv,SIGNAL(searchSignal(Word)),this,SLOT(recvMessage(Word)));
    delete myRecv;
}

void wordBook::recvMessage(Word data)
{
    QString out;
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
    label->setText(out);
}

void wordBook::showWords()
{
    for(QVector<Word>::iterator it = container->getWords().begin();it != container->getWords().end();it++)
    {
        wordWidget->addItem(it->getWord()+":"+it->getMeaning());
    }
}

void wordBook::deleteWord()
{
    int row = wordWidget->currentRow();
    container->getWords().remove(row-1);
}

void wordBook::searchWord(QModelIndex index)
{
    int row = index.row();
    Send::B_search(parent->getSocket(),container->getWords().at(row-1).getWord());
}
