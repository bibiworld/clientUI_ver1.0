#include "login.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
{
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(QHostAddress(SERVER_IP),SERVER_PORT);
    connect(this->tcpSocket,SIGNAL(readyRead()),this,SLOT(recvMessage()));
    isSuccess = 0;
    isMyturn = 1;

    int width = 450;
    int height = 300;
    this->setFixedSize(width,height);

    setWindowTitle(tr("欢迎来到 bibiWorld"));

    pic = new QLabel;
    /*pic->setPixmap(":/images/1.jpg");
    pic->resize(450,1500);*/
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    userNameLabel = new QLabel;
    userNameLabel->setText(tr("用户名："));
    userPasswordLabel = new QLabel;
    userPasswordLabel->setText(tr("密码："));

    userNameEdit = new QLineEdit;
    userPasswordEdit = new QLineEdit;
    userPasswordEdit->QLineEdit::setEchoMode(QLineEdit::Password);

    remberPassword = new QCheckBox(tr("记住密码"));
    autoLogin = new QCheckBox(tr("自动登录"));

    logintoButton = new QPushButton;
    logintoButton->setText(tr("登录"));
    exitoutButton = new QPushButton;
    exitoutButton->setText(tr("退出"));
    forgetPasswordButton = new QPushButton;
    forgetPasswordButton->setText(tr("忘记密码？"));
    registerButton = new QPushButton;
    registerButton->setText(tr("注册"));

    upLayout = new QGridLayout();
    upLayout->addWidget(pic,0,0,1,5);
    upLayout->addWidget(userNameLabel,2,0);
    upLayout->addWidget(userNameEdit,2,1);
    upLayout->addWidget(userPasswordLabel,3,0);
    upLayout->addWidget(userPasswordEdit,3,1);
    // upLayout->addWidget(logintoButton,4,0);
    //upLayout->addWidget(exitoutButton,4,1);
    upLayout->addWidget(forgetPasswordButton,2,2);
    upLayout->addWidget(registerButton,3,2);
    upLayout->addWidget(remberPassword,5,0);
    upLayout->addWidget(autoLogin,5,1);

    lowLayout = new QVBoxLayout();
    //lowLayout->addLayout(upLayout);
    lowLayout->addWidget(logintoButton);
    lowLayout->addWidget(exitoutButton);

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(upLayout,0,0);
    mainLayout->addLayout(lowLayout,1,0);
    //mainLayout->setSizeConstraint(QLayout::SetFixedSize);



    connect(logintoButton,SIGNAL(clicked()),this,SLOT(loginto()));
    connect(exitoutButton,SIGNAL(clicked()),this,SLOT(exitout()));
    connect(forgetPasswordButton,SIGNAL(clicked()),this,SLOT(forgetPassword()));
    connect(registerButton,SIGNAL(clicked()),this,SLOT(toRegister()));


}

Login::~Login()
{

}

void Login::loginto(){
    QString tmpname = userNameEdit->text();
    QString tmppassword = userPasswordEdit->text();
    if(tmpname==""||tmppassword=="")return;
    QString info = "BIBI_login((" + tmpname + ")(" + tmppassword + "))";
    sendMessage(info);
    //sendMessage("baijiaoyuan nizhale");
    state = LOGIN;
}
void Login::exitout(){
    exit(0);
    close();
}

void Login::forgetPassword(){

}

void Login::toRegister(){
    QString tmpname = userNameEdit->text();
    QString tmppassword = userPasswordEdit->text();
    if(tmpname==""||tmppassword=="")return;
    QString info = "BIBI_register((" + tmpname + ")(" + tmppassword + "))";
    sendMessage(info);
    state = REGISTER;
}

void Login::sendMessage(QString info){
    QByteArray *array =new QByteArray;
    array->clear();
    array->append(info);
    tcpSocket->write(array->data());
    tcpSocket->flush();
}
void Login::recvMessage(){
    if(!isMyturn)
        return;
    QString info;
    info = this->tcpSocket->readAll();
    qDebug() << info;
    if(state==REGISTER){
        if(info=="BIBI_register((1))"){
            QMessageBox::information(this,tr("register"),tr("successfully registered!"));
        }
        else if(info=="BIBI_register((0))"){
            QMessageBox::information(this,tr("register"),tr("registered failed!"));
        }
        else
            qDebug() << "error";
    }

    if(state==LOGIN){
        if(info=="BIBI_login((1)(1))"){
            qDebug() << "login successful";
            isSuccess = true;
            isMyturn = 0;
            close();
        }
        else if(info=="BIBI_login((1)(0))"){
            QMessageBox::information(this,tr("login"),tr("password error!"));
        }
        else if(info=="BIBI_login((0)(0))"){
            QMessageBox::information(this,tr("login"),tr("No username"));
        }
        else
            qDebug() << "login error";
    }
}

void Login::closeEvent(QCloseEvent *)
{
     if(!isSuccess) exit(0);
}
