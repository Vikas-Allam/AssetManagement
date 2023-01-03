#ifndef ASSETRECORD_H
#define ASSETRECORD_H
#include"SqlDataBase/AssetManagerDBServiceInterface.h"
#include"SqlDataBase/assetmanagerdbservice.h"
#include <QDialog>
#include<assetreport.h>
#include<QSqlQueryModel>

#include"assetmanagerinformation.h"
namespace Ui {
class AssetRecord;
}

class AssetRecord : public QDialog
{
    Q_OBJECT

public:
    explicit AssetRecord(QWidget *parent = nullptr);
    AssetRecord(QMap<QString,QString> data);
   // ~AssetRecord();
       void tabledata();


private slots:
       void on_pushButton_clicked();

private:
   Ui::AssetRecord *ui;
   // std:: unique_ptr< Ui::AssetRecord> ui;
    std::unique_ptr<AssetManagerDBService> ptr = std::unique_ptr<AssetManagerDBService>(AssetManagerDBService::CreateInstance());
// std::unique_ptr<AssetManagerinterface> inptr = std::unique_ptr<AssetManagerInformation>(new AssetManagerInformation);
    QSqlQueryModel *model=new QSqlQueryModel();

};

#endif // ASSETRECORD_H
