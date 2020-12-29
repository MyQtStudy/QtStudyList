#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    // 开始按钮
    void slotStart();
    // 关闭按钮
    void slotStop();

    void slotTimeout();
private:
    Ui::MyWidget *ui;
    QTimer* mytimer;
};
#endif // MYWIDGET_H
