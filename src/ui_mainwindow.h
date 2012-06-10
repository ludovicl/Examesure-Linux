/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Jun 10 19:53:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConfiguration_avanc_e;
    QWidget *centralWidget;
    QPushButton *demarrer;
    QLabel *label_5;
    QTableWidget *tableWidget;
    QLabel *labelCam;
    QFrame *frame;
    QSpinBox *spinMini;
    QSpinBox *spinMaxi;
    QDoubleSpinBox *spinInter;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QFrame *frame_2;
    QLabel *labelTempInt;
    QFrame *frame_3;
    QLabel *label_7;
    QFrame *frame_4;
    QLabel *labelConsigne;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menuConfigurer_des_mesures;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(650, 500);
        MainWindow->setMinimumSize(QSize(650, 500));
        MainWindow->setMaximumSize(QSize(650, 500));
        QFont font;
        font.setKerning(true);
        MainWindow->setFont(font);
        actionConfiguration_avanc_e = new QAction(MainWindow);
        actionConfiguration_avanc_e->setObjectName(QString::fromUtf8("actionConfiguration_avanc_e"));
        actionConfiguration_avanc_e->setCheckable(false);
        actionConfiguration_avanc_e->setIconVisibleInMenu(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        demarrer = new QPushButton(centralWidget);
        demarrer->setObjectName(QString::fromUtf8("demarrer"));
        demarrer->setGeometry(QRect(451, 180, 171, 51));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 2, 191, 21));
        QFont font1;
        font1.setPointSize(13);
        label_5->setFont(font1);
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(461, 260, 151, 192));
        labelCam = new QLabel(centralWidget);
        labelCam->setObjectName(QString::fromUtf8("labelCam"));
        labelCam->setGeometry(QRect(20, 180, 391, 281));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        labelCam->setFont(font2);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(250, 3, 261, 151));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        spinMini = new QSpinBox(frame);
        spinMini->setObjectName(QString::fromUtf8("spinMini"));
        spinMini->setGeometry(QRect(173, 10, 60, 27));
        spinMini->setMaximum(2000);
        spinMini->setValue(75);
        spinMaxi = new QSpinBox(frame);
        spinMaxi->setObjectName(QString::fromUtf8("spinMaxi"));
        spinMaxi->setGeometry(QRect(173, 49, 60, 27));
        spinMaxi->setMaximum(2000);
        spinMaxi->setValue(85);
        spinInter = new QDoubleSpinBox(frame);
        spinInter->setObjectName(QString::fromUtf8("spinInter"));
        spinInter->setGeometry(QRect(120, 90, 62, 27));
        spinInter->setMinimum(0.05);
        spinInter->setValue(0.1);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 181, 41));
        label_3->setFont(font1);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 171, 41));
        label_2->setFont(font1);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(14, 92, 101, 21));
        label_4->setFont(font1);
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(4, 3, 241, 111));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        labelTempInt = new QLabel(frame_2);
        labelTempInt->setObjectName(QString::fromUtf8("labelTempInt"));
        labelTempInt->setGeometry(QRect(40, 30, 131, 61));
        QFont font3;
        font3.setPointSize(24);
        font3.setBold(true);
        font3.setWeight(75);
        labelTempInt->setFont(font3);
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(441, 170, 191, 301));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(530, 40, 80, 21));
        label_7->setFont(font1);
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(520, 10, 111, 131));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        labelConsigne = new QLabel(frame_4);
        labelConsigne->setObjectName(QString::fromUtf8("labelConsigne"));
        labelConsigne->setGeometry(QRect(17, 67, 81, 41));
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        labelConsigne->setFont(font4);
        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 0, 91, 41));
        label_6->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        frame_3->raise();
        frame_4->raise();
        frame->raise();
        frame_2->raise();
        demarrer->raise();
        label_5->raise();
        tableWidget->raise();
        labelCam->raise();
        label_7->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 650, 25));
        menuConfigurer_des_mesures = new QMenu(menuBar);
        menuConfigurer_des_mesures->setObjectName(QString::fromUtf8("menuConfigurer_des_mesures"));
        menuConfigurer_des_mesures->setEnabled(true);
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(demarrer, tableWidget);

        menuBar->addAction(menuConfigurer_des_mesures->menuAction());
        menuConfigurer_des_mesures->addSeparator();
        menuConfigurer_des_mesures->addAction(actionConfiguration_avanc_e);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "D\303\251finition  des mesures", 0, QApplication::UnicodeUTF8));
        actionConfiguration_avanc_e->setText(QApplication::translate("MainWindow", "Configuration avanc\303\251e", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        demarrer->setToolTip(QApplication::translate("MainWindow", "D\303\251marrer une s\303\251rie de mesure", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        demarrer->setText(QApplication::translate("MainWindow", "D\303\251marrer les mesures", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Temperature interne :", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Temperatures", 0, QApplication::UnicodeUTF8));
        labelCam->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Temperature maxi :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Temperature mini :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Intervalle :", 0, QApplication::UnicodeUTF8));
        labelTempInt->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "actuelle :", 0, QApplication::UnicodeUTF8));
        labelConsigne->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Consigne", 0, QApplication::UnicodeUTF8));
        menuConfigurer_des_mesures->setTitle(QApplication::translate("MainWindow", "Configuration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
