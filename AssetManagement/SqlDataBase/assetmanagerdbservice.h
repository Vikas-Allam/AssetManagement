#pragma once

#include"AssetManagerDBServiceInterface.h"
#include<QString>
#include<QSqlDatabase>
#include<QObject>
#include<QMap>
class AssetManagerDBService:public AssetManagerDBServiceInterface
{

private:
    static AssetManagerDBService *single;
    AssetManagerDBService();
//    ~AssetManagerDBService();
    QMap<QString,QString>map;
 QString AssetName,AssetType,Description,SerialNumber,Manufacturer,Model,Owner,Condition,Site,Location,imagedata;
  bool IsConnected;
   bool AddSuccess;
public:
         QSqlDatabase db;
      static AssetManagerDBService *CreateInstance();

     bool getMap(QMap<QString,QString>);

   bool  isOpen() const;
    bool createTable();
  bool  removeAllData();
  QString ParticularData();
 bool IsDBConnected();
       bool IsDataAdded();
    AssetManagerDBService(bool connectStatus);

};


