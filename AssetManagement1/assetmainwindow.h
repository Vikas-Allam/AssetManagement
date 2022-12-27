#ifndef ASSETMAINWINDOW_H
#define ASSETMAINWINDOW_H

#include <QMainWindow>
#include"AssetManagerInterface.h"
#include"assetmanagerinformation.h"
#include "assetrecord.h"
QT_BEGIN_NAMESPACE
namespace Ui { class AssetMainWindow; }
QT_END_NAMESPACE

class AssetMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    AssetMainWindow(QWidget *parent = nullptr);
   AssetMainWindow(AssetManagerinterface *p1);
    ~AssetMainWindow();

private slots:
    // QMap<int,QString> on_Save_clicked();



    void on_site_currentIndexChanged(int index);



    void on_View_clicked();



public slots:
          void Save();
          void Update();

private:

  std:: unique_ptr< Ui::AssetMainWindow> ui;
std::unique_ptr<AssetManagerinterface> ptr = std::unique_ptr<AssetManagerInformation>(new AssetManagerInformation);


        QMap<QString,QString>v;


};
#endif // ASSETMAINWINDOW_H
