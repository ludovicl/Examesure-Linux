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


    /*---------------Lecture du fichier de configuration si il existe----------------------------------*/
    if(fichier)// si le fichier existe
    {
        string contenuFichier;

        fichier>>contenuFichier>>contenuFichier;
        adressFour=QString::fromStdString ( contenuFichier);
        fichier>>contenuFichier>>contenuFichier;
        baudFour=contenuFichier;
        fichier>>contenuFichier>>contenuFichier;
        indexVitesse=atoi(contenuFichier.c_str());
        fichier>>contenuFichier>>contenuFichier;
        idcam = atoi(contenuFichier.c_str());//convertir string en int
        fichier>>contenuFichier>>contenuFichier;
        lienPhotos=contenuFichier;
        fichier>>contenuFichier>>contenuFichier;
        checkBoxCam=contenuFichier.c_str();
        fichier>>contenuFichier>>contenuFichier;
        stab=atof(contenuFichier.c_str());
        fichier>>contenuFichier>>contenuFichier;
        coefRef1=atof(contenuFichier.c_str());
        fichier>>contenuFichier>>contenuFichier;
        coefRef2=atof(contenuFichier.c_str());
        fichier>>contenuFichier>>contenuFichier;
        coefRef3=atof(contenuFichier.c_str());
        fichier>>contenuFichier>>contenuFichier;
        coefExt1=atof(contenuFichier.c_str());
        fichier>>contenuFichier>>contenuFichier;
        coefExt2=atof(contenuFichier.c_str());
        fichier>>contenuFichier>>contenuFichier;
        coefExt3=atof(contenuFichier.c_str());
        fichier.close();


        /*-----------On definie la fenêtre config en fonction du fichier de configuration----*/
        ui->comboWebcam->setCurrentIndex(idcam);
        ui->labelLien->setText(QString(lienPhotos.c_str()));
        ui->spinAddr->setValue(adressFour.toInt());
        ui->comboVitesses->setCurrentIndex(indexVitesse);
        ui->spinStab->setValue(stab);
        ui->spinCoefExt1->setValue(coefExt1);
        ui->spinCoefExt2->setValue(coefExt2);
        ui->spinCoefExt3->setValue(coefExt3);
        ui->spinCoefRef1->setValue(coefRef1);
        ui->spinCoefRef2->setValue(coefRef2);
        ui->spinCoefRef3->setValue(coefRef3);
        /*-----------FIN On definie la fenêtre config en fonction du fichier de configuration----*/

        cout<<"contenue checkbox : "<<checkBoxCam<<endl;

        /*-----Le checkbox ne fonctionne pas------- */
        //        if(checkBoxCam==true)
        //        {
        //            cout<<"checkbox est check !"<<endl;
        //            ui->checkBox->setChecked(true);
        //        }
        //        else
        //            ui->checkBox->setChecked(false);
        /*-----FIN Le checkbox ne fonctionne pas------- */
    }
    else
    {
        /*-------Creation du fichier de config et écriture de la configuration par defaut-----*/
        system("touch .examesure.cfg");// créer le fichier
        ofstream fichier(".examesure.cfg", ios::app);

        fichier<<"adressefour "<<ui->spinAddr->text().toStdString()<<endl;
        fichier<<"vitessefour "<<ui->comboVitesses->currentText().toStdString()<<endl;
        fichier<<"indexVitesse "<<ui->comboVitesses->currentIndex()<<endl;
        fichier<<"webcam "<<ui->comboWebcam->currentIndex()<<endl;
        fichier<<"lienphoto "<<ui->labelLien->text().toStdString()<<endl;
        fichier<<"checkbox "<<ui->checkBox->isChecked()<<endl;
        fichier<<"stabilite "<<ui->spinStab->text().toStdString()<<endl;
        fichier<<"refcoef1 "<<ui->spinCoefRef1->text().toStdString()<<endl;
        fichier<<"refcoef2 "<<ui->spinCoefRef2->text().toStdString()<<endl;
        fichier<<"refcoef3 "<<ui->spinCoefRef3->text().toStdString()<<endl;
        fichier<<"extcoef1 "<<ui->spinCoefExt1->text().toStdString()<<endl;
        fichier<<"extcoef2 "<<ui->spinCoefExt2->text().toStdString()<<endl;
        fichier<<"extcoef3 "<<ui->spinCoefExt3->text().toStdString()<<endl;

        fichier.close();  // fermer le fichier
        /*-------Creation du fichier de config et écriture des données par defaut-----*/
    }
}
/*---------------FIN Lecture du fichier de configuration si il existe----------------------------------*/

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
    QMessageBox box;

    ofstream fichier(".examesure.cfg", ios::out | ios::trunc);

    fichier<<"adressefour "<<ui->spinAddr->text().toStdString()<<endl;
    fichier<<"vitessefour "<<ui->comboVitesses->currentText().toStdString()<<endl;
    fichier<<"indexVitesse "<<ui->comboVitesses->currentIndex()<<endl;
    fichier<<"webcam "<<ui->comboWebcam->currentIndex()<<endl;
    fichier<<"lienphoto "<<ui->labelLien->text().toStdString()<<endl;
    fichier<<"checkbox "<<ui->checkBox->isChecked()<<endl;
    fichier<<"stabilite "<<ui->spinStab->text().toStdString()<<endl;
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
    Config::close();
}
