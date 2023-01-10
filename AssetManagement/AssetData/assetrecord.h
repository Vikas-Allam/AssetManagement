//#ifndef ASSETRECORD_H
//#define ASSETRECORD_H
#pragma once

#include <QDialog>
#include"assetreport.h"
#include<QSqlQueryModel>

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


    QSqlQueryModel *model=new QSqlQueryModel();

};

//#endif // ASSETRECORD_H
