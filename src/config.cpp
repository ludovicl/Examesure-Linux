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

    ofstream fichier(".examesure.cfg",ios::app);

    if(fichier)// si le fichier existe
    {
        fichier.close();
    }
    else
    {
        system("touch .examesure.cfg");// créer le fichier
        ofstream fichier(".examesure.cfg", ios::app);

        fichier<<"webcam "<<ui->comboWebcam->currentIndex()<<" finwebcam"<<endl;
        fichier<<"lienphoto "<<ui->labelLien->text().toStdString()<<" finlienphoto \r"<<endl;
        fichier<<"checkbox "<<ui->checkBox->isTristate()<<" fincheckbox"<<endl;
        fichier<<"adressefour "<<ui->spinAddr->text().toStdString()<<" finadressefour"<<endl;
        fichier<<"vitessefour "<<ui->comboVitesses->currentText().toStdString()<<" finvitessefour"<<endl;
        fichier<<"stabilite "<<ui->spinAddr->text().toStdString()<<" finstabilite"<<endl;
        fichier<<"refcoef1 "<<ui->spinCoefRef1->text().toStdString()<<" finrefcoef1"<<endl;
        fichier<<"refcoef2 "<<ui->spinCoefRef2->text().toStdString()<<" finrefcoef2"<<endl;
        fichier<<"refcoef3 "<<ui->spinCoefRef3->text().toStdString()<<" finrefcoef3"<<endl;
        fichier<<"extcoef1 "<<ui->spinCoefExt1->text().toStdString()<<" finextcoef1"<<endl;
        fichier<<"extcoef2 "<<ui->spinCoefExt2->text().toStdString()<<" finextcoef2"<<endl;
        fichier<<"extcoef3 "<<ui->spinCoefExt3->text().toStdString()<<" finextcoef3"<<endl;
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

    fichier<<"webcam "<<ui->comboWebcam->currentIndex()<<" finwebcam"<<endl;
    fichier<<"lienphoto "<<ui->labelLien->text().toStdString()<<" finlienphoto \r"<<endl;
    fichier<<"checkbox "<<ui->checkBox->isTristate()<<" fincheckbox"<<endl;
    fichier<<"adressefour "<<ui->spinAddr->text().toStdString()<<" finadressefour"<<endl;
    fichier<<"vitessefour "<<ui->comboVitesses->currentText().toStdString()<<" finvitessefour"<<endl;
    fichier<<"stabilite "<<ui->spinAddr->text().toStdString()<<" finstabilite"<<endl;
    fichier<<"refcoef1 "<<ui->spinCoefRef1->text().toStdString()<<" finrefcoef1"<<endl;
    fichier<<"refcoef2 "<<ui->spinCoefRef2->text().toStdString()<<" finrefcoef2"<<endl;
    fichier<<"refcoef3 "<<ui->spinCoefRef3->text().toStdString()<<" finrefcoef3"<<endl;
    fichier<<"extcoef1 "<<ui->spinCoefExt1->text().toStdString()<<" finextcoef1"<<endl;
    fichier<<"extcoef2 "<<ui->spinCoefExt2->text().toStdString()<<" finextcoef2"<<endl;
    fichier<<"extcoef3 "<<ui->spinCoefExt3->text().toStdString()<<" finextcoef3"<<endl;
    fichier.close();  // fermer le fichier



    qApp->exit(1);
}

void Config::on_pushAnnuler_clicked()
{

}
