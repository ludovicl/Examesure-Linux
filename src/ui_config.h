/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created: Sat Jun 2 19:56:05 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboWebcam;
    QFrame *frame;
    QLabel *labelLien;
    QCheckBox *checkBox;
    QLabel *label_3;
    QComboBox *comboVitesses;
    QLabel *label_4;
    QSpinBox *spinAddr;
    QFrame *frame_2;
    QLabel *label_15;
    QDoubleSpinBox *spinCoefRef1_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QFrame *frame_3;
    QDoubleSpinBox *spinCoefExt1;
    QDoubleSpinBox *spinCoefExt2;
    QDoubleSpinBox *spinCoefExt3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QDoubleSpinBox *spinCoefRef3;
    QLabel *label_13;
    QLabel *label_14;
    QDoubleSpinBox *spinCoefRef2;
    QDoubleSpinBox *spinCoefRef1;
    QFrame *frame_4;
    QToolButton *toolButton;
    QPushButton *pushValider;
    QPushButton *pushAnnuler;

    void setupUi(QWidget *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QString::fromUtf8("Config"));
        Config->resize(537, 506);
        label = new QLabel(Config);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 25, 81, 17));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(Config);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 55, 151, 17));
        label_2->setFont(font);
        comboWebcam = new QComboBox(Config);
        comboWebcam->setObjectName(QString::fromUtf8("comboWebcam"));
        comboWebcam->setGeometry(QRect(110, 25, 141, 20));
        comboWebcam->setEditable(false);
        frame = new QFrame(Config);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 15, 511, 71));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labelLien = new QLabel(frame);
        labelLien->setObjectName(QString::fromUtf8("labelLien"));
        labelLien->setGeometry(QRect(170, 35, 221, 31));
        QFont font1;
        font1.setPointSize(12);
        labelLien->setFont(font1);
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(250, 10, 241, 22));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        checkBox->setFont(font2);
        label_3 = new QLabel(Config);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(135, 143, 141, 17));
        label_3->setFont(font);
        comboVitesses = new QComboBox(Config);
        comboVitesses->setObjectName(QString::fromUtf8("comboVitesses"));
        comboVitesses->setGeometry(QRect(275, 143, 101, 20));
        label_4 = new QLabel(Config);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(135, 113, 191, 17));
        label_4->setFont(font);
        spinAddr = new QSpinBox(Config);
        spinAddr->setObjectName(QString::fromUtf8("spinAddr"));
        spinAddr->setGeometry(QRect(290, 110, 60, 27));
        spinAddr->setMinimum(1);
        frame_2 = new QFrame(Config);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(133, 98, 261, 105));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_15 = new QLabel(frame_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(2, 74, 91, 20));
        label_15->setFont(font);
        spinCoefRef1_2 = new QDoubleSpinBox(frame_2);
        spinCoefRef1_2->setObjectName(QString::fromUtf8("spinCoefRef1_2"));
        spinCoefRef1_2->setGeometry(QRect(149, 73, 62, 20));
        spinCoefRef1_2->setMinimum(-100);
        spinCoefRef1_2->setMaximum(100);
        spinCoefRef1_2->setValue(0.2);
        label_5 = new QLabel(Config);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(300, 222, 201, 16));
        label_5->setFont(font);
        label_6 = new QLabel(Config);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(310, 242, 181, 16));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(75);
        font3.setStrikeOut(false);
        label_6->setFont(font3);
        label_7 = new QLabel(Config);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(310, 277, 121, 17));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(false);
        font4.setWeight(50);
        label_7->setFont(font4);
        label_8 = new QLabel(Config);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(310, 309, 121, 17));
        label_8->setFont(font4);
        label_9 = new QLabel(Config);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(310, 345, 121, 17));
        label_9->setFont(font4);
        frame_3 = new QFrame(Config);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(290, 212, 221, 171));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        spinCoefExt1 = new QDoubleSpinBox(frame_3);
        spinCoefExt1->setObjectName(QString::fromUtf8("spinCoefExt1"));
        spinCoefExt1->setGeometry(QRect(140, 67, 61, 20));
        spinCoefExt1->setMinimum(-100);
        spinCoefExt1->setMaximum(100);
        spinCoefExt1->setSingleStep(1);
        spinCoefExt1->setValue(0);
        spinCoefExt2 = new QDoubleSpinBox(frame_3);
        spinCoefExt2->setObjectName(QString::fromUtf8("spinCoefExt2"));
        spinCoefExt2->setGeometry(QRect(140, 97, 62, 20));
        spinCoefExt2->setMinimum(-100);
        spinCoefExt2->setMaximum(100);
        spinCoefExt3 = new QDoubleSpinBox(frame_3);
        spinCoefExt3->setObjectName(QString::fromUtf8("spinCoefExt3"));
        spinCoefExt3->setGeometry(QRect(141, 137, 63, 20));
        spinCoefExt3->setMinimum(-100);
        spinCoefExt3->setMaximum(100);
        label_10 = new QLabel(Config);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(34, 245, 220, 16));
        label_10->setFont(font3);
        label_11 = new QLabel(Config);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(41, 228, 201, 16));
        label_11->setFont(font);
        label_12 = new QLabel(Config);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 353, 121, 17));
        label_12->setFont(font4);
        spinCoefRef3 = new QDoubleSpinBox(Config);
        spinCoefRef3->setObjectName(QString::fromUtf8("spinCoefRef3"));
        spinCoefRef3->setGeometry(QRect(160, 353, 62, 20));
        spinCoefRef3->setMinimum(-100);
        spinCoefRef3->setMaximum(100);
        label_13 = new QLabel(Config);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(40, 318, 121, 17));
        label_13->setFont(font4);
        label_14 = new QLabel(Config);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(40, 283, 121, 17));
        label_14->setFont(font4);
        spinCoefRef2 = new QDoubleSpinBox(Config);
        spinCoefRef2->setObjectName(QString::fromUtf8("spinCoefRef2"));
        spinCoefRef2->setGeometry(QRect(160, 318, 62, 20));
        spinCoefRef2->setMinimum(-100);
        spinCoefRef2->setMaximum(100);
        spinCoefRef1 = new QDoubleSpinBox(Config);
        spinCoefRef1->setObjectName(QString::fromUtf8("spinCoefRef1"));
        spinCoefRef1->setGeometry(QRect(160, 283, 62, 20));
        spinCoefRef1->setMinimum(-100);
        spinCoefRef1->setMaximum(100);
        frame_4 = new QFrame(Config);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(20, 211, 241, 171));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        toolButton = new QToolButton(Config);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(410, 53, 71, 25));
        pushValider = new QPushButton(Config);
        pushValider->setObjectName(QString::fromUtf8("pushValider"));
        pushValider->setGeometry(QRect(410, 430, 91, 21));
        pushAnnuler = new QPushButton(Config);
        pushAnnuler->setObjectName(QString::fromUtf8("pushAnnuler"));
        pushAnnuler->setGeometry(QRect(310, 430, 91, 21));
        frame_4->raise();
        frame_3->raise();
        frame_2->raise();
        frame->raise();
        label->raise();
        label_2->raise();
        comboWebcam->raise();
        label_3->raise();
        comboVitesses->raise();
        label_4->raise();
        spinAddr->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        spinCoefRef3->raise();
        label_13->raise();
        label_14->raise();
        spinCoefRef2->raise();
        spinCoefRef1->raise();
        toolButton->raise();
        pushValider->raise();
        pushAnnuler->raise();

        retranslateUi(Config);

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QWidget *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "Configuration avanc\303\251e", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Config", "Webcam :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Config", "Lien des photos :", 0, QApplication::UnicodeUTF8));
        comboWebcam->clear();
        comboWebcam->insertItems(0, QStringList()
         << QApplication::translate("Config", "Aucune webcam", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Config", "Webcam 1", "1", QApplication::UnicodeUTF8)
         << QApplication::translate("Config", "Webcam 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Config", "Webcam 3", 0, QApplication::UnicodeUTF8)
        );
        labelLien->setText(QString());
#ifndef QT_NO_WHATSTHIS
        checkBox->setWhatsThis(QApplication::translate("Config", "<html><head/><body><p>S\303\251l\303\251ctionnez cettte option si vous utilisez</p><p>une sonde avec afficheur digital</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox->setText(QApplication::translate("Config", "Eregister les mesures avec la webcam", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Config", "Vitesse du four :", 0, QApplication::UnicodeUTF8));
        comboVitesses->clear();
        comboVitesses->insertItems(0, QStringList()
         << QApplication::translate("Config", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Config", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Config", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Config", "19200", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("Config", "Adresse du four :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Config", "Stabilit\303\251 :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Config", "Polynome de corr\303\251ction", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Config", "de la sonde externe :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Config", "Coefficient 1 :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Config", "Coefficient 2 :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Config", "Coefficient 3 :", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Config", "de la sonde de r\303\251f\303\251rence :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Config", "Polynome de corr\303\251ction", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Config", "Coefficient 3 :", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Config", "Coefficient 2 :", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Config", "Coefficient 1 :", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("Config", "Naviguer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushValider->setToolTip(QApplication::translate("Config", "D\303\251marrer une s\303\251rie de mesure", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushValider->setText(QApplication::translate("Config", "Valider", 0, QApplication::UnicodeUTF8));
        pushAnnuler->setText(QApplication::translate("Config", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
