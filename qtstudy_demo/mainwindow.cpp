#include "mainwindow.h"
#include "mybutton.h" // 自定义类头文件

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*
     * 如果窗口需要依附于另外一个窗口,需要给窗口指定父类
     * 父窗口显示的时候,子窗口也会随之显示
    */
    b2 = new QPushButton("hello, qt",this);
    // b2->setText("Hello,qt");
    // b2->show();

    b1.setParent(this);
    b1.setText("我是老二");

    // 改变位置 -- 移动
    // 窗口坐标系,原点在左上角
    b1.move(200,0);
    b1.resize(50,50);

    // 内存自动回收
    // 1.从QObject派生的类  1.直接  2.间接
    // 2.指定父类

    // 创建自定义的按钮对象
    MyButton* btn = new MyButton(this);
    btn->setText("我是mybutton");
    btn->move(0,200);

    // 设置窗口标题  test1
    this->setWindowTitle("这是我第一个程序");
    // 设置窗口大小
    this->resize(400,400);

}

MainWindow::~MainWindow()
{

}

