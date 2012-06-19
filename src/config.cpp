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

    


    /*---------------Lecture du fichier de configuration si il existe----------------------------------*/
   
    ifstream fichierConf(".examesure.cfg");//ouvre le fichier en lecture
    if(fichierConf)// si le fichier existe
    {
        string contenuFichier;
        fichierConf>>contenuFichier>>contenuFichier;
        adressFour=QString::fromStdString ( contenuFichier);
        
        
        
        fichierConf>>contenuFichier>>contenuFichier;
        baudFour=contenuFichier;
        fichierConf>>contenuFichier>>contenuFichier;
        indexVitesse=atoi(contenuFichier.c_str());
        fichierConf>>contenuFichier>>contenuFichier;
        idcam = atoi(contenuFichier.c_str());//convertir string en int
        fichierConf>>contenuFichier>>contenuFichier;
        lienPhotos=contenuFichier;
        fichierConf>>contenuFichier>>contenuFichier;
        checkBoxCam=contenuFichier;
        fichierConf>>contenuFichier>>contenuFichier;
        stab=atof(contenuFichier.c_str());
        fichierConf>>contenuFichier>>contenuFichier;
        coefRef1=atof(contenuFichier.c_str());
        fichierConf>>contenuFichier>>contenuFichier;
        coefRef2=atof(contenuFichier.c_str());
        fichierConf>>contenuFichier>>contenuFichier;
        coefRef3=atof(contenuFichier.c_str());
        fichierConf>>contenuFichier>>contenuFichier;
        coefExt1=atof(contenuFichier.c_str());
        fichierConf>>contenuFichier>>contenuFichier;
        coefExt2=atof(contenuFichier.c_str());
        fichierConf>>contenuFichier>>contenuFichier;
        coefExt3=atof(contenuFichier.c_str());
        fichierConf.close();

        cout<<"Check box de config : "<<checkBoxCam<<endl;

        if(checkBoxCam=="1")
        {
            cout<<"checkbox est check !"<<endl;
            ui->checkBox->setChecked(true);
        }
        if(checkBoxCam=="0")
            ui->checkBox->setChecked(false);

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

    }
    else
    {
        system("touch .examesure.cfg");// créer le fichier
        QMessageBox box;
        box.setText("1er utilisation : veuilliez initialiser la configuration ");
        box.exec();

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

    ofstream fichierConf(".examesure.cfg", ios::out | ios::trunc);//ouvre le fichier en eciture
    fichierConf<<"adressefour "<<ui->spinAddr->text().toStdString()<<endl;
    
    
    
    fichierConf<<"vitessefour "<<ui->comboVitesses->currentText().toStdString()<<endl;
    fichierConf<<"indexVitesse "<<ui->comboVitesses->currentIndex()<<endl;
    fichierConf<<"webcam "<<ui->comboWebcam->currentIndex()<<endl;
    fichierConf<<"lienphoto "<<ui->labelLien->text().toStdString()<<endl;
    fichierConf<<"checkbox "<<ui->checkBox->isChecked()<<endl;
    fichierConf<<"stabilite "<<ui->spinStab->text().toStdString()<<endl;
    fichierConf<<"refcoef1 "<<ui->spinCoefRef1->text().toStdString()<<endl;
    fichierConf<<"refcoef2 "<<ui->spinCoefRef2->text().toStdString()<<endl;
    fichierConf<<"refcoef3 "<<ui->spinCoefRef3->text().toStdString()<<endl;
    fichierConf<<"extcoef1 "<<ui->spinCoefExt1->text().toStdString()<<endl;
    fichierConf<<"extcoef2 "<<ui->spinCoefExt2->text().toStdString()<<endl;
    fichierConf<<"extcoef3 "<<ui->spinCoefExt3->text().toStdString()<<endl;
    fichierConf.close();  // fermer le fichier

    qApp->exit(1);
}

void Config::on_pushAnnuler_clicked()
{
    Config::close();
}
