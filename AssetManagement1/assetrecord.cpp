#include "assetrecord.h"
#include "ui_assetrecord.h"
#include<QSqlQuery>
#include<QSqlRecord>
#include<QSqlQueryModel>
#include<QMessageBox>
#include<QStandardItem>
AssetRecord::AssetRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AssetRecord)
{
    ui->setupUi(this);



}



void AssetRecord::tabledata()
{
    qDebug()<<"coming";








       ptr->db.open();
       QSqlQuery *query=new QSqlQuery(ptr->db);
              query->prepare("select * from AssetInformation");
     query->exec();

              model->setQuery (*query);

               ui->tableView->setModel(model);
                ptr->db.close();




}


void AssetRecord::on_pushButton_clicked()
{
    int rows = model->rowCount();
    int columns=model->columnCount();
  int ind=ui->tableView->selectionModel()->currentIndex().row();
    QString number[100] ;


       for (int i = 0; i < columns; i++)
       {

              number [i]= ui->tableView->model()->data(ui->tableView->model()->index(ind,i)).toString();
       }



    std::unique_ptr<AssetReport>p(new AssetReport());

   if( p->printData(columns,number)==true)
   {
         QMessageBox::information(this,"Alert","Data Printed Successfully");
   }

}

