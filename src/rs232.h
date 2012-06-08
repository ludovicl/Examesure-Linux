//--------------------------------------------------------
//NOM : rs232.h

//UTILITE : la classe Rs23 permet de gérer la liaison série rs232
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#ifndef RS232_H
#define RS232_H
#include <fcntl.h> // pour ORDWR ...
#include <QtGui>
#include <QSemaphore>
#include <stdio.h>
#include <iostream>
using namespace std;
#include <QMutex>
#include<cstdlib> //pour avoir un pointeur null
class Rs232
{
public :
    void ecrire(QString, int );
    QString recevoir(QString, int );
    int get_id_tty();
    Rs232();
    static Rs232* getInstance();


signals:
    void emSig2(QString str);
    void sigInc(int i);


private:
    QMutex mutex;
    static Rs232* rs232;

    Rs232(const Rs232&);
    Rs232& operator= (const Rs232&);

    string vitesseFour;
    int id_tty;
    int idFour;

    int taille;
    char * buffer;

    char buff[15];
    char key;
    int found;
    int found2;
    QString buffRead;
    QString trameFormateTint;
    QString trameFormate;
};
#endif // RS232_H
