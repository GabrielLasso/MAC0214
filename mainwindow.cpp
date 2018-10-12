#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    novoMapa = ui->actionNovo_Mapa;
    novoMapa->setShortcut(QKeySequence::New);
    loadMapa = ui->actionCarregar_Mapa;
    loadMapa->setShortcut(QKeySequence::Open);
    saveMapa = ui->actionSalvar_Mapa;
    saveMapa->setShortcut(QKeySequence::Save);
    exportMapa = ui->actionExportar_como_imagem;
    editMapa = ui->actionPropriedades_do_mapa;
    resize(QDesktopWidget().availableGeometry(this).size());
    connect(novoMapa, SIGNAL(triggered()), this, SLOT(criaMapa()));
    connect(loadMapa, SIGNAL(triggered()), this, SLOT(carregaMapa()));
    connect(saveMapa, SIGNAL(triggered()), this, SLOT(salvaMapa()));
    connect(exportMapa, SIGNAL(triggered()), this, SLOT(exportaImagem()));
    connect(editMapa, SIGNAL(triggered()), this, SLOT(propriedadesMapa()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::criaMapa() {
    QDialog* dialog = new QDialog;
    QFormLayout form(dialog);
    QLineEdit* mTitle= new QLineEdit(dialog);
    QLineEdit* mTeam= new QLineEdit(dialog);
    QLineEdit* mCity= new QLineEdit(dialog);
    QDoubleSpinBox* mWidth= new QDoubleSpinBox(dialog);
    QDoubleSpinBox* mHeight = new QDoubleSpinBox(dialog);;
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, dialog);
    form.addRow(QString("Título:"),mTitle);
    form.addRow(QString("Equipe:"),mTeam);
    form.addRow(QString("Cidade:"),mCity);
    form.addRow(QString("Largura:"),mWidth);
    form.addRow(QString("Altura:"),mHeight);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

    if (dialog->exec() == QDialog::Accepted) {
        Mapa* map = new Mapa(mHeight->value(), mWidth->value(), mTitle->text(), mTeam->text(), mCity->text());
        mostraMapa(map);
    }
}

void MainWindow::carregaMapa() {
    Mapa* map;
    QString file_name = QFileDialog::getOpenFileName(nullptr,"Carregar Mapa", "", "Mapas de taiko(*.abt);;Todos os arquivos(*)");
    if ((map=Mapa::carrega_mapa(file_name)) != nullptr) {
        mostraMapa(map);
    }
}

void MainWindow::salvaMapa() {
    if (ui->tabWidget->count() <= 0)
        return;
    QString name = dynamic_cast<MapaWidget*>(ui->tabWidget->currentWidget())->data->titulo;
    QString file_name = QFileDialog::getSaveFileName(nullptr,"Salvar mapa", name+".abt", "Mapas de taiko(*.abt);;Todos os arquivos(*)");
    dynamic_cast<MapaWidget*>(ui->tabWidget->currentWidget())->save(file_name);
}

void MainWindow::exportaImagem() {
    if (ui->tabWidget->count() <= 0)
        return;
    QString name = dynamic_cast<MapaWidget*>(ui->tabWidget->currentWidget())->data->titulo;
    QString file_name = QFileDialog::getSaveFileName(nullptr,"Exportar Para...", name+".png", "Imagens(*.png *.xpm *.jpg);;Todos os arquivos(*)");
    dynamic_cast<MapaWidget*>(ui->tabWidget->currentWidget())->exportToImage(file_name);
}

void MainWindow::propriedadesMapa() {
    if (ui->tabWidget->count() <= 0)
        return;
    dynamic_cast<MapaWidget*>(ui->tabWidget->currentWidget())->edit();
}

void MainWindow::mostraMapa(Mapa* map){
    MapaWidget* mapa = new MapaWidget (nullptr, map);
    ui->tabWidget->addTab(mapa,map->titulo);
    saveMapa->setEnabled(true);
    editMapa->setEnabled(true);
    exportMapa->setEnabled(true);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
    if (ui->tabWidget->count() <= 0) {
        saveMapa->setEnabled(false);
        editMapa->setEnabled(false);
        exportMapa->setEnabled(false);
    }
}
