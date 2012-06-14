//---------------------------------------------------------
//NOM : sonde.cpp

//UTILITE : La classe Sonde permet de définir les sondes à lire
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#include "sonde.h"
int Sonde::nbObjSonde;

Sonde::Sonde(string ty)
{
    type = ty;
    Sonde::nbObjSonde++;
}

Sonde::Sonde(string ty,float c1,float c2,float c3)
{
    coefficient1=c1;
    coefficient2=c2;
    coefficient3=c3;

    type = ty;
    Sonde::nbObjSonde++;
}

QString Sonde::acquerirTemp() //lire la temperature du type
{
    char* voie;
    Rs232 *rs=Rs232::getInstance ();

    if (type == "externe")
    {
        voie="105";
    }

    if (type == "reference")
    {
        voie="106";
    }

    if (type == "interne")
    {
        coefficient1=0;
        coefficient2=1;
        coefficient3=0;
        voie="100";
    }

    float valeur = rs->recevoir(voie,rs->get_id_tty()).toFloat();

    valeur=coefficient1+(valeur*coefficient2)+coefficient3*(valeur*valeur);
    QString strAReturn;
    strAReturn.setNum(valeur);
    return  strAReturn;
}
void Sonde::set_type(string para)
{
    type = para;
}

string Sonde::get_type()
{
    return type;
}

float Sonde::getCoef1()
{

    return coefficient1;
}

float Sonde::getCoef2()
{
    return coefficient2;
}

float Sonde::getCoef3()
{
    return coefficient3;
}
ThreadAcquerir::ThreadAcquerir(string cons)
{

    sd = new Sonde(cons);

}

Sonde::~Sonde()
{
    Sonde::nbObjSonde--;
}


void ThreadAcquerir::run()
{
    while(true)
    {
        sleep(2);
        emit emSig(sd->acquerirTemp());
    }
}

