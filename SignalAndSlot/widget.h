#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 自定义槽函数
    void slotForMainWidget();

private:
    QPushButton* b1;
    QPushButton* b2;
};

#endif // WIDGET_H
