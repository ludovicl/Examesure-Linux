//---------------------------------------------------------
//NOM : config.h

//UTILITE : Fichier de l'ui de la configuration généré par QT Creator
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#ifndef CONFIG_H
#define CONFIG_H
#include <QFileDialog>
#include <iostream>
using namespace std;
#include <QMessageBox>
#include <QWidget>
#include <fstream>
#include <QAbstractButton>
#include <QMessageBox>

using namespace std;
namespace Ui {
class Config;
}

class Config : public QWidget
{
    Q_OBJECT
    
public:
    explicit Config(QWidget *parent = 0);
    ~Config();
    
private slots:
    void on_toolButton_clicked();
    void on_pushValider_clicked();
    void on_pushAnnuler_clicked();

private:

    int idcam, indexVitesse;
    string lienPhotos, baudFour;//baud = vitesse du four
    QString adressFour;
    string checkBoxCam;
    float coefExt1, coefExt2, coefExt3, coefRef1, coefRef2, coefRef3, stab;

    Ui::Config *ui;
};

#endif // CONFIG_H
