#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    novoMapa = ui->actionNovo_Mapa;
    loadMapa = ui->actionCarregar_Mapa;
    saveMapa = ui->actionSalvar_Mapa;
    connect(novoMapa, SIGNAL(triggered()), this, SLOT(criaMapa()));
    connect(loadMapa, SIGNAL(triggered()), this, SLOT(carregaMapa()));
    connect(saveMapa, SIGNAL(triggered()), this, SLOT(salvaMapa()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::criaMapa() {
    QDialog* dialog = new QDialog;
    QFormLayout form(dialog);
    QLineEdit* mTitle= new QLineEdit(dialog);
    QDoubleSpinBox* mWidth= new QDoubleSpinBox(dialog);
    QDoubleSpinBox* mHeight = new QDoubleSpinBox(dialog);;
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, dialog);
    form.addRow(QString("Título:"),mTitle);
    form.addRow(QString("Largura:"),mWidth);
    form.addRow(QString("Altura:"),mHeight);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

    if (dialog->exec() == QDialog::Accepted) {
        Mapa* map = new Mapa(mHeight->value(), mWidth->value(), mTitle->text());
        mostraMapa(map);
    }
}

void MainWindow::carregaMapa() {
    Mapa* map;
    QString file_name = QFileDialog::getOpenFileName();
    if ((map=Mapa::carrega_mapa(file_name)) != nullptr) {
        mostraMapa(map);
    }
}

void MainWindow::salvaMapa() {
    QString file_name = QFileDialog::getSaveFileName();
    dynamic_cast<MapaWidget*>(ui->tabWidget->currentWidget())->save(file_name);
}

void MainWindow::mostraMapa(Mapa* map){
    MapaWidget* mapa = new MapaWidget (nullptr, map);
    ui->tabWidget->addTab(mapa,map->titulo);
    saveMapa->setEnabled(true);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
    if (ui->tabWidget->count() <= 0)
        saveMapa->setEnabled(false);
}
