#include "mapawidget.h"
#include "ui_mapawidget.h"

MapaWidget::MapaWidget(QWidget *parent, Mapa *data) :
    QWidget(parent),
    ui(new Ui::MapaWidget)
{
    ppm = 50; // Pixel per meter
    ui->setupUi(this);
    this->data = data;
    this->view = ui->view;
    instrumentos = ui->taiko_list;
    createScene();
    loadList();
}

MapaWidget::~MapaWidget()
{
    delete ui;
}

void MapaWidget::loadList() {
    QDirIterator dirIt("Image/",QDirIterator::Subdirectories);
    while (dirIt.hasNext()) {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile()) {
            QString filename = dirIt.fileName().split(".")[0];
            QListWidgetItem* instr = new QListWidgetItem(QIcon("Image/"+filename), filename);
            instrumentos->addItem(instr);
        }
    }
    instrumentos->sortItems();
}

void MapaWidget::createScene() {
    scene = new MapaScene(this);
    view->setScene(scene);
    foreach (Instrumento taiko, *data->taikos) {
        scene->addInstrument(taiko.filename, taiko.x, taiko.y, taiko.angle);
    }
    scene->updateScene(data, ppm);
}

void MapaWidget::edit() {
    QDialog* dialog = new QDialog;
    QFormLayout form(dialog);
    QLineEdit* mTitle= new QLineEdit(data->titulo, dialog);
    QLineEdit* mTeam= new QLineEdit(data->equipe, dialog);
    QLineEdit* mCity= new QLineEdit(data->cidade, dialog);
    QDoubleSpinBox* mWidth= new QDoubleSpinBox(dialog);
    mWidth->setValue(data->width);
    QDoubleSpinBox* mHeight = new QDoubleSpinBox(dialog);;
    mHeight->setValue(data->height);
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
        data->height = mHeight->value();
        data->width = mWidth->value();
        data->titulo = mTitle->text();
        data->equipe = mTeam->text();
        data->cidade = mCity->text();
        scene->updateScene(data, ppm);
    }
}

void MapaWidget::save(QString filename){
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)){
        QTextStream stream (&file);
        stream<<data->titulo<<endl;
        stream<<data->equipe<<endl;
        stream<<data->cidade<<endl;
        stream<<data->height<<","<<data->width<<endl;
        foreach (QGraphicsItem* taiko, scene->items()){
            if (taiko->type() == QGraphicsTaikoItem::Type) {
                Instrumento taiko_data = dynamic_cast<QGraphicsTaikoItem*>(taiko)->data;
                taiko_data.x = taiko->pos().rx();
                taiko_data.y = taiko->pos().ry();
                stream<<taiko_data.x<<","<<taiko_data.y<<","<<taiko_data.angle<<","<<taiko_data.filename<<endl;
            }
        }
        file.close();
    }
}

void MapaWidget::on_horizontalSlider_sliderMoved(int position)
{
    view->zoom = position;
    view->setZoom();
}

void MapaWidget::on_add_taiko_clicked()
{
    foreach (QListWidgetItem* instrumento, instrumentos->selectedItems()) {
        scene->addInstrument(instrumento->text());
    }
    scene->updateScene(data, ppm);
}

void MapaWidget::exportToImage(QString filename) {
    QImage white_bg (ppm*(int(data->width)+1)+200,ppm*(int(data->height)+1)+24,QImage::Format_ARGB32_Premultiplied);
    white_bg.fill(QColor(Qt::white));
    QPainter p(&white_bg);
    scene->render(&p);
    p.end();
    white_bg.save(filename);
}

