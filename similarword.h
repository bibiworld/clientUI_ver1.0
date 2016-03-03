#ifndef SIMILARWORD_H
#define SIMILARWORD_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDialog>
#include <QtNetwork/QTcpSocket>
#include <QPushButton>
#include "mainwindow.h"
#include "word.h"
#include "myqlineedit.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDialog>
#include <QtNetwork/QTcpSocket>
#include <QScrollArea>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QListView>
#include <vector>
#include <QListWidget>
#include <QListWidgetItem>
#include <QGroupBox>
#include "mainwindow.h"

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
class SimilarWord : public QDialog
{
    Q_OBJECT
private:
    MainWindow* parent;
    myQLineEdit* lineEdit;
    QTextEdit* textEdit;
    QPushButton* button;
    Recv* myRecv;
public:
    SimilarWord(MainWindow* m);
    ~SimilarWord();
public slots:
    void searchWord();
    void recvMessage(QString,QVector<Word>);
};

#endif // SIMILARWORD_H
