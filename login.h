#ifndef LOGIN_H
#define LOGIN_H

#include <windows.h>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QTcpSocket>
#include <QtNetwork>
#include <QHostAddress>
#include <QDebug>
#include <QMessageBox>
#include <QSplashScreen>
#include <QThread>
#include <QTimer>
#include <QTime>
#include <QFile>
<<<<<<< HEAD
#include <QThread>

#define SERVER_IP "59.66.131.73"
=======

#define SERVER_IP "59.66.131.186"
>>>>>>> 9054b7df4035bb28bc5963e390a1abd25640d84c
#define SERVER_PORT 1234
//#define SERVER_IP "127.0.0.1"
//#define SERVER_PORT 8010
#define LOGIN 1
#define REGISTER 2

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = 0);
    ~Login();
    void closeEvent(QCloseEvent *);
    bool findSuccess();

private slots:
    void loginto();//登录按钮
    void exitout();//退出按钮
    void forgetPassword();//忘记密码按钮
    void toRegister();//帮助按钮

    
private:
    QLabel *userNameLabel;
    QLabel *userPasswordLabel;
    QLineEdit *userNameEdit;
    QLineEdit *userPasswordEdit;
    QCheckBox *remberPassword;
    QCheckBox *autoLogin;

    QPushButton *logintoButton;
    QPushButton *exitoutButton;
    QPushButton *forgetPasswordButton;
    QPushButton *registerButton;

    QGridLayout *mainLayout;
    QGridLayout *upLayout;
    QVBoxLayout *lowLayout;

    QLabel *pic;

private://interface for hyf
    QString username;
    QTcpSocket *tcpSocket;
    int state;
    bool isSuccess;
    bool isMyturn;
    QTimer* time;
    void findAuto();
<<<<<<< HEAD
    bool connectedSuccess;
    void isConnected(){
        connectedSuccess = true;
        qDebug() << "iconnected";
    }
=======
>>>>>>> 9054b7df4035bb28bc5963e390a1abd25640d84c
public:
    QString getUserName(){
        return username;
    }
    QTcpSocket* getSocket(){
        return tcpSocket;
    }
public slots:
    void recvMessage();
    void afterTimeout();
public:
    void sendMessage(QString info);
};

#endif // LOGIN_H
