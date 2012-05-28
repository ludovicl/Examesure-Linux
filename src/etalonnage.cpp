//---------------------------------------------------------
//NOM : etalonnage.cpp

//UTILITE : La classe Etalonnage permet de définir les consignes et de vérifier la stailité
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#include "etalonnage.h"


Etalonnage::Etalonnage()
{
    cout<<"Un objet etalonnage"<<endl;
    fr = new Four;
    sdRef = new Sonde("reference");
    sdInt = new Sonde("interne");
}

float Etalonnage::get_tempMini()
{
    return tempMini;
}

void Etalonnage::set_tempMini(float para)
{
    tempMini = para;
}

float Etalonnage::get_tempMax()
{
    return tempMax;
}


void Etalonnage::set_tempMax(float para)
{

    tempMax = para;
}


float Etalonnage::get_intervalle()
{


    return intervalle;
}

void Etalonnage::set_intervalle(float para)
{
    intervalle = para;
}

vector<float> Etalonnage::get_tabTemp()
{

    return tabTemp;
}


void Etalonnage::set_tabTemp(vector<float> para)
{
    tabTemp=para;

}

void Etalonnage::remplir_tabTemp()
{
    float tmp=tempMini;
    while (tmp<=tempMax+intervalle)
    {
        tabTemp.push_back(tmp);//remplir le vector des temperatures
        tmp +=intervalle;
    }
}

void Etalonnage::run()
{
    ofstream fichier("/home/ludovic/Bureau/test.txt", ios::out | ios::trunc);

    bool stab;
    cout<<"dans les consignes"<<endl;
    for (int i=0; i<tabTemp.size();i++)//les consignes rentrées par l'opérateur
    {
        cout <<"TabTEMP :"<<tabTemp.size()<<endl;
        QString str;
        str.setNum(tabTemp.at(i));
        cout<<"CONSIGNE : "<<str.toStdString()<<endl;
        fr->definirTemp(str);//définie la temperature

        emit emSigCons(str.setNum(tabTemp.at(i)));
        float tmpTempo=sdRef->acquerirTemp().toFloat();

        if((tmpTempo>(tabTemp.at(i)+0.01)) && (tmpTempo<(tabTemp.at(i)-0.01)) )
        {
            sleep(200);
            tmpTempo=sdRef->acquerirTemp().toFloat();
        }
        float tempIntTempo=sdInt->acquerirTemp().toFloat();
        float tempRefTempo=sdRef->acquerirTemp().toFloat();
        float newcons=tabTemp.at(i)+tempIntTempo-tempRefTempo;// calculer la nouvelle consigne
        fr->definirTemp(str.setNum(newcons));//définie la temperature
        emit emSigCons(str.setNum(newcons));
        cout<<"temperatur envoyée :"<<str.toStdString()<<endl;
        stab = false;
        while(stab==false)
        {
            for(int j=0; j<240; j++)//récupére 1 valeur tout les 3 sec jusqu'a 240 valeurs
            {
                tabTempRecup.push_back(sdRef->acquerirTemp().toFloat());//récupére la temperature externe et la stock
                sleep(1);
                cout<<"DANS CONSIGNE : "<<sdRef->acquerirTemp().toFloat()<<endl;
            }
            stab = testStabilite(tabTempRecup);
        }

        fichier<<"Reference : "<<endl;
        fichier<<i+1<<" : ";
        fichier<<sdRef->acquerirTemp().toFloat()<<endl;

        fichier<<"Interne : "<<endl;
        fichier<<i+1<<" : ";
        fichier<<sdInt->acquerirTemp().toFloat()<<endl;

        fichier.close();
    }
}

bool Etalonnage::testStabilite(vector<float>tab)//
{
    float max, min;

    for (int i=0; i<tab.size();i++)
    {
        if((tab.at(i)>max) && (tab.at(i)=!0))
            max=tab.at(i);

        else if((tab.at(i)<min) && (tab.at(i)=!0))
            min=tab.at(i);
    }
    if((max-min)<=0.2 )
    {
        return true;
        cout<<"ON EST STABLE"<<endl;
    }
    else
        return false;
}


