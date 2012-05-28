//---------------------------------------------------------
//NOM : sonde.h

//UTILITE : La classe Sonde permet de définir les sondes à lire
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#ifndef SONDE_H
#define SONDE_H

#include "rs232.h"

class Sonde
{
    private :

        QString temperature;
        string type;

    public :

        Sonde(string);
        void set_type(string);
        string get_type();
        float get_temp();
        QString acquerirTemp();
};


class ThreadAcquerir : public QThread  //lire la temperature du type  : public QThread
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
