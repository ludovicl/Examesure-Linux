//--------------------------------------------------------
//NOM : rs232.cpp

//UTILITE : la classe Rs232 permet de gérer la liaison série rs232
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#include "rs232.h"

int Rs232::id_tty;
Rs232* Rs232::rs232 = NULL;
string Rs232::vitesseFour="0";
QString Rs232::idFour="0";

Rs232* Rs232::getInstance ()
{
    if (Rs232::rs232 == NULL)
    {
        Rs232::rs232 = new Rs232;
    }
    return Rs232::rs232;
}

Rs232* Rs232::getInstance (QString id, string baud)
{
    Rs232::vitesseFour=baud;
    Rs232::idFour=id;

    if (Rs232::rs232 == NULL)
    {
        Rs232::rs232 = new Rs232;

    }
    return Rs232::rs232;
}

Rs232::Rs232()
{


    //    cout<<"Un objet entree"<<endl;

    if (Rs232::vitesseFour=="2400")
    {
        system("stty -F /dev/ttyUSB0 2400");
        system("stty -F /dev/ttyUSB1 2400");
    }

    else if (Rs232::vitesseFour=="4800")
    {
        system("stty -F /dev/ttyUSB0 4800");
        system("stty -F /dev/ttyUSB1 4800");
    }

    else if (Rs232::vitesseFour=="9600")
    {
        system("stty -F /dev/ttyUSB0 9600");
        system("stty -F /dev/ttyUSB1 9600");
    }
    else if (Rs232::vitesseFour=="19200")
    {
        system("stty -F /dev/ttyUSB0 19200");
        system("stty -F /dev/ttyUSB1 19200");
    }

    id_tty=open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NONBLOCK ); //




    if (id_tty < 0 )
    {

        id_tty=open("/dev/ttyUSB1", O_RDWR | O_NOCTTY | O_NONBLOCK ); //
    }


    if (id_tty < 0 )
    {
        QMessageBox box;
        perror("open");
//        cout<<"On est pas co "<<endl;
        box.setText("VERIFIEZ VOTRE LIASISON RS232");
        box.exec();
    }




    QString data = "$"+idFour+"WVAR8 3 \r";

    const char* buffer= data.toStdString().c_str();

    mutex.lock();

    write(id_tty, buffer ,data.size()); //ecrire sur la liaison
    usleep(200);
    mutex.unlock(); // debloque la liaison RS232

}

void Rs232::ecrire(QString para, int id_tty)
{
    QString data = "$"+Rs232::idFour+"WVAR0 "+para+"\r";
    const char* buffer= data.toStdString().c_str();


    mutex.lock();

    tcflush(Rs232::id_tty,TCIFLUSH );

    write(id_tty, buffer ,data.size()); //envoi au port serie
    usleep(200);
    mutex.unlock(); // debloque la liaison RS232



    usleep(50);

}

QString Rs232::recevoir(QString para, int id_tty) // recuperer la temperature externe
{

    char buff[15];

    mutex.lock();

    buffRead="0";
    QString data = "$"+Rs232::idFour+"RVAR"+para+" \r";
//    cout<<data.toStdString()<<endl;
    taille = data.size()+1; // recupere la taille de la donnée

    char * buffer = new char[ taille ]; // pour convertir le string en char*
    strcpy(buffer, data.toStdString().c_str()); // convertie le string en char*


    write(id_tty, buffer ,data.size()); //envoi au port serie

    usleep(200);
    int nb=0;
    //    for(int i=0; i<3; i++)
    //    {

    for(nb=0;nb<20;nb++)
    {
        read(id_tty,buff+nb, 1);//lire sur la liaison caractère par caractère

        if(buff[nb]=='\r')//lire jusqu'au caractère <cr>
        {
            
            break;//sortir de la boucle
        }
    }
    mutex.unlock();
    
    
    
    //        if(nb>4)
    //            break;
    //    }

    tcflush(Rs232::id_tty,TCOFLUSH );

    buffRead=buff;//convertie buff(char*) en QString

//    cout<<"buffer : "<<buffRead.toStdString()<<endl;
//    cout<<"Taille du buffer :"<<buffRead.size()<<endl;

    found = buffRead.lastIndexOf(" "); //trouve ou est le caractere  espace
    found2 = buffRead.indexOf(" ");//et le 2em caractere espace
    trameFormate=buffRead.mid(found2,found);

//    cout<<trameFormate.toStdString()<<endl;

    if ((trameFormate.toFloat()>0) && (trameFormate.toFloat()<1000))
    {
        mutex.unlock();
        return trameFormate;
    }
    else
    {
        mutex.unlock();
        return 0;
    }


}

int  Rs232::get_id_tty()
{
    return id_tty;
}
