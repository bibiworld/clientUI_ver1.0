#ifndef CARDS_H
#define CARDS_H
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

using std::vector;

class MainWindow;
class Cards : public QDialog
{
    Q_OBJECT
private:
    MainWindow* parent;
    QListWidget* list;
    QPushButton* del;
    QPushButton* pri;
    void print(vector<QString>&, vector<QString>&);
    void drawLines(QPainter* pdf_painter);
public:
    Cards(MainWindow* p);
    ~Cards();
private slots:
    void printPdf();
    void remove();
};

#endif // CARDS_H
