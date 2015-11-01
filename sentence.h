#ifndef SENTENCE_H
#define SENTENCE_H
#include <QWidget>
#include <QLabel>
#include <QString>
#include "mainwindow.h"
#include "recv.h"

class MainWindow;
class Sentence : public QWidget
{
    Q_OBJECT
    
    MainWindow* parent;
public:
    Sentence(MainWindow* p,QWidget* w = 0);
    Recv* myRecv;
private slots:
    void showSentence(QString,QString);
/*
signals:
    void sentenceSignal();
*/
};

#endif // SENTENCE_H

