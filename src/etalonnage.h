//---------------------------------------------------------
//NOM : etalonnage.h

//UTILITE : La classe Etalonnage permet de définir les consignes et de vérifier la stailité
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#ifndef ETALONNAGE_H
#define ETALONNAGE_H

#include <iostream>
using namespace std;
//#include "mainwindow.h"
#include "math.h"
#include "four.h"
#include "sonde.h"
#include <vector>
#include <QMessageBox>
#include <QtGui>
#include <fstream>
#include <sstream>
#include <string>

class Etalonnage : public QThread
{
    Q_OBJECT
private :

    int tempMini;
    int tempMax;
    float intervalle;
    vector<float>tabTemp;
    vector<float>tabTempRecup;
    Four *fr;
    Sonde *sdRef;
    bool checkBox;
    int idcam;
    string adresseLienPhotos;
    //    Sonde sdRef;
    Sonde *sdInt;
    Sonde *sdExt;
    float stabilite;

signals:
    virtual void emSigCons(QString);
    virtual void emSigPrendPhoto();

public :

    Etalonnage(float, Sonde, Sonde, Sonde, bool, string, int );
    ~Etalonnage();

    static int nbObjEtalonnage;//vérifier le nombre d'objet

    bool testStabilite(vector<float>, float);

    float get_tempMini();
    void set_tempMini(float);

    void  run();

    float get_tempMax();
    void set_tempMax(float);

    float get_intervalle();
    void set_intervalle(float);

    vector<float> get_tabTemp();
    void set_tabTemp(vector<float>);

    void remplir_tabTemp();

};



#endif // ETALONNAGE_H
