//---------------------------------------------------------
//NOM : sonde.cpp

//UTILITE : La classe Sonde permet de définir les sondes à lire
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#include "sonde.h"

Sonde::Sonde(string ty)
{
    type = ty;
    cout<<"Un objet sonde"<<endl;
}

Sonde::Sonde(string ty,float c1,float c2,float c3)
{
    coefficient1=c1;
    coefficient2=c2;
    coefficient3=c3;

    type = ty;
    cout<<"Un objet sonde"<<endl;
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
        voie="100";
    }

    return	rs->recevoir(voie,rs->get_id_tty());
}
void Sonde::set_type(string para)
{
    type = para;
}

string Sonde::get_type()
{
    return type;
}

ThreadAcquerir::ThreadAcquerir(string cons)
{

    sd = new Sonde(cons);

}

void ThreadAcquerir::run()
{


    while(true)
    {
        sleep(2);
        emit emSig(sd->acquerirTemp());

    }

}

