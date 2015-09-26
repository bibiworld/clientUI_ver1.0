#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QtNetwork/QTcpSocket>
#include "search.h"
#include "login.h"

namespace Ui {
class MainWindow;
}
class search;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
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
    void clearUI();
    
private slots:
    void searchWord();
    void userInfo();
};

#endif // MAINWINDOW_H
