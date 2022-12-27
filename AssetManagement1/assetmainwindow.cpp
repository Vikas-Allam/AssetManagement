#include "assetmainwindow.h"
#include "./ui_assetmainwindow.h"
#include<QFileDialog>
#include "assetrecord.h"
AssetMainWindow::AssetMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AssetMainWindow)
{
    ui->setupUi(this);
    connect(ui->Save,SIGNAL(clicked()),this,SLOT(Save()));
    connect(ui->Upload,SIGNAL(clicked()),this,SLOT(Update()));
ui->centralwidget->activateWindow();
    QPixmap pic(":/image/default.png");
    ui->Image->setPixmap(pic);
     v.insert("imagedata",":/image/default.png");
}


AssetMainWindow::~AssetMainWindow()
{
   // delete ui;
}

void AssetMainWindow::Save()
{
qDebug()<<"one";


   v.insert("AssetName",ui->lineEdit->text());

   v.insert("AssetType",ui->lineEdit_2->text());

   v.insert("Description",ui->lineEdit_3->text());

   v.insert("SerialNumber",ui->lineEdit_4->text());


   v.insert("Manufacturer",ui->lineEdit_5->text());

   v.insert("Model",ui->lineEdit_6->text());

   v.insert("Owner",ui->lineEdit_7->text());

  v.insert("Condition",ui->comboBox->currentText());

  v.insert("Site",ui->site->currentText());




 ptr->Savedata(v);



}


void AssetMainWindow::on_site_currentIndexChanged(int index)
{
    if(index==1)
    {

        QString hyd="Address: Office# 203,2nd Floor Rockdale Compound,  Diamond Block ,Somajiguda,  Hyderabad, Telangana- 500082";


            ui->textEdit->setPlainText(hyd);
          ui->textEdit->setReadOnly(true);
          v.insert("Location",hyd);



    }
    if(index==2)
    {


        QString Pune="Address: Tower S4, Magarpatta City To Koregaon Park, Back Side Road Cybercity, Magarpatta, HadapsarPune, Maharashtra - 411028";
                ui->textEdit->setPlainText(Pune);
                ui->textEdit->setReadOnly(true);
        v.insert("Location",Pune);


    }

}
void AssetMainWindow::Update()
{ qDebug()<<"ok";
    QString temp= QFileDialog::getOpenFileName(this,
                                             tr("Open Image"), "D:/", tr("Image Files (*.png *.jpg *.bmp)"));
    qDebug()<<temp;

    QPixmap pic(temp);
    ui->Image->setPixmap(pic);
    v.insert("imagedata",temp);

}




void AssetMainWindow::on_View_clicked()
{

    AssetRecord *p;
    p=new AssetRecord();
   p->tabledata();
    p->show();
}



