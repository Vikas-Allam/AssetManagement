#ifndef ASSETMANAGERINFORMATION_H
#define ASSETMANAGERINFORMATION_H
#include"AssetManagerInterface.h"
#include"SqlDataBase/AssetManagerDBServiceInterface.h"
#include"SqlDataBase/assetmanagerdbservice.h"
#include<assetreport.h>
#include<QMap>
#include<QSharedPointer>
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
     //  void Getdata();
       void Savedata(QMap<QString,QString>);


private:
     QMap<QString,QString>var;
     std::unique_ptr<AssetManagerDBServiceInterface> ptrDB = std::unique_ptr<AssetManagerDBService>(AssetManagerDBService::CreateInstance());

 // QSqlQueryModel *model=new QSqlQueryModel();


};

#endif // ASSETMANAGERINFORMATION_H
