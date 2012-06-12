//---------------------------------------------------------
//NOM :four.cpp

//UTILITE : evoyer un consigne au four
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#include "four.h"

Four::Four()
{

    cout<<"Un objet Four"<<endl;
}

void Four::definirTemp(QString temp)
{
    Rs232 *rs=Rs232::getInstance ();
    rs->ecrire(temp, rs->get_id_tty());
    cout<<"ici four"<<endl;
}




