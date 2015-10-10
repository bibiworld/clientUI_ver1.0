#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QtNetwork/QTcpSocket>
#include <vector>
#include <QString>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QMenu>

#include "send.h"
#include "recv.h"
#include "search.h"
#include "fuzzysearch.h"
#include "login.h"
#include "cards.h"

using std::vector;

namespace Ui {
class MainWindow;
}
class search;
class fuzzySearch;
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
    QSystemTrayIcon* trayIcon;//托盘图标
    QMenu* trayMenu;
    QAction* maxAction;
    QAction* minAction;
    QAction* quitAction;
    QToolBar* toolBar;//工具条
    search* mySearch;//单词查询
    fuzzySearch* myFuzzySearch;//模糊查询
    Login* myLogin;//登陆界面
    Cards* myCards;//单词卡
    QLabel* sentencesLabel;
    vector<QString> eng;
    vector<QString> chi;
    void clearUI();
    
    void closeEvent(QCloseEvent *);
    void changeEvent(QEvent *);
private slots:
    void searchWord();
    void fuzzySearchWord();
    void userInfo();
    void printCards();
    
    void trayiconActivated(QSystemTrayIcon::ActivationReason reason);
};

#endif // MAINWINDOW_H
