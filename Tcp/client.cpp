#include "client.h"
#include "ui_client.h"
#include <QHostAddress>

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    ui->sIP->setText("127.0.0.1");
    ui->sPort->setText("9999");

    // init
    client = new QTcpSocket(this);
    // 链接服务器
    client->connectToHost(QHostAddress(ui->sIP->text()),ui->sPort->text().toInt());

    //　接收数据
    connect(client,&QTcpSocket::readyRead,this,[=]{
        QByteArray array = client->readAll();
        ui->record->append(array);
    });

    connect(ui->send,&QPushButton::clicked,this,[=](){
        client->write(ui->msg->toPlainText().toUtf8());
        ui->record->append("ME Say:" + ui->msg->toPlainText());
        // clear
        ui->msg->clear();
    });
}

Client::~Client()
{
    delete ui;
}
