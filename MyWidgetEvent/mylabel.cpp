#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setText("++++++++++");
    this->setMouseTracking(true);

    // 启动定时器
    // 参数 1:触发定时器的时间, 单位:ms
    // 参数2 使用默认值
    id = startTimer(100);
}

// 鼠标进入函数
void MyLabel::enterEvent(QEvent *){
    setText("你不要乱动");
}

// 鼠标离开
void MyLabel::leaveEvent(QEvent *){
    setText("你可以玩耍了");
}

void MyLabel::mousePressEvent(QMouseEvent *ev){

//    QString str = "123";
//    int number = str.toInt();
//    int nnumber = 123;
//    str = QString::number(nnumber);

    // 字符串拼接QString().arg()
    // "%1,%2,%3 -- 占位符
    QString btn;
//    if(ev->button() ==)
//    QString str = QString("%1,%2").arg().arg();
    setText("str");


}

//没触发一次定时器,进入该函数中
void MyLabel::timerEvent(QTimerEvent *e){
    static int num = 0;
    QString str = QString("%1,%2").arg("Time out:").arg(num++);
    if(num ==100){
        killTimer(id);
    }
    setText(str);
}
