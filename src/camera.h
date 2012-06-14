//---------------------------------------------------------
//NOM : camera.h

//UTILITE : Gérer la webcam
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H

#include <QtGui>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <QImage>
#include <QPixmap>
#include "config.h"
#include <time.h>
using namespace cv;
class Camera : public QThread
{
    Q_OBJECT

private :

    IplImage *image;
    QImage img;
    QPixmap pm;
    int idcam;
    static  int nbObCam;
    static  CvCapture *capture;

public :

    ~Camera();
    void enregistrer(string);
    Camera();
    void liberer();
    virtual void run();
    //    virtual void terminate();
    bool connecter(int id);


signals :
    virtual void emSig2(QImage);
};


#endif // CAMERA_H
