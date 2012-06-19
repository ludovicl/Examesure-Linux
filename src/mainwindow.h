//---------------------------------------------------------
//NOM : mainwindows.h

//UTILITE : Fichier de l'ui de défnition des consignes généré par QT Creator
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
//#include "sonde.h"
#include "etalonnage.h"
#include "camera.h"
#include "config.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_demarrer_clicked();

    void afficheCam(QImage);

    void prendrePhoto();

    void on_actionConfiguration_avanc_e_triggered();

    void on_pushButton_clicked();

private:
    ThreadAcquerir *tAcqu;
    int idcam,indexVitesse;
    Sonde *sdRef, *sdExt, *sdInt;
    string lienPhotos, baudFour;//baud = vitesse du four
    QString adressFour;
    string checkBoxCam;
    float coefExt1, coefExt2, coefExt3, coefRef1, coefRef2, coefRef3, stab;
    Camera *cam;
    Config *conf;
    Etalonnage *et;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
