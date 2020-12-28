#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

signals:

public slots:

protected:
    // 鼠标进入
    void enterEvent(QEvent *);
    // 鼠标离开
    void leaveEvent(QEvent *);
    // 鼠标按下
    void mousePressEvent(QMouseEvent *);
    // 鼠标释放
//    void mouseReleaseEvent(QMouseEvent *);
//    // 鼠标移动
//    void mouseMoveEvent(QMouseEvent *);
//    // 定时器
    void timerEvent(QTimerEvent *);

private:
    int id;

};

#endif // MYLABEL_H
