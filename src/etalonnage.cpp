//---------------------------------------------------------
//NOM : etalonnage.cpp

//UTILITE : La classe Etalonnage permet de définir les consignes et de vérifier la stailité
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#include "etalonnage.h"
int Etalonnage::nbObjEtalonnage;

Etalonnage::Etalonnage(float stabFromCfg, Sonde ref, Sonde ext, Sonde inte, string check, string adresse, int _idCam)
{
    Etalonnage::nbObjEtalonnage++;

    stabilite=stabFromCfg;
    cout<<"Un objet etalonnage"<<endl;
    checkBox = check;
    fr = new Four;
    idcam = _idCam;
    sdRef = new Sonde("reference",ref.getCoef1(),ref.getCoef2(), ref.getCoef3());
    sdExt = new Sonde("externe",ext.getCoef1(),ext.getCoef2(), ext.getCoef3());
    sdInt = new Sonde("interne");
}

Etalonnage::~Etalonnage()
{
    delete fr;
    delete sdRef;
    delete sdExt;
    delete sdInt;
    Etalonnage::nbObjEtalonnage--;
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
    while (tmp<tempMax+intervalle)
    {

        tmp= tmp * 100;
        tmp = ceil( tmp );
        tmp = tmp / 100;

        tabTemp.push_back(tmp);//remplir le vector des temperature
        tmp +=intervalle;
    }


}

void Etalonnage::run()
{
    ofstream fichier("/home/ludovic/Bureau/test.txt", ios::out | ios::trunc);
    QMessageBox box;
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
        float tmpTempo=sdInt->acquerirTemp().toFloat();

        //tant que temperature est suprérieur a la consigne +0,5° ou inférieur à la consigne -0.5°
        while(true)
        {
            if ((tmpTempo<(tabTemp.at(i)+5)) && (tmpTempo>(tabTemp.at(i)-5)) )
            {
                break;
            }
            else
            {
                sleep(1);
                tmpTempo=sdInt->acquerirTemp().toFloat();
                cout<<"dans le while"<<endl;
            }
        }

        float tempIntTempo=sdInt->acquerirTemp().toFloat();
        float tempRefTempo=sdRef->acquerirTemp().toFloat();
        float newcons=tabTemp.at(i)+tempIntTempo-tempRefTempo;// calculer la nouvelle consigne
        fr->definirTemp(str.setNum(newcons));//définie la temperature
        cout<<"nouvelle consigne :"<<newcons<<endl;

        emit emSigCons(str.setNum(newcons));
        cout<<"temperatur envoyée :"<<str.toStdString()<<endl;
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
        cout<<"checkBox dans etalonnage : "<<checkBox<<endl;

        if((checkBox=="1")&&(idcam!=0))
        {
            cout<<"CHEESE"<<endl;
            emit emSigPrendPhoto();
            fichier<<"Reference : "<<endl;
//            fichier<<i+1<<" : ";
            fichier<<sdRef->acquerirTemp().toFloat()<<endl;
        }
        else
        {
            cout<<"ON STOCK DANS LE FICHIER "<<endl;
            fichier<<"Reference : "<<endl;
//            fichier<<i+1<<" : ";
            fichier<<sdRef->acquerirTemp().toFloat()<<endl;
            usleep(200);
            fichier<<"Interne : "<<endl;
//            fichier<<i+1<<" : ";
            fichier<<sdInt->acquerirTemp().toFloat()<<endl;


        }
    }
     fichier.close();
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

    if (taille  % 2 == 0)//le nombre de valeurs dans le vector est impaire
    {
        median = (tab[taille / 2 - 1] + tab[taille / 2]) / 2;
    }
    else// le nombre de valeurs dans le vector est paire
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


