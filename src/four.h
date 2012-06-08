//---------------------------------------------------------
//NOM :four.h

//UTILITE : evoyer un consigne au four
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#ifndef FOUR_H
#define FOUR_H
#include <iostream>
using namespace std;
#include <stdio.h>
#include "rs232.h"
class Four
{
private :
    static int id;
   static int vitesse;

public :


    Four();
    void definirTemp(QString);

};

#endif // FOUR_H
