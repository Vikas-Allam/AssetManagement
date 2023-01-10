#include "assetmainwindow.h"
#include"assetmanagerinformation.h"
#include <QApplication>
#include"SqlDataBase/assetmanagerdbservice.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AssetMainWindow w;

//bool Success=p->Getdata("RaspBerry");
//qDebug()<<Success;
    w.show();
    return a.exec();
}
