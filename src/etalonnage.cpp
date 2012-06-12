//---------------------------------------------------------
//NOM : etalonnage.cpp

//UTILITE : La classe Etalonnage permet de définir les consignes et de vérifier la stailité
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#include "etalonnage.h"


Etalonnage::Etalonnage(float stabFromCfg, Sonde ref, Sonde ext, Sonde inte, bool check, string adresse, int _idCam)
{
    stabilite=stabFromCfg;
    cout<<"Un objet etalonnage"<<endl;
    fr = new Four;
    //    cam= new Camera(_cam);
    idcam = _idCam;
    //    sdRef= new Sonde(ref);

    //      sdRef =ref;
    //    float refCoef=ref.coefficient1;
    sdRef = new Sonde("reference",ref.getCoef1(),ref.getCoef2(), ref.getCoef3());
    sdExt = new Sonde("externe",ext.getCoef1(),ext.getCoef2(), ext.getCoef3());
    sdInt = new Sonde("interne",inte.getCoef1(),inte.getCoef2(), inte.getCoef3());
    //    sdExt =  new Sonde("externe");
    //    sdRef = new Sonde("reference");
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

    QMessageBox box;
    //    emit emSigPrendPhoto();

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
//        float tmpTempo=sdRef->acquerirTemp().toFloat();


//        while((tmpTempo>(tabTemp.at(i)+0.5)) && (tmpTempo<(tabTemp.at(i)-0.5)) )
//        {
//            sleep(200);
//            tmpTempo=sdRef->acquerirTemp().toFloat();
//        }

//        float tempIntTempo=sdInt->acquerirTemp().toFloat();
//        float tempRefTempo=sdRef->acquerirTemp().toFloat();
//        float newcons=tabTemp.at(i)+tempIntTempo-tempRefTempo;// calculer la nouvelle consigne
//        fr->definirTemp(str.setNum(newcons));//définie la temperature
//        emit emSigCons(str.setNum(newcons));
//        cout<<"temperatur envoyée :"<<str.toStdString()<<endl;
        stab = false;
        while(stab==false)
        {
            for(int j=0; j<5; j++)//récupére 1 valeur tout les 3 sec jusqu'a 240 valeurs
            {
                tabTempRecup.push_back(sdRef->acquerirTemp().toFloat());//récupére la temperature externe et la stock
                sleep(1);
                cout<<"DANS CONSIGNE : "<<sdRef->acquerirTemp().toFloat()<<endl;
            }
            stab = testStabilite(tabTempRecup, stabilite);
        }

        cout<<"idcam :"<<idcam<<endl;
        if((checkBox==true)&&(idcam==0) || ((checkBox==false)&&(idcam!=0)))
        {

            box.setText("Les photos ne seront pas enregistrées ");
            box.exec();
            return;
        }

        if((checkBox==true)&&(idcam!=0))
        {

            emit emSigPrendPhoto();
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

bool Etalonnage::testStabilite(vector<float>tab, float stability)//
{
    float max, min;
    min=1000;
    max=-1000;

    int taille = tab.size();

    cout<<"satabilité dans test dtab :"<<stability<<endl;

    float median;

    sort(tab.begin(), tab.end());

    if (taille  % 2 == 0)
    {
        median = (tab[taille / 2 - 1] + tab[taille / 2]) / 2;
    }
    else
    {
        median = tab[taille / 2];
    }

    cout<<"median : "<<median<<endl;



    for (int i=0; i<tab.size();i++)
    {
        if((tab.at(i)>max) && (tab.at(i)<median+5)&&(tab.at(i)>median-5))
            max=tab.at(i);

        if((tab.at(i)<min)&& (tab.at(i)<median+5) && (tab.at(i)>median-5))
            min=tab.at(i);

        cout<<"min :"<<min<<" max :"<<max<<endl;
    }


    if((max-min)<=stability )
    {
        return true;
        cout<<"ON EST STABLE"<<endl;
    }
    else
        return false;
}


