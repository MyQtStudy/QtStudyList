#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 自定义槽函数
    void slotForMainWidget();
    void slotHideMe();
    void slotShowMe();
    void slotSubMsg(int num,QString str);

private:
    QPushButton* b1;
    QPushButton* b2;
    QPushButton* b3;   // 显示子窗口
    //子窗口对象
    SubWidget subW;
};

#endif // WIDGET_H
