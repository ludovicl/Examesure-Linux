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

#include "ui_config.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conf = new Config();

    cam= new Camera();

   ifstream fichier(".examesure.cfg", ios::in);  // on ouvre le fichier en lecture


    /*------------------------Lecteur dans le fichier de configuration -------------------------------- */
    if(fichier)  // si l'ouverture a réussi
    {

        string contenuFichier;  // string qui contiendra la ligne lue

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
        checkBoxCam=contenuFichier;
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

        cout<<"idcam :"<<idcam<<endl;
        cout<<"index Vitesse :"<<indexVitesse<<endl;
        cout<<"lien photos : "<<lienPhotos<<endl;
        cout<<"checkbox : "<<checkBoxCam<<endl;
        cout<<"adresse du four : "<<adressFour.toStdString()<<endl;
        cout<<"vitesse du four : "<<baudFour<<endl;
        cout<<"stabilité : "<<stab<<endl;
        cout<<"coefficient reference 1 : "<<coefRef1<<endl;
        cout<<"coefficient reference 2 : "<<coefRef2<<endl;
        cout<<"coefficient reference 3 : "<<coefRef3<<endl;
        cout<<"coefficient externe 1 : "<<coefExt1<<endl;
        cout<<"coefficient externe 2 : "<<coefExt2<<endl;
        cout<<"coefficient externe 3 : "<<coefExt3<<endl;

        fichier.close();  // on ferme le fichier
    }
    else
    {
        cerr << "Probléme pendant la lecture du fichier de la configuration" << endl;
    }
    /*----------------------------------------------------------------------------------------------- */


    Rs232 *rs=Rs232::getInstance (adressFour, baudFour);

    tAcqu=new ThreadAcquerir("interne");

    tAcqu->start();
    cout<<"Application lancée"<<endl;

    connect(tAcqu,SIGNAL(emSig(QString)),ui->labelTempInt,SLOT(setText(QString)));

    cout<<"checkboxCAMMM : "<<checkBoxCam<<endl;

    if((checkBoxCam=="1")&&(idcam==0))
    {
        QMessageBox box;
        box.setText("Les photos ne seront pas enregistrees ");
        box.exec();
//        return;
    }


    if (checkBoxCam=="0")
    {
        QMessageBox box;
        box.setText("Les photos ne seront pas enregistrees ");
        box.exec();
    }

    if((idcam!=0)&&(cam->connecter(idcam-1)==0))//si une camera est séléctioné et la camera bien connéecté
    {
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
    if (cam->isRunning())
    {
        cam->terminate();//terminer le thread de la webcam;
        cout<<"cam delete !"<<endl;

    }
    if(Camera::nbObCam >=1)
    delete cam;
//    delete conf;
    delete ui;
}

void MainWindow::on_demarrer_clicked()
{

    if((ui->spinMaxi->text().toFloat())<(ui->spinMini->text().toFloat()))
    {
        QMessageBox box;
        box.setText("LA TEMPERATURE MAXIMUM DOIT ETRE SUPERIEUR A LA TEMPERATURE MINIMUM...");
        box.exec();
        return;
    }

    if((ui->spinInter->text().toFloat())>(ui->spinMaxi->text().toFloat()-ui->spinMini->text().toFloat()))
    {
        QMessageBox box;
        box.setText("L'INTERVALLE NE PEUT PAS ETRE SUPERIEUR A LA TEMPERATURE MAXIMUM...");
        box.exec();
        return;
    }

//    if(((ui->spinInter->text().toFloat())==0 && ui->spinMaxi->text().toFloat())==0 &&  (ui->spinMini->text().toFloat())==0)
//    {
//        QMessageBox box;
//        box.setText("IL FAUT RENTRER DES VALEURS ");
//        box.exec();
//        return;
//    }

    if((ui->spinInter->text().toFloat())==0)
    {
        QMessageBox box;
        box.setText("L'INTERVALLE NE PEUT PAS ETRE DE ZERO");
        box.exec();
        return;
    }

    if (Sonde::nbObjSonde>3)// pour ne pas instancier plus d'objets que necessaire
    {
        delete sdRef;
        delete sdInt;
        delete sdExt;
        cout<<"c'est delete !"<<endl;
    }

    if(Etalonnage::nbObjEtalonnage>1)
    {
          delete et;
    }

    sdRef = new Sonde("reference", coefRef1, coefRef2, coefRef3);
    sdExt = new Sonde("externe", coefExt1, coefExt2, coefExt3);
    sdInt=new Sonde("interne");
    cout<<"Nombre d'objet sonde :"<<Sonde::nbObjSonde<<endl;

    et = new Etalonnage(stab, *sdRef, *sdExt, *sdInt, checkBoxCam, lienPhotos, idcam);

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

    connect(et,SIGNAL(emSigPrendPhoto()),this,SLOT(prendrePhoto()));
}

void MainWindow::prendrePhoto()
{
    if((idcam!=0) &&(checkBoxCam=="1"))
    {
        cam->enregistrer(lienPhotos);
        cout<<"enregistrer ok !"<<endl;
    }
}

void MainWindow::on_actionConfiguration_avanc_e_triggered()
{

    conf->show();
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::close();
}
