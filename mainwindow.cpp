#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QDebug>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QFile>
#include <QPainter>
#include <QDebug>
#include <QPen>
#include <QPageLayout>
const QString imagesPath = ":/images";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->hide();
    
    myLogin = new Login(this);
    myLogin->show();
    myLogin->exec();
    myLogin->hide();
    
    //if(!myLogin->findSuccess()) exit(0);
    this->show();
    socket = myLogin->getSocket();
    mySearch = 0;
    myCards = 0;
    myFuzzySearch = 0;
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

