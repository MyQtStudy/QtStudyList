#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    mytimer = new QTimer(this);

    connect(ui->start,&QPushButton::clicked,this,&MyWidget::slotStart);
    connect(ui->stop,&QPushButton::clicked,this,&MyWidget::slotStop);
    // 定时器
    // connect(mytimer,&QTimer::timeout,this,&MyWidget::slotTimeout);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::slotStart(){
    if(mytimer->isActive() == true){
        return;
    }
    mytimer->start(500);
}

void MyWidget::slotStop(){

}
