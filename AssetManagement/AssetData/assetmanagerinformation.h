//#ifndef ASSETMANAGERINFORMATION_H
//#define ASSETMANAGERINFORMATION_H
#pragma once
#include"AssetManagerInterface.h"
#include<QMap>
#include<QSqlQueryModel>
class AssetManagerInformation:public AssetManagerinterface
{

public:
AssetManagerInformation();

     QString AssetName();
     QString AssetType();
      QString Description();
    QString SerialNumber();
  QString Manufacturer();
     QString Model();
   QString Owner();
    QString Condition();
      QString Site();
      QString Location();
      QString imagedata();
       bool Getdata(QString);
       bool Savedata(QMap<QString,QString>);
      bool IsDataAdded();


private:
      bool success;
     QMap<QString,QString>var;
     bool DataReceived;
// std::unique_ptr<AssetManagerDBServiceInterface> ptrDB = std::unique_ptr<AssetManagerDBService>(AssetManagerDBService::CreateInstance());
  QSqlQueryModel *model=new QSqlQueryModel();


};

//#endif // ASSETMANAGERINFORMATION_H
