//---------------------------------------------------------
//NOM :four.h

//UTILITE : evoyer un consigne au four
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#ifndef FOUR_H
#define FOUR_H

#include "sonde.h"
#include "rs232.h"
#include <iostream>
using namespace std;
#include <stdio.h>
class Four
{
private :
    int id;
    int vitesse;

public :

    Rs232 *rs;
    Four();
    void definirTemp(QString);

};

#endif // FOUR_H
