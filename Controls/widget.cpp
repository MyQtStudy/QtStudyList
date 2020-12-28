#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    connect(ui->groupBox-,&QRadioButton::released,this,[=](){
//        QMessageBox::information(this,"radioButton","hah+");
//    });
   // ui->pushButton('me',this);

    connect(ui->checkBox,&QCheckBox::stateChanged,this,[=](int state){
         QMessageBox::information(this,"checkbox",QString::number(state));
    });

    ui->listWidget->addItem("heelo, memem!");
}

Widget::~Widget()
{
    delete ui;
}

