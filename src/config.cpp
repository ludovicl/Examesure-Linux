//---------------------------------------------------------
//NOM : config.cpp

//UTILITE : Fichier de l'ui de la configuration généré par QT Creator
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#include "config.h"
#include "ui_config.h"
int combocam;
Config::Config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Config)
{
    cout<<"Configuration crée !"<<endl;
    ui->setupUi(this);

    ifstream fichier(".examesure.cfg");

    if(fichier)// si le fichier existe
    {
        fichier.close();
    }
    else
    {
        system("touch .examesure.cfg");// créer le fichier
        ofstream fichier(".examesure.cfg", ios::app);

        fichier<<"adressefour "<<ui->spinAddr->text().toStdString()<<endl;
        fichier<<"vitessefour "<<ui->comboVitesses->currentText().toStdString()<<endl;
        fichier<<"webcam "<<ui->comboWebcam->currentIndex()<<endl;
        fichier<<"lienphoto "<<ui->labelLien->text().toStdString()<<endl;
        fichier<<"checkbox "<<ui->checkBox->isChecked()<<endl;
        fichier<<"stabilite "<<ui->spinAddr->text().toStdString()<<endl;
        fichier<<"refcoef1 "<<ui->spinCoefRef1->text().toStdString()<<endl;
        fichier<<"refcoef2 "<<ui->spinCoefRef2->text().toStdString()<<endl;
        fichier<<"refcoef3 "<<ui->spinCoefRef3->text().toStdString()<<endl;
        fichier<<"extcoef1 "<<ui->spinCoefExt1->text().toStdString()<<endl;
        fichier<<"extcoef2 "<<ui->spinCoefExt2->text().toStdString()<<endl;
        fichier<<"extcoef3 "<<ui->spinCoefExt3->text().toStdString()<<endl;
        fichier.close();  // fermer le fichier
    }



}

Config::~Config()
{

    delete ui;
}

void Config::on_toolButton_clicked()
{

    QFileDialog *dialog=new QFileDialog;

    dialog->setFileMode(QFileDialog::DirectoryOnly);
    connect(dialog,SIGNAL(fileSelected( QString  )),ui->labelLien,SLOT(setText(QString)));
    dialog->exec();
}

void Config::on_pushValider_clicked()
{


    ofstream fichier(".examesure.cfg", ios::out | ios::trunc);

    fichier<<"adressefour "<<ui->spinAddr->text().toStdString()<<endl;
    fichier<<"vitessefour "<<ui->comboVitesses->currentText().toStdString()<<endl;
    fichier<<"webcam "<<ui->comboWebcam->currentIndex()<<endl;
    fichier<<"lienphoto "<<ui->labelLien->text().toStdString()<<endl;
    fichier<<"checkbox "<<ui->checkBox->isChecked()<<endl;
    fichier<<"stabilite "<<ui->spinAddr->text().toStdString()<<endl;
    fichier<<"refcoef1 "<<ui->spinCoefRef1->text().toStdString()<<endl;
    fichier<<"refcoef2 "<<ui->spinCoefRef2->text().toStdString()<<endl;
    fichier<<"refcoef3 "<<ui->spinCoefRef3->text().toStdString()<<endl;
    fichier<<"extcoef1 "<<ui->spinCoefExt1->text().toStdString()<<endl;
    fichier<<"extcoef2 "<<ui->spinCoefExt2->text().toStdString()<<endl;
    fichier<<"extcoef3 "<<ui->spinCoefExt3->text().toStdString()<<endl;
    fichier.close();  // fermer le fichier



    qApp->exit(1);
}

void Config::on_pushAnnuler_clicked()
{

}
