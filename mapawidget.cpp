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
    scale = 50;
    createScene();
}

MapaWidget::~MapaWidget()
{
    delete ui;
}

QList<Instrumento> MapaWidget::getTaikos() {
    QList<Instrumento> taikos;
    foreach (QGraphicsItem* taiko, scene->items()){
        if (taiko->type() == QGraphicsTaikoItem::Type) {
            Instrumento taiko_data = dynamic_cast<QGraphicsTaikoItem*>(taiko)->taiko;
            taiko_data.x += taiko->x()/scale;
            taiko_data.y += taiko->y()/scale;
            taikos.append(taiko_data);
        }
    }
    return taikos;
}

void MapaWidget::createScene() {
    scene = new QGraphicsScene(this);
    view->setScene(scene);
    updateScene(*data->taikos);
}

void MapaWidget::updateScene(QList<Instrumento> taikos) {
    int i,j;
    QPen pen(QColor(0,0,0));
    scene->clear();
    pen.setWidth(3);
    scene->addLine(-data->width/2*scale+1,0,data->width/2*scale-1,0,pen);
    scene->addLine(0,-data->height/2*scale+1,0,data->height/2*scale-1,pen);
    for (i=-int(data->height/2);i<=data->height/2;i++){
        for(j=-int(data->width/2);j<=data->width/2;j++){
            scene->addLine(j*scale,-data->height*scale/2,j*scale,data->height*scale/2);
        }
        scene->addLine(-data->width*scale/2,i*scale,data->width*scale/2,i*scale);
    }
    scene->addLine(data->width/2*scale,-data->height/2*scale,data->width/2*scale,data->height/2*scale);
    scene->addLine(-data->width/2*scale,data->height/2*scale,data->width/2*scale,data->height/2*scale);
    scene->addLine(-data->width/2*scale,-data->height/2*scale,-data->width/2*scale,data->height/2*scale);
    scene->addLine(-data->width/2*scale,-data->height/2*scale,data->width/2*scale,-data->height/2*scale);

    for (Instrumento taiko : taikos) {
        QGraphicsTaikoItem *t = new QGraphicsTaikoItem(taiko);
        t->setOffset(taiko.x*scale,taiko.y*scale);
        t->setFlag(QGraphicsItem::ItemIsMovable);
        t->setFlag(QGraphicsItem::ItemIsSelectable);
        scene->addItem(t);
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
                taiko_data.x += taiko->x()/scale;
                taiko_data.y += taiko->y()/scale;
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
    t->setFlag(QGraphicsItem::ItemIsMovable);
    view->scene()->addItem(t);
}

void MapaWidget::on_add_okedo_clicked()
{
    addInstrument("okedo");
}

void MapaWidget::on_add_shime_clicked()
{
    addInstrument("shime");
    foreach (QGraphicsItem *taiko, scene->selectedItems()) {
        taiko->moveBy(10,10);

    }
}

void MapaWidget::on_zoom_in_clicked()
{
    QList<Instrumento> taikos = getTaikos();
    scale *= 1.1;
    updateScene(taikos);
}

void MapaWidget::on_zoom_out_clicked()
{
    QList<Instrumento> taikos = getTaikos();
    scale /= 1.1;
    updateScene(taikos);
}
