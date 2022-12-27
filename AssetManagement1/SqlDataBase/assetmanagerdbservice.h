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
    public:
         QSqlDatabase db;
      static AssetManagerDBService *CreateInstance();

     bool getMap(QMap<QString,QString>);

   bool  isOpen() const;
    bool createTable(const QString&);
  bool  removeAllData();
 bool DataExists(const QString &emp) const;
};


