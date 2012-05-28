//---------------------------------------------------------
//NOM : config.cpp

//UTILITE : Fichier de l'ui de la configuration généré par QT Creator
//PROJET : Projet de fin de bts iris Examesure

//Date : 2012
//AUTEUR : LARDIES Ludovic
//-------------------------------------------------------
#include "config.h"
#include "ui_config.h"

Config::Config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Config)
{
    ui->setupUi(this);
}

Config::~Config()
{
    delete ui;
}

void Config::on_toolButton_clicked()
{

    QFileDialog *dialog=new QFileDialog;

    dialog->setFileMode(QFileDialog::DirectoryOnly);
    connect(dialog,SIGNAL(fileSelected( QString  )),ui->labelLien,SLOT(setText(QString)));
    dialog->exec();


}
