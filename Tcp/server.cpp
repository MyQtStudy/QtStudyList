#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);

    // ui init
    ui->sIP->setText("127.0.0.1");
    ui->sPort->setText("9999");
    // 实例化 init
    server = new QTcpServer(this);
    // 监听
    server->listen(QHostAddress(ui->sIP->text()),ui->sPort->text().toInt());

    // 新的链接
    connect(server,&QTcpServer::newConnection,this,[=](){
        //接收客户端的套接字对象 accept
        //sock_addr　结构体 == 类　QTcpSocket
        conn = server->nextPendingConnection();
        // 发送数据
       //conn->write("小弟，你好，我是你的大爷");
        ui->record->append("有新的链接");

        // 保证conn 是一个有效的对象
        connect(conn,&QTcpSocket::readyRead,this,[=](){

            //接收数据
            QByteArray array = conn->readAll();
            ui->record->append(array);
        });

    });
    // 发送
    connect(ui->send,&QPushButton::clicked,this,[=](){
        // 发送数据
       conn->write(ui->msg->toPlainText().toUtf8().data());
       ui->record->append("Me Say:"+ui->msg->toPlainText());
       // clear
       ui->msg->clear();
    });




}

Server::~Server()
{
    delete ui;
}

