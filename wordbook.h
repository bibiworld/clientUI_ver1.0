#ifndef WORDBOOK_H
#define WORDBOOK_H
#include "mainwindow.h"
#include "wordcontainer.h"
#include "send.h"
#include "recv.h"
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>

class wordBook : public QObject
{
    Q_OBJECT
public:
    wordBook(MainWindow* m,QWidget* p);
    ~wordBook();
private:
    MainWindow* parent;
    QListWidget* wordWidget;
    wordContainer* container;
    Recv* myRecv;
    QLabel* label;
    QPushButton* readButton;
    QPushButton* deleteButton;
private slots:
    void recvMessage(Word data);
    void showWords();
    void deleteWord();
    void searchWord(QModelIndex);
};

#endif // WORDBOOK_H

