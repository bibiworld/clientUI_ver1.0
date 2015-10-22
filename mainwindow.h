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
#include "wordbook.h"

using std::vector;

namespace Ui {
class MainWindow;
}
class search;
class fuzzySearch;
class Cards;
class wordBook;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Cards;
    friend class search;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTcpSocket* getSocket();//获取通信用的socket指针
    
public slots:
    void sendBubble(QString);//托盘显示气泡的接口
private:
    Ui::MainWindow *ui;
    QTcpSocket* socket;//socket指针
    QSystemTrayIcon* trayIcon;//托盘图标
    QMenu* trayMenu;//托盘菜单
    QAction* maxAction;//还原
    QAction* minAction;//最小化
    QAction* quitAction;//退出
    QToolBar* toolBar;//工具条
    search* mySearch;//单词查询
    fuzzySearch* myFuzzySearch;//模糊查询
    Login* myLogin;//登陆界面
    Cards* myCards;//单词卡
    wordBook* myWordBook;//单词本
    QLabel* sentencesLabel;//每日好句
    vector<QString> eng;
    vector<QString> chi;
    
    void closeEvent(QCloseEvent *);//关闭事件
    void changeEvent(QEvent *);//change事件
private slots:
    void searchWord();//查找单词界面
    void fuzzySearchWord();//模糊查询界面
    void userInfo();//用户界面
    void printCards();//打印单词卡
    void showWordBook();//单词本
    void clearUI();//清除UI
    void trayiconActivated(QSystemTrayIcon::ActivationReason reason);//托盘点击事件
};

#endif // MAINWINDOW_H
