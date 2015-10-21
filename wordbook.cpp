#include "wordbook.h"

wordBook::wordBook(MainWindow *m, QWidget *p) : QObject(p)
{
    parent = m;
    container = new wordContainer();
    wordWidget = new QListWidget(parent);
    label = new QLabel(parent);
    readButton = new QPushButton(parent);
    myRecv = new Recv(parent->getSocket());
    connect(myRecv,SIGNAL(searchSignal(Word)),this,SLOT(recvMessage(Word)));
    connect(readButton,SIGNAL(clicked(bool)),this->container,SLOT(readin()));
    connect(this->container,SIGNAL(updateWordSignal()),this,SLOT(showWords()));
    connect(this->wordWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(searchWord(QModelIndex)));
}

wordBook::~wordBook()
{
    disconnect(myRecv,SIGNAL(searchSignal(Word)),this,SLOT(recvMessage(Word)));
    delete myRecv;
}

void wordBook::recvMessage(Word w)
{
    
}

void wordBook::showWords()
{
    for(vector<Word>::iterator it = container->wordList.begin();it != container->wordList.end();it++)
    {
        wordWidget->addItem(it->getWord());
    }
}

void wordBook::searchWord(QModelIndex)
{
    
}
