//---------------------------------------------------------
//NOM : mainwindows.cpp

//UTILITE : Fichier de l'ui de défnition des consignes généré par QT Creator
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#include "mainwindow.h"
#include "ui_config.h"
#include "ui_mainwindow.h"
#include "config.h"
#include "ui_config.h"
extern int combocam;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conf = new Config();
    cam= new Camera();

    Rs232 *rs=Rs232::getInstance ();

    tAcqu=new ThreadAcquerir("interne");

    tAcqu->start();
    cout<<"Application lancée"<<endl;

    connect(tAcqu,SIGNAL(emSig(QString)),ui->labelTempInt,SLOT(setText(QString)));



    idcam=combocam;


    cout<<"Combocam :"<<combocam<<endl;
    if(idcam!=0)
    {
        cam->connecter(-1);
        cam->start();
        connect(cam,SIGNAL(emSig2(QImage)),this,SLOT(afficheCam(QImage)));
    }


}



void MainWindow::afficheCam(QImage image)
{
    ui->labelCam->setPixmap(QPixmap::fromImage(image));
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_demarrer_clicked()
{
    QMessageBox box;

    if((ui->spinMaxi->text().toFloat())<(ui->spinMini->text().toFloat()))
    {
        box.setText("LA TEMPERATURE MAXIMUM DOIT ETRE SUPERIEUR A LA TEMPERATURE MINIMUM...");
        box.exec();
        return;
    }


    if((ui->spinInter->text().toFloat())>(ui->spinMaxi->text().toFloat()))
    {
        box.setText("L'INTERVALLE NE PEUT PAS ETRE SUPERIEUR A LA TEMPERATURE MAXIMUM...");
        box.exec();
        return;
    }

    if(((ui->spinInter->text().toFloat())==0 && ui->spinMaxi->text().toFloat())==0 &&  (ui->spinMini->text().toFloat())==0)
    {
        box.setText("IL FAUT RENTRER DES VALEURS ");
        box.exec();
        return;
    }

    if((ui->spinInter->text().toFloat())==0)
    {
        box.setText("L'INTERVALLE NE PEUT PAS ETRE DE ZERO... ><' ");
        box.exec();
        return;
    }


    Etalonnage *et;
    et = new Etalonnage();

    et->set_intervalle(ui->spinInter->text().toFloat());

    et->set_tempMax(ui->spinMaxi->text().toFloat());

    et->set_tempMini(ui->spinMini->text().toFloat());

    et->remplir_tabTemp();

    vector<float>vec=et->get_tabTemp();


    ui->tableWidget->setRowCount( vec.size());
    for(int i = 0; i < (vec.size()); i++)
    {
        QString str = QString::number(vec.at(i));

        QTableWidgetItem *newItem = new QTableWidgetItem;
        newItem->setText(str);

        ui->tableWidget->setItem(i, 0, newItem);
    }
    et->start();
    connect(et,SIGNAL(emSigCons(QString)),ui->labelConsigne,SLOT(setText(QString)));
}


void MainWindow::on_actionConfiguration_avanc_e_triggered()
{

    conf->show();
}



