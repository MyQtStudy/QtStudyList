#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);

    ui->cIp->setText("127.0.0.1");
    ui->cPort->setText("9999");
    ui->sPort->setText("8888");

    udp1 = new QUdpSocket(this);

    // if want receive must bind port
    udp1->bind(QHostAddress::AnyIPv4,ui->sPort->text().toInt());

    // send msg  组播 与 广播
    connect(ui->send,&QPushButton::clicked,this,[=](){
        udp1->writeDatagram(ui->msg->toPlainText().toUtf8(),QHostAddress("224.0.0.10"),ui->cPort->text().toInt());
        ui->record->append("Me say:"+ui->msg->toPlainText());
    });

    connect(udp1,&QUdpSocket::readyRead,this,[=](){
        qint64 size = udp1->pendingDatagramSize();
        QByteArray array(size,0);
        udp1->readDatagram(array.data(),size);
        ui->record->append(array);
        ui->msg->clear();
    });
}

Server::~Server()
{
    delete ui;
}

