#ifndef LOGIN_H
#define LOGIN_H

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

#define SERVER_IP "59.66.131.174"
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

private slots:
    void loginto();//登录按钮
    void exitout();//退出按钮
    void forgetPassword();//忘记密码按钮
    void toRegister();//帮助按钮
    void closeEvent(QCloseEvent *);
    
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
public:
    QString getUserName(){
        return username;
    }
    QTcpSocket* getSocket(){
        return tcpSocket;
    }
public slots:
    void recvMessage();
public:
    void sendMessage(QString info);
};

#endif // LOGIN_H
