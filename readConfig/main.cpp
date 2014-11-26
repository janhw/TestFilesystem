#include <QCoreApplication>
#include<QFile>
#include<QDebug>
#include<stdio.h>
#include<QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString,QString> map;

    QStringList lines;
    QString path = "E:\\Demo\\QT\\read_write_file\\write_file_process\\config\\config.cfg";
    QFile file(path);

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString line;

        while(!stream.atEnd())
        {
            line = stream.readLine();
//            qDebug()<<line;
            lines += line;
        }
        file.close();
    }

    for(int i = 0; i<=3; i++)
    {
        QStringList tmp;
        tmp = lines.at(i).split(' ');
//        qDebug()<<tmp[0]<<" "<<tmp[1];
        map[tmp[0]] = tmp[1];
    }

    return a.exec();
}
