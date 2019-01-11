/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNovo_Mapa;
    QAction *actionCarregar_Mapa;
    QAction *actionSalvar_Mapa;
    QAction *actionExportar_como_imagem;
    QAction *actionPropriedades_do_mapa;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEditar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(153, 87);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionNovo_Mapa = new QAction(MainWindow);
        actionNovo_Mapa->setObjectName(QStringLiteral("actionNovo_Mapa"));
        actionCarregar_Mapa = new QAction(MainWindow);
        actionCarregar_Mapa->setObjectName(QStringLiteral("actionCarregar_Mapa"));
        actionSalvar_Mapa = new QAction(MainWindow);
        actionSalvar_Mapa->setObjectName(QStringLiteral("actionSalvar_Mapa"));
        actionSalvar_Mapa->setEnabled(false);
        actionExportar_como_imagem = new QAction(MainWindow);
        actionExportar_como_imagem->setObjectName(QStringLiteral("actionExportar_como_imagem"));
        actionExportar_como_imagem->setEnabled(false);
        actionPropriedades_do_mapa = new QAction(MainWindow);
        actionPropriedades_do_mapa->setObjectName(QStringLiteral("actionPropriedades_do_mapa"));
        actionPropriedades_do_mapa->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 153, 24));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEditar = new QMenu(menuBar);
        menuEditar->setObjectName(QStringLiteral("menuEditar"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEditar->menuAction());
        menuFile->addAction(actionNovo_Mapa);
        menuFile->addAction(actionCarregar_Mapa);
        menuFile->addAction(actionSalvar_Mapa);
        menuFile->addSeparator();
        menuFile->addAction(actionExportar_como_imagem);
        menuEditar->addAction(actionPropriedades_do_mapa);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNovo_Mapa->setText(QApplication::translate("MainWindow", "&Novo Mapa", nullptr));
        actionCarregar_Mapa->setText(QApplication::translate("MainWindow", "&Carregar Mapa", nullptr));
        actionSalvar_Mapa->setText(QApplication::translate("MainWindow", "&Salvar Mapa", nullptr));
        actionExportar_como_imagem->setText(QApplication::translate("MainWindow", "&Exportar como imagem", nullptr));
        actionPropriedades_do_mapa->setText(QApplication::translate("MainWindow", "&Propriedades do mapa", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "Ar&quivo", nullptr));
        menuEditar->setTitle(QApplication::translate("MainWindow", "Edita&r", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
