#include "readconfig.h"
#include<QFile>
#include<QDebug>
#include<stdio.h>
#include<QStringList>

readConfig::readConfig()
{
    QStringList lines;
    QString path = "D:\\QT_test\\5.1.0\\readFile\\write_file_process\\build-testReadConfig-Desktop_Qt_5_1_0_MinGW_32bit-Debug\\debug\\config\\config.cfg";
    QFile file(path);

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString line;

        while(!stream.atEnd())
        {
            line = stream.readLine();
            lines += line;
        }
        file.close();
    }

    for(int i = 0; i<=3; i++)
    {
        QStringList tmp;
        tmp = lines.at(i).split(' ');
        map[tmp[0]] = tmp[1];
    }
}
