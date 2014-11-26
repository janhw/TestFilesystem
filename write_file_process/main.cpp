#include <QCoreApplication>
#include<QProcess>
#include<QDebug>
#include<QTime>
#include<../readConfig/readconfig.h>

class CreateProcess
{
public:
    CreateProcess(int Pnumber, int fileBaseNum, QString program, int fileSize,QTime timer);
    ~CreateProcess();
public:
    void clear_pro(void);

public:
    QVector<QProcess*> integerVector;
    QTime Timer;
    long sum;//总文件大小
    int filenum;//
    int processNum;
};

CreateProcess::CreateProcess(int Pnumber, int fileBaseNum, QString program, int fileSize,QTime timer)
{
    Timer =  timer;
    filenum = Pnumber*fileBaseNum;
    processNum = Pnumber;
    for(int i=0;i<Pnumber;i++)
    {
        QProcess *myProcess = new  QProcess();
        QStringList arguments;
        int n=i*fileBaseNum+1;
        int n1=(i+1)*fileBaseNum;

        arguments.append(QString("%1").arg(n1));//个数n1
        arguments.append(QString("%1").arg(fileSize));//大小
        arguments.append(QString("%1").arg(n));//起始数据n1
        myProcess->start(program, arguments);
        integerVector.append(myProcess);
    }
    sum = Pnumber * fileBaseNum * fileSize;
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
                qDebug()<< "总文件写数据大小："<<sum<<"kB";
                qDebug()<< "总文件写速度："<<sum/(Timer.elapsed()/1000.00) <<"kBps";
                qDebug()<< "每个进程写文件速度："<<sum/(Timer.elapsed()/1000.00)/processNum <<"kBps";
                qDebug()<< "每秒写文件个数："<< filenum/(Timer.elapsed()/1000.0) <<"个/s";
                qDebug()<< "每个进程写文件个数："<< filenum/(Timer.elapsed()/1000.0)/processNum <<"个/s";
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printf("Please Input Process Num :\n");
    int Pnumber;
    QTextStream stream(stdin);
    stream >> Pnumber;

    printf("Please Input fileBase Num  :\n");
    int fileBaseNum;
    QTextStream stream1(stdin);
    stream1 >> fileBaseNum;

    printf("Please Input fileSize (kB) :\n");
    int fileSize;
    QTextStream stream2(stdin);
    stream2 >> fileSize;

    readConfig read;

    QString program = read.map["writeFileEXE"] ;

    QTime timer;
    timer.start();

    CreateProcess Cprocess(Pnumber, fileBaseNum, program, fileSize, timer);
    Cprocess.clear_pro();

    return 0;
}
