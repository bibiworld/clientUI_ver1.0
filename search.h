#ifndef SEARCH
#define SEARCH
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDialog>
#include <QtNetwork/QTcpSocket>
#include "mainwindow.h"

class MainWindow;
class search : public QDialog
{
    Q_OBJECT
private:
    MainWindow* parent;
    QLineEdit* lineEdit;
    QTextEdit* textEdit;
    QPushButton* button;
    QPushButton* addButton;
    QString word;
    QString meaning;
public:
    search(QWidget* p,MainWindow* m);
    ~search();
private slots:
    void searchWord();
    void recvMessage();
    void addWord();
};

#endif // SEARCH

