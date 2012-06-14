//---------------------------------------------------------
//NOM : camera.cpp

//UTILITE : Gérer la webcam
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#include "camera.h"
int Camera::nbObCam;
CvCapture *Camera::capture;
static QImage IplImage2QImage(const IplImage *iplImage)//fonction pour convertir IplImage* en QImage
{
    int height = iplImage->height;
    int width = iplImage->width;
    if (iplImage->depth == IPL_DEPTH_8U && iplImage->nChannels == 3)
    {
        const uchar *qImageBuffer =(const uchar*)iplImage->imageData;
        QImage img(qImageBuffer, width, height, QImage::Format_RGB888);
        return img.rgbSwapped();
    }else{
        qWarning() << "Image cannot be converted.";
        return QImage();
    }
}

bool Camera::connecter(int id)
{

    QMessageBox box;
    Camera::capture = cvCaptureFromCAM(id);

    cout<<"CAMERA : "<<Camera::capture<<endl;
    if (!Camera::capture)
    {
        box.setText("Verifier votre webcam");
        box.exec();
        cout<<"idcam :"<<idcam<<endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

void Camera::enregistrer(string lien )
{
    string nomPhoto;
    string time4photo; //pour avoir date comme nom photo

    time_t t =(time(NULL));

    time4photo=ctime(&t);//récupérer date, minute, heure
    nomPhoto = lien+'/'+time4photo+".jpg";
    cvSaveImage(nomPhoto.c_str(),image);
}

Camera::Camera()
{
    Camera::nbObCam++;
    cout<<"nombre d'objet camera :"<< Camera::nbObCam<<endl;
}
void Camera::liberer()
{
    cvReleaseCapture(&capture);
}

Camera::~Camera()
{
//    cvReleaseCapture(&capture);
}

void Camera::run()
{

    while(true)
    {
        usleep(50);
        image = cvQueryFrame(capture);//récuperer le flux de la webcam
        img=IplImage2QImage(image);//convertir IplImage en QImage
        emit emSig2(img);
    }

}




