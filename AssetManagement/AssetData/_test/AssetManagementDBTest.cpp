#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include"assetmanagerdbservice.h"
#include"assetmanagerinformation.h"
#include"assetrecord.h"
QMap<QString,QString>map;


TEST(AssetDBServiceTest, WhenDBIsConnectedThenISDBConnectionFunctionReturnTrue)
{
   const bool expectedDBConnection = true;

   AssetManagerDBService ptr=new AssetManagerDBService(expectedDBConnection);


   EXPECT_EQ(expectedDBConnection, ptr.IsDBConnected());
}



TEST(AssetDBServiceTest,WhenDBCreatedisOpenReturnTrue)

{
    const bool expectedDBConnection = true;
    AssetManagerDBService *ptr= AssetManagerDBService::CreateInstance();

        EXPECT_EQ(expectedDBConnection,ptr->isOpen());

}

TEST(AssetDBServiceTest,WhenDBTableCreatedCreateTableReturnTrue)

{
    const bool expectedDBConnection = false;
    AssetManagerDBService *ptr= AssetManagerDBService::CreateInstance();

        EXPECT_EQ(expectedDBConnection,ptr->createTable());

}
//TEST(AssetDBServiceTest,WhenDataAddedToDBIsDataAddedReturnTrue)

//{
//    const bool expectedDBConnection = true;
//    AssetManagerInformation *p=new AssetManagerInformation();

//        EXPECT_EQ(expectedDBConnection,p->IsDataAdded());

//}
TEST(AssetDBServiceTest,WhenDataRecievedToAssetInformationIsDataAddedReturnTrue)

{
     bool expectedDBConnection=true;
      AssetManagerInformation *p=new AssetManagerInformation();
      QString AssetName ="Nokia";
      qDebug()<<AssetName;

        EXPECT_EQ(true,p->Getdata(AssetName));

}

TEST(AssetDBServiceTest,WhenDataToAssetInformationIsDataAddedReturnTrue)

{
     bool expectedDBConnection=true;

     QMap<QString,QString>map;
map.insert("AssetName","Nokia");

map.insert("AssetType","Mobile");

map.insert("Description","None");

map.insert("SerialNumber","N2132");


map.insert("Manufacturer","Nokia");

map.insert("Model","Nokia7632");

map.insert("Owner","Vikas");

map.insert("Condition","good");

map.insert("Site","Hyederabad");
map.insert("Location","Hyederabad");
map.insert("imagedata",":/Images/default.png");
AssetManagerInformation *p=new AssetManagerInformation();
   EXPECT_EQ(expectedDBConnection,p->Savedata(map));
   EXPECT_EQ(map["AssetName"].toLatin1(),p->AssetName().toLatin1());
   EXPECT_EQ(map["AssetType"],p->AssetType());
   EXPECT_EQ(map["Description"],p->Description());
   EXPECT_EQ(map["SerialNumber"],p->SerialNumber());
   EXPECT_EQ(map["Manufacturer"],p->Manufacturer());
   EXPECT_EQ(map["Model"],p->Model());
   EXPECT_EQ(map["Owner"],p->Owner());
   EXPECT_EQ(map["Condition"],p->Condition());
      EXPECT_EQ(map["Location"],p->Location());
      EXPECT_EQ(map["imagedata"],p->imagedata());


   EXPECT_EQ(map["Site"],p->Site());
   AssetManagerDBService *ptr= AssetManagerDBService::CreateInstance();

       EXPECT_EQ(expectedDBConnection,ptr->IsDataAdded());



}
