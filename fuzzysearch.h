#ifndef FUZZYSEARCH_H
#define FUZZYSEARCH_H

#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDialog>
#include <QtNetwork/QTcpSocket>
#include <QComboBox>
#include <QLabel>
#include <QVector>
#include "mainwindow.h"
#include "word.h"
#include "myqlineedit.h"

class MainWindow;
class fuzzySearch : public QDialog
{
    Q_OBJECT
private:
    MainWindow* parent;
    myQLineEdit* lineEdit;
    QTextEdit* textEdit;
    QPushButton* button;
    QLabel* label;
    QComboBox* box;
    Recv* myRecv;
public:
    fuzzySearch(QWidget* p,MainWindow* m);
    ~fuzzySearch();
private slots:
    void searchWord();
    void recvMessage(QVector<Word>);
    void editingFinishedSlot();
};

#endif // FUZZYSEARCH_H

