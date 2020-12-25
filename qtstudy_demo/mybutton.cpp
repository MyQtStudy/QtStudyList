#include "mybutton.h"
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{


}

// 实现析构函数
MyButton::~MyButton(){
    // 调用打印以下字符串
    qDebug() << "this is my button! ";
}
