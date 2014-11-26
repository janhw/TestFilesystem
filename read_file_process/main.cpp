#include <QCoreApplication>
#include<QProcess>
#include<QDebug>
#include<QTime>
#include<../readConfig/readconfig.h>

class CreateProcess
{
public:
    CreateProcess(int Pnumber, int fileBaseNum, QString program, QTime timer);
    ~CreateProcess();
public:
    void clear_pro(void);

public:
    QVector<QProcess*> integerVector;
    QTime Timer;
    int processNum;
    int filenum;//
};

CreateProcess::CreateProcess(int Pnumber, int fileBaseNum, QString program, QTime timer)
{
    Timer =  timer;
    processNum = Pnumber;

    for(int i=0;i<Pnumber;i++)
    {
        QProcess *myProcess = new  QProcess();
        QStringList arguments;
        int n=i*fileBaseNum+1;
        int n1=(i+1)*fileBaseNum;

        arguments.append(QString("%1").arg(n1));//个数n1
//        arguments.append(QString("%1").arg(fileSize));//大小
        arguments.append(QString("%1").arg(n));//起始数据n1
//        arguments.append(writepath);
        myProcess->start(program, arguments);
        integerVector.append(myProcess);
    }
    filenum = Pnumber * fileBaseNum;
}

CreateProcess::~CreateProcess()
{
    for (int i = 0; i < integerVector.size(); ++i)
    {
        integerVector.at(i)->close();
    }
}

void CreateProcess::clear_pro(void)
{
    while(1)
    {
        for (int i = 0; i < integerVector.size(); ++i)
        {
            if(integerVector.at(i)->waitForFinished())
            {
                integerVector.at(i)->close();
                integerVector.remove(i);
            }
            if(integerVector.isEmpty())
            {
                qDebug() << "耗时:" << Timer.elapsed() << "ms";
                qDebug()<< "总文件个数："<<filenum;
                qDebug()<< "每秒读文件个数："<< filenum/(Timer.elapsed()/1000.00) <<"个/s";
                qDebug()<< "每个进程读文件个数："<< filenum/(Timer.elapsed()/1000.00)/processNum <<"个/s";
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    printf("Please Input Process number :\n");
    int Pnumber;
    QTextStream stream(stdin);
    stream >> Pnumber;

    printf("Please Input fileBaseNum  :\n");
    int fileBaseNum;
    QTextStream stream1(stdin);
    stream1 >> fileBaseNum;

    readConfig read;

    QString program = read.map["readFileEXE"];

    QTime timer;
    timer.start();

    CreateProcess Cprocess(Pnumber, fileBaseNum, program, timer);
    Cprocess.clear_pro();
    return 0;
}
