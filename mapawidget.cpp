#include "mapawidget.h"
#include "ui_mapawidget.h"

MapaWidget::MapaWidget(QWidget *parent, Mapa *data) :
    QWidget(parent),
    ui(new Ui::MapaWidget)
{
    ui->setupUi(this);
    this->data = data;
    this->titulo = ui->titulo;
    this->view = ui->view;
    this->titulo->setText(data->titulo);
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
}

QList<Instrumento> MapaWidget::getTaikos() {
    QList<Instrumento> taikos;
    foreach (QGraphicsItem* taiko, scene->items()){
        if (taiko->type() == QGraphicsTaikoItem::Type) {
            Instrumento taiko_data = dynamic_cast<QGraphicsTaikoItem*>(taiko)->taiko;
            taiko_data.x += taiko->x();
            taiko_data.y += taiko->y();
            dynamic_cast<QGraphicsTaikoItem*>(taiko)->mapa_h = data->height;
            dynamic_cast<QGraphicsTaikoItem*>(taiko)->mapa_h = data->width;
            taikos.append(taiko_data);
        }
    }
    return taikos;
}

void MapaWidget::createScene() {
    scene = new MapaScene(this);
    view->setScene(scene);
    updateScene(*data->taikos);
}

void MapaWidget::updateScene(QList<Instrumento> taikos) {
    int i,j, meter = 50;
    QPen pen(QColor(0,0,0));
    scene->clear();
    pen.setWidth(3);
    scene->addLine(-data->width/2*meter+1,0,data->width/2*meter-1,0,pen);
    scene->addLine(0,-data->height/2*meter+1,0,data->height/2*meter-1,pen);
    for (i=-int(data->height/2);i<=data->height/2;i++){
        for(j=-int(data->width/2);j<=data->width/2;j++){
            scene->addLine(j*meter,-data->height*meter/2,j*meter,data->height*meter/2);
        }
        scene->addLine(-data->width*meter/2,i*meter,data->width*meter/2,i*meter);
    }
    scene->addLine(data->width/2*meter,-data->height/2*meter,data->width/2*meter,data->height/2*meter);
    scene->addLine(-data->width/2*meter,data->height/2*meter,data->width/2*meter,data->height/2*meter);
    scene->addLine(-data->width/2*meter,-data->height/2*meter,-data->width/2*meter,data->height/2*meter);
    scene->addLine(-data->width/2*meter,-data->height/2*meter,data->width/2*meter,-data->height/2*meter);

    for (Instrumento taiko : taikos) {
        addInstrument(taiko.filename);
    }
}

void MapaWidget::save(QString filename){
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)){
        QTextStream stream (&file);
        stream<<data->titulo<<endl;
        stream<<data->height<<","<<data->width<<endl;
        foreach (QGraphicsItem* taiko, scene->items()){
            if (taiko->type() == QGraphicsTaikoItem::Type) {
                Instrumento taiko_data = dynamic_cast<QGraphicsTaikoItem*>(taiko)->taiko;
                taiko_data.x += taiko->x();
                taiko_data.y += taiko->y();
                stream<<taiko_data.x<<","<<taiko_data.y<<","<<taiko_data.filename<<endl;
            }
        }
        file.close();
    }
}

void MapaWidget::addInstrument(QString name) {
    Instrumento taiko;
    taiko.filename = name;
    QGraphicsTaikoItem *t = new QGraphicsTaikoItem(taiko);
    t->setOffset(-t->width/2,-t->height/2);
    t->setFlag(QGraphicsItem::ItemIsSelectable);
    t->mapa_h = data->height;
    t->mapa_h = data->width;
    view->scene()->addItem(t);
}

void MapaWidget::on_horizontalSlider_sliderMoved(int position)
{
    QMatrix matrix;
    qreal zoom = qPow(2,((qreal(position)-50)/17));
    matrix.scale(zoom,zoom);
    view->setTransform(QTransform(matrix));
}

void MapaWidget::on_add_taiko_clicked()
{
    foreach (QListWidgetItem* instrumento, instrumentos->selectedItems()) {
        addInstrument(instrumento->text());
    }
}
