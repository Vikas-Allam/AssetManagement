#include "assetmainwindow.h"
#include<iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AssetMainWindow w;


    w.show();
    return a.exec();
}
