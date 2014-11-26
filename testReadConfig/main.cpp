#include <QCoreApplication>
#include"readconfig.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    readConfig config;
    qDebug()<<config.map.value("readFilePath");
    qDebug()<<config.map.value("writeFilePath");
    qDebug()<<config.map.value("readFileEXE");
    qDebug()<<config.map.value("writeFileEXE");
    
    return a.exec();
}
