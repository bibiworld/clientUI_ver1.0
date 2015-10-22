#ifndef SEARCH
#define SEARCH
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDialog>
#include <QtNetwork/QTcpSocket>
#include <QPushButton>
#include "mainwindow.h"
#include "word.h"
#include "myqlineedit.h"

class MainWindow;
class search : public QDialog
{
    Q_OBJECT
private:
    MainWindow* parent;
    myQLineEdit* lineEdit;
    QTextEdit* textEdit;
    QPushButton* button;
    QPushButton* addButton;
    QPushButton* bookButton;
    Recv* myRecv;
    QString word;
    QString meaning;
public:
    search(QWidget* p,MainWindow* m);
    ~search();
public slots:
    void searchWord();
    void recvMessage(Word);
    void addWord();
    void addWordtoBook();
    void editingFinishedSlot();
};

#endif // SEARCH

