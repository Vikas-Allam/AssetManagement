#include "assetmanagerinformation.h"
#include<QDebug>
#include"assetmainwindow.h"
#include"AssetManagerDBServiceInterface.h"
#include"assetmanagerdbservice.h"
#include<QSqlRecord>
#include<QSqlQuery>
 std::unique_ptr<AssetManagerDBServiceInterface> ptrDB = std::unique_ptr<AssetManagerDBService>(AssetManagerDBService::CreateInstance());
AssetManagerInformation::AssetManagerInformation()
{




}



QString AssetManagerInformation::AssetName( )
{


  return var["AssetName"];

}

QString AssetManagerInformation::AssetType( )
{
    return var["AssetType"];
}

QString AssetManagerInformation::Description( )
{
  return var["Description"];
}

QString AssetManagerInformation::SerialNumber()
{

    return var["SerialNumber"];
}

QString AssetManagerInformation::Manufacturer()
{

  return var["Manufacturer"];
}

QString AssetManagerInformation::Model()
{
    return var["Model"];

}

QString AssetManagerInformation::Owner()
{

    return var["Owner"];

}

QString AssetManagerInformation::Condition()
{

    return var["Condition"];

}

QString AssetManagerInformation::Site()
{

    return var["Site"];
}

QString AssetManagerInformation::Location()
{
 return var["Location"];
}

QString AssetManagerInformation::imagedata()
{
    return var["imagedata"];
}



bool AssetManagerInformation::Savedata(QMap<QString, QString> data)
{
    var=data;
      success=ptrDB->getMap(var);
    if(var.empty()==0)
        return true;


   if(success==true)
   {
       qDebug()<<"Data Added Successfully";
   DataReceived=true;

}
}
bool AssetManagerInformation::IsDataAdded()
{
    qDebug()<<"information:"<<DataReceived;
    return DataReceived;
}


bool AssetManagerInformation::Getdata(QString AssetName)
{
    qDebug()<<AssetName;
    AssetManagerDBService ptr=AssetManagerDBService::CreateInstance();
    QString data;


data=ptr.ParticularData();
qDebug()<<data;
if(data==AssetName)
    return true;
//for ( int i = 0; i < 10; i++ ) {

//   qDebug() << *(data + i);
//   if(*(data + i)==AssetName)
//   {
//       return true;
//   }
}




