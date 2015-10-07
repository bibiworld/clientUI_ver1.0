#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QtNetwork/QTcpSocket>
#include <vector>
#include <QString>
#include "search.h"
#include "login.h"
#include "cards.h"

using std::vector;

namespace Ui {
class MainWindow;
}
class search;
class Cards;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Cards;
    friend class search;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTcpSocket* socket;
    QTcpSocket* getSocket();
private:
    Ui::MainWindow *ui;
    QToolBar* toolBar;
    search* mySearch;
    Login* myLogin;
    Cards* myCards;
    vector<QString> eng;
    vector<QString> chi;
    void clearUI();
private slots:
    void searchWord();
    void userInfo();
    void printCards();
};

#endif // MAINWINDOW_H
