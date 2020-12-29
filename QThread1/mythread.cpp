#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run(){
    //复杂的操作
    this->sleep(5);
    emit sigDone();
}
