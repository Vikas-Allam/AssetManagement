#include "assetmanagerinformation.h"
#include<QDebug>
#include"assetmainwindow.h"
#include<QSqlRecord>
#include<QSqlQuery>
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

//void AssetManagerInformation::Getdata()
//{
//    ptr->db.open();
//    QSqlQuery *query=new QSqlQuery(ptr->db);
//           query->prepare("select * from AssetInformation");
//  query->exec();
//           model->setQuery (*query);
//           while (query->next())
//           {




//           }
//             ptr->db.close();
//         }

void AssetManagerInformation::Savedata(QMap<QString, QString> data)
{


    qDebug()<<"save";
    var=data;

 bool success= ptrDB->getMap(var);
   if(success==true)
       qDebug()<<"Data Added Successfully";

}

