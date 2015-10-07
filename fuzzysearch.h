#ifndef FUZZYSEARCH_H
#define FUZZYSEARCH_H

#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDialog>
#include <QtNetwork/QTcpSocket>
#include <QComboBox>
#include "mainwindow.h"

class MainWindow;
class fuzzySearch : public QDialog
{
    Q_OBJECT
private:
    MainWindow* parent;
    QLineEdit* lineEdit;
    QTextEdit* textEdit;
    QPushButton* button;
    QComboBox* box;
public:
    fuzzySearch(QWidget* p,MainWindow* m);
    ~fuzzySearch();
private slots:
    void searchWord();
    void recvMessage();
};

#endif // FUZZYSEARCH_H

