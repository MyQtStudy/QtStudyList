#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //initkeyiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
    b1 = new QPushButton("Close",this);
    b1->move(100,100);

    b2 = new QPushButton;
    b2->setParent(this);
    b2->setText("Close2");
    b2->move(100,200);
    b2->resize(200,200);

    // b1 close  window
    // qt 信号和槽都是函数
    // 1.信号只有函数声明,不需要函数定义
    // 2.槽函数数据需要声明也需要定义
    connect(b2,&QPushButton::clicked,this,&Widget::close);

    // 自定义槽函数
    /*
     * 1. 槽函数在QT5中可以是任意类成员函数,全局函数,静态函数,lambda表达式(隐式函数)
     * 2. 槽函数需要与信号对应(返回值,参数)
     * 3. 信号没有返回值,槽函数返回值:void
     * 4. void mysig(int,double,Qstring);
     *    void myslot(int,double,Qstring);
     * 5. 槽函数的参数是为了接受信号传递过来的数据
     * 6. 槽函数的参数应该是不能够大于信号的参数个数,可以少于信号的参数个数
     * 7. 槽函数可以重载
    */
    connect(b1,&QPushButton::released,this,&Widget::slotForMainWidget);

    // b3 显示子窗口SubWidget -- subW
    b3 = new QPushButton("软件园",this);
    b3->resize(150,150);
    b3->move(300,200);

    connect(b3,&QPushButton::clicked,this,&Widget::slotHideMe);

    // Qt 5 信号槽的使用方法
    void (SubWidget::*MySigSub)() = &SubWidget::sigSub;
    connect(&subW,MySigSub,this,&Widget::slotShowMe);

    void (SubWidget::*MySigPlus)(int,QString) = &SubWidget::sigSub;
    connect(&subW,MySigPlus,this,&Widget::slotSubMsg);

    //拓展:
    /*
     * 1. 信号可以连接信号
     * 2. 一个信号可以连接多个槽函数
     * 3. 多个信号可连接同一个槽函数
     * 4. 槽函数可以使用lambda表达式
    */

    //lambda 表达式 加 =可以跑值拷贝  , 加&引用方式,  用this, 使用当前类成员变量, b3按值传递
    //    [=](int num,QString str){
    //        b3->setText("aa");
    //    };

    //使用lambda 表达式作为槽函数
    connect(b1,&QPushButton::clicked,this,[=](){
        b2->setText("lambda表达式!");
        b3->hide();
    });




}

Widget::~Widget()
{
}

void Widget::slotForMainWidget()
{
    b2->setText("我被修改了!");
}

void Widget::slotHideMe(){
    // 隐藏自己
    hide();
    // 显示软件窗口
    subW.show();
}


void Widget::slotShowMe(){
    // 显示自己
    show();
    // 隐藏软件园窗口
    subW.hide();
}

void Widget::slotSubMsg(int num, QString str){

    // QString --> char*
    // string --> char*  .data()

    qDebug() << num << str.toUtf8().data();
}
