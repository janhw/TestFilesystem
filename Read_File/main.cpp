#include <QCoreApplication>
#include<QDir>
#include<QDebug>
#include<QTime>
#include<QString>
#include<../readConfig/readconfig.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    readConfig read;

    qDebug()<<argv[0];
    qDebug()<<argv[1];
    qDebug()<<argv[2];

    int n = atoi(argv[1]);//文件个数
    int num1 = atoi(argv[2]);//文件起始数

    QTime timer;
    timer.start();

//    QDir dir(read.map["readFilePath"]);//读文件目录
//    QStringList sl = dir.nameFilters();//文件目录列表
//    QStringList filter;
//    QList<QFileInfo> *fileInfo=new QList<QFileInfo>(dir.entryInfoList(filter));
//    int nFileNum = fileInfo->count();

//    if(n>nFileNum-2)
//    {
//        return 0;
//    }

    quint64 nSum = 0;

    for(int i=num1; i<=n; i++)
    {
        QString path = "%1\\%2";
        path = path.arg(read.map["readFilePath"]);
        QString fileName = "myTest_%3";
        QString PathName = path.arg(fileName).arg(i);
//        qDebug()<<PathName;
        QFile file(PathName);
        quint64 maxvalue = file.size();;
        char *p  = new char [maxvalue];
        file.open(QIODevice::ReadOnly);
        int n = file.read(p, maxvalue);
//        qDebug() << "n = " << n;
        delete [] p;
        nSum += n;
    }
//    qDebug() << "文件个数:" << n;
//    qDebug() << "文件总大小" << nSum/1000000 << "MB";
//    qDebug() << "耗时:" << timer.elapsed() << "ms";
    return 0;
}
