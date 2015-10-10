#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QLineEdit>
#include <QDebug>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QFile>
#include <QPainter>
#include <QDebug>
#include <QPen>
#include <QMessageBox>

const QString imagesPath = ":/images";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    this->hide();
    myLogin = new Login(this);
    myLogin->show();
    myLogin->exec();
    myLogin->hide();
    if(!myLogin->findSuccess()) exit(0);
    */
    trayIcon = new QSystemTrayIcon(this);
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                this,SLOT(trayiconActivated(QSystemTrayIcon::ActivationReason)));
    trayMenu = new QMenu(this);
    //trayIcon->setToolTip("Bibi");
    //trayIcon->showMessage("Bibi World","Bibi World正在后台运行",QSystemTrayIcon::Information,5000);
    QIcon icon(imagesPath + "/logo.png");
    
    maxAction = new QAction(this);
    maxAction->setText("还原");
    connect(maxAction,SIGNAL(triggered(bool)),this,SLOT(showNormal()));
    minAction = new QAction(this);
    minAction->setText("最小化");
    connect(minAction,SIGNAL(triggered(bool)),this,SLOT(hide()));
    quitAction = new QAction(this);
    quitAction->setText("退出程序");
    connect(quitAction,SIGNAL(triggered(bool)),this,SLOT(close()));
    
    trayMenu->addAction(maxAction);
    trayMenu->addAction(minAction);
    trayMenu->addAction(quitAction);
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("Bibi World");
    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();
    
    this->show();
    //socket = myLogin->getSocket();
    socket = 0;
    
    mySearch = 0;
    myCards = 0;
    myFuzzySearch = 0;
    
    sentencesLabel = new QLabel(this);
    sentencesLabel->setMargin(30);
    sentencesLabel->setGeometry(80,410,440,80);
    sentencesLabel->setText("此处将显示每日好句");
    sentencesLabel->show();
    
    toolBar = new QToolBar(this);
    this->setContextMenuPolicy(Qt::NoContextMenu);
    QAction* searchAction = new QAction(QIcon(imagesPath + "/search.png"),tr("查询单词"),this);
    QAction* userAction = new QAction(QIcon(imagesPath + "/user.png"),tr("用户管理"),this);
    QAction* cardAction = new QAction(QIcon(imagesPath + "/cards.png"),tr("单词卡"),this);
    QAction* fuzzyAction = new QAction(QIcon(imagesPath + "/user.png"),tr("模糊查询"),this);
    
    toolBar->addAction(searchAction);
    toolBar->addAction(fuzzyAction);
    toolBar->addAction(cardAction);
    toolBar->addAction(userAction);
    
    this->addToolBar(Qt::TopToolBarArea,toolBar);
    
    connect(searchAction,SIGNAL(triggered(bool)),this,SLOT(searchWord()));
    connect(fuzzyAction,SIGNAL(triggered(bool)),this,SLOT(fuzzySearchWord()));
    connect(userAction,SIGNAL(triggered(bool)),this,SLOT(userInfo()));
    connect(cardAction,SIGNAL(triggered(bool)),this,SLOT(printCards()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearUI()
{
    if(mySearch != 0)
    { 
        delete mySearch;
        mySearch = 0;
    }
    if(myCards != 0)
    { 
        delete myCards;
        myCards = 0;
    }
    if(myFuzzySearch != 0)
    {
        delete myFuzzySearch;
        myFuzzySearch = 0;
    }
}

QTcpSocket* MainWindow::getSocket()
{
     return socket;
}

void MainWindow::searchWord()
{
    clearUI();
    mySearch = new search(0,this);
}

void MainWindow::fuzzySearchWord()
{
    clearUI();
    myFuzzySearch = new fuzzySearch(0,this);
}

void MainWindow::userInfo()
{
    clearUI();
}

void MainWindow::printCards() {
    clearUI();
    myCards = new Cards(this);
    qDebug() << "print cards!";
}

void MainWindow::trayiconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:
        //单击托盘图标
    case QSystemTrayIcon::DoubleClick:
        //双击托盘图标
        this->showNormal();
        this->raise();
        break;
    default:
        break;
    }
}

void MainWindow::closeEvent(QCloseEvent *)
{
    int ret = QMessageBox::information(this,"退出","你确定要退出Bibi World吗?",QMessageBox::Yes | QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        //socket->write("BIBI_quit");
        exit(0);
    }
}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type()==QEvent::WindowStateChange){  
        if(windowState() & Qt::WindowMinimized){  
            hide();  
            trayIcon->show();  
        }
    }
    QMainWindow::changeEvent(event);
}
