#ifndef ASSETMANAGERINTERFACE_H
#define ASSETMANAGERINTERFACE_H

#include<iostream>
#include<QString>
class AssetManagerinterface
{
public:
    virtual QString AssetName()=0;
    virtual QString AssetType()=0;
    virtual QString Description()=0;
    virtual QString SerialNumber()=0;
    virtual QString Manufacturer()=0;
    virtual QString Model()=0;
    virtual QString Owner()=0;
    virtual QString Condition()=0;
    virtual QString Site()=0;
    virtual QString Location()=0;
    virtual QString imagedata()=0;
    //virtual void Getdata()=0;
    virtual void Savedata(QMap<QString,QString>)=0;
};

#endif // ASSETMANAGERINTERFACE_H
