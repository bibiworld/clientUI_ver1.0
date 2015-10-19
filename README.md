# Bibi World客户端编写说明

																evan69于10.19夜

## 一、Git

项目地址 : [**https://github.com/bibiworld/clientUI_ver1.0**](https://github.com/bibiworld/clientUI_ver1.0)

SSH clone URL : **git@github.com:bibiworld/clientUI_ver1.0.git**

## 二、常用公共类及接口

1. **MainWindow**

	- 概述：MainWindow是本客户端的主界面，所有的客户端模块需要在它上面实现。每次新增一个客户端模块，需要向MainWindow类中加入相应的类指针。该类的构造函数应该有如下格式：
	
		` search(QWidget* p,MainWindow* m); `

		其中第二个参数是传入的MainWindow指针，使用它在MainWindow上构造控件或绘制图形。

	- 接口

		- `QTcpSocket* getSocket(void);` 获取通信所用的QTcpSocket指针

		- `void sendBubble(QString);` 可以在托盘中显示带文字的气泡

2. **Send**

	Send类可以将客户端用到的C++对象转换为向服务器传输的字符串。

	- `static void B_search(QTcpSocket* socket,QString word);`
    - `static void B_fuzzysearch(QTcpSocket* socket,QString word,int len = 0);`
    - `static void B_similar(QTcpSocket* socket,QString word);`
    - `static void B_quit(QTcpSocket* socket);`

	以上的静态函数第一参数均为从MainWindow对象处获得的QTcpSocket指针
    
3. **Recv**

	Recv类可以将服务器传输过来的的字符串转换为客户端用到的C++对象。使用方法是信号槽机制，Recv类根据协议提供若干信号，使用时首先在类里声明一个Recv指针，然后将所需的信号与合适的槽关联起来。注意需要在析构函数中显式delete这个指针，否则可能出现问题。目前提供的信号如下：
	
    - `void searchSignal(Word);` 获取查询单词的结果，回传一个Word类对象
    - `void fuzzySignal(QVector<Word>);` 获取模糊查询的结果，回传一个Word类对象的向量
    - `void similarSignal(QString,QVector<Word>);` 获取亲缘查询的结果，回传一个Word类对象的向量

## 三、图标

	图标还望lihy96加紧设计

## 四、存在的部分问题

- 登陆界面的美化

- 查询界面的美化

- 单词卡片的部分功能

- 单词本功能

- 亲缘单词功能

## 五、加油


全文完