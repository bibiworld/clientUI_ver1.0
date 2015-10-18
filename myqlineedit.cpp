#include "myqlineedit.h"

myQLineEdit::myQLineEdit(QWidget *parent) : QLineEdit(parent)
{
    QPalette pal = this->palette();
    pal.setColor(QPalette::Text,QColor(211,211,211));
    this->setPalette(pal);
    this->setText("请输入要查询的单词");
}

void myQLineEdit::focusInEvent(QFocusEvent*)
{
    if(this->text() == "请输入要查询的单词")
    {
        this->setText("");
    }
    QPalette pal =this->palette();
    pal.setColor(QPalette::Text,QColor(0,0,0));
    this->setPalette(pal);
}
