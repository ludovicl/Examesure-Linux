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
#include <QMessageBox>
#include "sonde.h"
#include "etalonnage.h"
#include "camera.h"

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


private:
    ThreadAcquerir *tAcqu;
    Camera *cam;

    //    IplImage *image;//pour test
    //    CvCapture *camera;//pour test
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
