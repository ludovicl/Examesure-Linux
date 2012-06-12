//---------------------------------------------------------
//NOM : sonde.h

//UTILITE : La classe Sonde permet de définir les sondes à lire
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#ifndef SONDE_H
#define SONDE_H
 #include <QString>
#include "rs232.h"

class Sonde
{
private :

    QString temperature;
    string type;

    //coeff1=a, coeff2=b, coeff3=c dans une equation a+bx+cx²
    float coefficient1, coefficient2, coefficient3;
public :


    Sonde(string letypedesonde);
    Sonde(string type,float c1, float c2,float c3);

    float getCoef1();
    float getCoef2();
    float getCoef3();

    void set_type(string);
    string get_type();

    float get_temp();
    QString acquerirTemp();

};


class ThreadAcquerir : public QThread
{
    Q_OBJECT

public :
    ThreadAcquerir(string);
    virtual void run();

signals:
    virtual void emSig(QString str);

private :
    Sonde *sd;
    string type;

};

#endif // SONDE_H
