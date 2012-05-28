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
using namespace cv;
class Camera : public QThread
{
    Q_OBJECT

private :
    CvCapture *camera;
    IplImage *image;
    QImage img;
    QPixmap pm;

public :

    Camera();
    virtual void run();
    void connecter(int);

signals :
    virtual void emSig2(QImage);
};


#endif // CAMERA_H