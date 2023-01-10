#include "assetreport.h"
#include<QPdfWriter>
#include<QPainter>
#include<QMap>
#include<QDebug>

AssetReport::AssetReport()
{
    qDebug()<<"Asset report:";


}

bool AssetReport::printData(int columns,QString v[])
{
bool success=true;
    int j=0;
    for(int i=0;i<columns;i++)
    {
        data[i]=v[i];

    }


    QPdfWriter pdf("AssetData.pdf");
    QPainter painter(&pdf);


    QFont f( "Verdana", 27, QFont::Bold);
    painter.setFont(f);

      painter.drawText(1900,800,"AssetManagement");

      QFont f1( "Verdana", 12);
    painter.setFont(f1);

    painter.drawText(1000,2800,"AssetID");
    painter.drawText(3500,2800,":");
    painter.drawText(4500,2800,data[0]);

    painter.drawText(1000,3300,"AssetName");
    painter.drawText(3500,3300,":");
    painter.drawText(4500,3300,data[1]);
    painter.drawText(1000,3800,"AssetType");
    painter.drawText(3500,3800,":");
    painter.drawText(4500,3800,data[2]);
    painter.drawText(1000,4300,"Description");
    painter.drawText(3500,4300,":");
   painter.drawText(4500,4300,data[3]);
    painter.drawText(1000,4800,"Serial NUmber");
    painter.drawText(3500,4800,":");
    painter.drawText(4500,4800,data[4]);
    painter.drawText(1000,5300,"Manufacturer");
    painter.drawText(3500,5300,":");
    painter.drawText(4500,5300,data[5]);
    painter.drawText(1000,5800,"Model");
    painter.drawText(3500,5800,":");
    painter.drawText(4500,5800,data[6]);
    painter.drawText(1000,6300,"Owner");
    painter.drawText(3500,6300,":");
    painter.drawText(4500,6300,data[7]);

    painter.drawText(1000,6800,"Condition");
    painter.drawText(3500,6800,":");
    painter.drawText(4500,6800,data[8]);
    painter.drawText(1000,7300,"Site");
    painter.drawText(3500,7300,":");
    painter.drawText(4500,7300,data[9]);

    painter.drawText(1000,7800,"Location");
    painter.drawText(3500,7800,":");
    painter.drawText(4500,7800,data[10]);

    painter.drawText(1000,8300,"imagepath");
    painter.drawText(3500,8300,":");
    painter.drawText(4500,8300,data[11]);
    QPixmap pix2(data[11]);
    painter.drawPixmap(7300,500,pix2);

return success;
}
