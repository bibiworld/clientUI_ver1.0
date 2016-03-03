#include "sentence.h"
#include <QDebug>

Sentence::Sentence(MainWindow *p, QWidget *w):QWidget(w)
{
    parent = p;
    myRecv = new Recv(parent->getSocket());
    connect(myRecv,SIGNAL(sentenceSignal(QString,QString)),this,SLOT(showSentence(QString,QString)));
}

void Sentence::showSentence(QString eng, QString chi)
{
    qDebug() << "haoju:" << eng << chi;
    parent->sentencesLabel->setText(eng + "\n" + chi);
}
