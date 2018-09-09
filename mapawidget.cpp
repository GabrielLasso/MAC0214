#include "mapawidget.h"
#include "ui_mapawidget.h"

MapaWidget::MapaWidget(QWidget *parent, Mapa *data) :
    QWidget(parent),
    ui(new Ui::MapaWidget)
{
    ui->setupUi(this);
    this->data = data;
    this->titulo = ui->musicNameLineEdit;
    this->equipe = ui->equipeLineEdit;
    this->cidade = ui->cidadeLineEdit;
    this->view = ui->view;
    this->titulo->setText(data->titulo);
    this->equipe->setText(data->equipe);
    this->cidade->setText(data->cidade);
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
            taiko_data.x = taiko->x();
            taiko_data.y = taiko->y();
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
    QPen pen3(QColor(0,0,0));
    QPen pen5(QColor(0,0,0));

    scene->clear();
    pen3.setWidth(3);
    pen5.setWidth(5);

    // Header
    QGraphicsTextItem *title = scene->addText(titulo->text());
    QGraphicsTextItem *titleHUD = scene->addText("Nome da música");
    QGraphicsTextItem *team = scene->addText(equipe->text());
    QGraphicsTextItem *teamHUD = scene->addText("Equipe");
    QGraphicsTextItem *city = scene->addText(cidade->text());
    QGraphicsTextItem *cityHUD = scene->addText("Cidade");
    title->setPos((titleHUD->boundingRect().width()-title->boundingRect().width())/2, -(data->height/2+1)*meter);
    titleHUD->setPos(-data->width/2*meter, -(data->height/2+1)*meter);
    team->setPos((-data->width*meter/2+teamHUD->boundingRect().width()-team->boundingRect().width())/2, -(data->height/2+1)*meter-24);
    teamHUD->setPos(-data->width/2*meter, -(data->height/2+1)*meter-24);
    city->setPos((data->width*meter/2+cityHUD->boundingRect().width()-city->boundingRect().width())/2, -(data->height/2+1)*meter-24);
    cityHUD->setPos(0,-(data->height/2+1)*meter-24);
    scene->addRect(-data->width/2*meter,-(data->height/2+1)*meter,data->width*meter,24,pen3);
    scene->addLine(-data->width/2*meter+titleHUD->boundingRect().width(), -(data->height/2+1)*meter+24, -data->width/2*meter+titleHUD->boundingRect().width(), -(data->height/2+1)*meter);
    scene->addRect(-data->width/2*meter,-(data->height/2+1)*meter-24,data->width*meter/2,24,pen3);
    scene->addLine(-data->width/2*meter+teamHUD->boundingRect().width(), -(data->height/2+1)*meter-24, -data->width/2*meter+teamHUD->boundingRect().width(), -(data->height/2+1)*meter);
    scene->addRect(0,-(data->height/2+1)*meter-24,data->width*meter/2,24,pen3);
    scene->addLine(cityHUD->boundingRect().width(), -(data->height/2+1)*meter-24, cityHUD->boundingRect().width(), -(data->height/2+1)*meter);

    // Grid
    scene->addLine(-data->width/2*meter+2,0,data->width/2*meter-2,0,pen5);
    scene->addLine(0,-data->height/2*meter+2,0,data->height/2*meter-2,pen5);
    for (i=-int(data->height/2);i<=data->height/2;i++){
        for(j=-int(data->width/2);j<=data->width/2;j++){
            if (j%2==0)
                scene->addLine(j*meter,-data->height*meter/2+1,j*meter,data->height*meter/2-1, pen3);
            else
                scene->addLine(j*meter,-data->height*meter/2,j*meter,data->height*meter/2);
        }
        if (i%2==0)
            scene->addLine(-data->width*meter/2+1,i*meter,data->width*meter/2-1,i*meter, pen3);
        else
            scene->addLine(-data->width*meter/2,i*meter,data->width*meter/2,i*meter);
    }
    scene->addLine(data->width/2*meter,-data->height/2*meter,data->width/2*meter,data->height/2*meter);
    scene->addLine(-data->width/2*meter,data->height/2*meter,data->width/2*meter,data->height/2*meter);
    scene->addLine(-data->width/2*meter,-data->height/2*meter,-data->width/2*meter,data->height/2*meter);
    scene->addLine(-data->width/2*meter,-data->height/2*meter,data->width/2*meter,-data->height/2*meter);

    // Taikos
    for (Instrumento taiko : taikos) {
        addInstrument(taiko.filename, taiko.x, taiko.y);
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
                Instrumento taiko_data = dynamic_cast<QGraphicsTaikoItem*>(taiko)->taiko;
                taiko_data.x = taiko->pos().rx();
                taiko_data.y = taiko->pos().ry();
                stream<<taiko_data.x<<","<<taiko_data.y<<","<<taiko_data.filename<<endl;
            }
        }
        file.close();
    }
}

void MapaWidget::addInstrument(QString name, qreal x=0, qreal y=0) {
    Instrumento taiko(x,y,name);
    QGraphicsTaikoItem *t = new QGraphicsTaikoItem(taiko);
    t->setOffset(-t->width/2,-t->height/2);
    t->setFlag(QGraphicsItem::ItemIsSelectable);
    t->setFlag(QGraphicsItem::ItemIsMovable);
    t->mapa_h = data->height;
    t->mapa_h = data->width;
    view->scene()->addItem(t);
}

void MapaWidget::on_horizontalSlider_sliderMoved(int position)
{
    view->zoom = position;
    view->setZoom();
}

void MapaWidget::on_add_taiko_clicked()
{
    foreach (QListWidgetItem* instrumento, instrumentos->selectedItems()) {
        addInstrument(instrumento->text());
    }
}

void MapaWidget::on_musicNameLineEdit_textEdited(const QString &arg1)
{
    data->titulo = arg1;
    updateScene(getTaikos());
}

void MapaWidget::on_equipeLineEdit_textEdited(const QString &arg1)
{
    data->equipe = arg1;
    updateScene(getTaikos());
}

void MapaWidget::on_cidadeLineEdit_textEdited(const QString &arg1)
{
    data->cidade = arg1;
    updateScene(getTaikos());
}
