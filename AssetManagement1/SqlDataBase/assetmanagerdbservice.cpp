
#include<QSqlQuery>
#include<qsqlrecord.h>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlRecord>
#include "assetmanagerdbservice.h"
AssetManagerDBService *AssetManagerDBService::single=nullptr;



AssetManagerDBService::AssetManagerDBService()
{
    createTable("DataBase");

}


AssetManagerDBService *AssetManagerDBService::CreateInstance()
{
  if(single==nullptr)
  {
      single=new AssetManagerDBService();
      return single;
  }
  else
  {
      return single;
  }
}


bool AssetManagerDBService::getMap(QMap<QString, QString> data)
{
                     bool success = false;

  map=data;
        AssetName=map["AssetName"];
        AssetType=map["AssetType"];
        Description=map["Description"];
        SerialNumber=map["SerialNumber"];
        Manufacturer=map["Manufacturer"];
        Model=map["Model"];
        Owner=map["Owner"];
        Condition=map["Condition"];
        Site=map["Site"];
        Location=map["Location"];
        imagedata=map["imagedata"];





                QSqlQuery queryAdd;

queryAdd.prepare("INSERT INTO AssetInformation (AssetName,AssetType,Description,SerialNumber,Manufacturer,Model,Owner,Condition,Site,Location,imagedata) VALUES (:AssetName,:AssetType,:Description,:SerialNumber,:Manufacturer,:Model,:Owner,:Condition,:Site,:Location,:imagedata)");

                           queryAdd.bindValue(":AssetName",AssetName);
                      queryAdd.bindValue(":AssetType",AssetType);
                     queryAdd.bindValue(":Description",Description);
                     queryAdd.bindValue(":SerialNumber",SerialNumber);
                     queryAdd.bindValue(":Manufacturer",Manufacturer);
                     queryAdd.bindValue(":Model",Model);
                     queryAdd.bindValue(":Owner",Owner);
                     queryAdd.bindValue(":Condition",Condition);
                     queryAdd.bindValue(":Site",Site);

                     queryAdd.bindValue(":Location",Location);
                    queryAdd.bindValue(":imagedata",imagedata);


          if(queryAdd.exec())
          {
              success = true;
          }
          else
          {
              qDebug() << "add AssetInformation failed: " << queryAdd.lastError();
          }
          return success;
}











bool AssetManagerDBService::createTable(const QString &path)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if(!db.open())
    {
        qDebug()<<"error"<<"\n";
    }
    else
    {
        qDebug()<<"ok"<<"\n";
    }

    bool success = false;

        QSqlQuery query;
             //  query.prepare("CREATE TABLE DataBase(EMPID TEXT,Name TEXT,Designation TEXT,DateOfBirth TEXT,Department TEXT,JoiningDate TEXT,ContactNumber TEXT,Skills TEXT,Address TEXT);");
  query.prepare("CREATE TABLE AssetInformation(AssetID INTEGER PRIMARY KEY, AssetName TEXT,AssetType TEXT,Description TEXT,SerialNumber TEXT,Manufacturer TEXT,Model TEXT,Owner TEXT,Condition TEXT,Site TEXT,Location TEXT, imagedata BLOB);");

        if (!query.exec())
        {
            qDebug() << "Couldn't create the table 'AssetInformation': one might already exist.";
            success = false;
        }

        return success;




}

bool AssetManagerDBService::isOpen() const
{
    return db.isOpen();
}



bool AssetManagerDBService::DataExists(const QString &emp) const
{
    bool exists = false;

    QSqlQuery checkQuery;
       checkQuery.prepare("SELECT EMPID FROM AssetInformation WHERE EMPID = (:EMPID)");

    checkQuery.bindValue(":EMPID",emp);


    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;

        }
    }
    else
    {
        qDebug() << "DATA exists failed: " << checkQuery.lastError();
        return 0;
    }
 qDebug()<<exists;

  return exists;
}



bool AssetManagerDBService::removeAllData()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM AssetInformation");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all Data failed: " << removeQuery.lastError();
    }

    return success;
}
