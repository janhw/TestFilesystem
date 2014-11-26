#include <QCoreApplication>
#include<QFile>
#include<QDebug>
#include<../readConfig/readconfig.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    readConfig read;
//创建文件：
    qDebug()<<1;
    qDebug()<<argv[0];
    qDebug()<<argv[1];
    qDebug()<<argv[2];
    qDebug()<<argv[3];

    int n = atoi(argv[1]);//文件个数
    int num = atoi(argv[2]);//文件大小
    int num1 = atoi(argv[3]);//文件起始数

    char* data = new char[num*1024];
    memset(data,'*',num*1024);

    for(int i=num1;i<=n;i++)
    {
        QString path = "%1\\%2";
        path = path.arg(read.map["writeFilePath"]);
        QString fileName = "myTest_%3";
        QString PathName = path.arg(fileName).arg(i);

        QFile file(PathName);
        file.open(QIODevice::WriteOnly | QIODevice::Text);

        QTextStream out(&file);
        out << data;
        file.flush(); //冲刷所有的缓冲数据到文件中

        file.close();
    }

    delete data;
    data = NULL;

    return 0;
}
