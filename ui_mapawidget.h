/********************************************************************************
** Form generated from reading UI file 'mapawidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPAWIDGET_H
#define UI_MAPAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mapaview.h"

QT_BEGIN_NAMESPACE

class Ui_MapaWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    MapaView *view;
    QSlider *horizontalSlider;
    QVBoxLayout *verticalLayout_2;
    QListWidget *taiko_list;
    QPushButton *add_taiko;

    void setupUi(QWidget *MapaWidget)
    {
        if (MapaWidget->objectName().isEmpty())
            MapaWidget->setObjectName(QStringLiteral("MapaWidget"));
        MapaWidget->resize(534, 340);
        verticalLayout = new QVBoxLayout(MapaWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        view = new MapaView(MapaWidget);
        view->setObjectName(QStringLiteral("view"));

        verticalLayout_3->addWidget(view);

        horizontalSlider = new QSlider(MapaWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalSlider);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        taiko_list = new QListWidget(MapaWidget);
        taiko_list->setObjectName(QStringLiteral("taiko_list"));
        taiko_list->setMaximumSize(QSize(250, 16777215));

        verticalLayout_2->addWidget(taiko_list);

        add_taiko = new QPushButton(MapaWidget);
        add_taiko->setObjectName(QStringLiteral("add_taiko"));
        add_taiko->setMaximumSize(QSize(250, 16777215));

        verticalLayout_2->addWidget(add_taiko);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MapaWidget);
        QObject::connect(taiko_list, SIGNAL(doubleClicked(QModelIndex)), add_taiko, SLOT(click()));

        QMetaObject::connectSlotsByName(MapaWidget);
    } // setupUi

    void retranslateUi(QWidget *MapaWidget)
    {
        MapaWidget->setWindowTitle(QApplication::translate("MapaWidget", "Form", nullptr));
        add_taiko->setText(QApplication::translate("MapaWidget", "Adicionar instrumento", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapaWidget: public Ui_MapaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPAWIDGET_H
