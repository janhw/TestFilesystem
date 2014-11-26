#ifndef READCONFIG_H
#define READCONFIG_H
#include<QMap>

//#define LIBSHARED_EXPORT Q_DECL_EXPORT

class readConfig
{
public:
    readConfig();

public:
    QMap<QString,QString> map;
};

#endif // READCONFIG_H
