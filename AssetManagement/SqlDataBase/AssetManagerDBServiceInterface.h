#pragma once
//#ifndef ASSETMANAGERDBSERVICEINTERFACE_H
//#define ASSETMANAGERDBSERVICEINTERFACE_H
#include<iostream>
#include<QString>
  class AssetManagerDBServiceInterface
{
  public:


      virtual bool getMap(QMap<QString,QString>)=0;


   virtual bool  isOpen() const=0;
     virtual bool createTable()=0;
  virtual bool  removeAllData()=0;
    virtual   bool IsDBConnected()=0;
    virtual    bool IsDataAdded()=0;
  };
