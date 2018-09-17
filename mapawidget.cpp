#include "mapawidget.h"
#include "ui_mapawidget.h"

MapaWidget::MapaWidget(QWidget *parent, Mapa *data) :
    QWidget(parent),
    ui(new Ui::MapaWidget)
{
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
    QGraphicsTextItem *title = scene->addText(data->titulo);
    QGraphicsTextItem *titleHUD = scene->addText("Nome da música");
    QGraphicsTextItem *team = scene->addText(data->equipe);
    QGraphicsTextItem *teamHUD = scene->addText("Equipe");
    QGraphicsTextItem *city = scene->addText(data->cidade);
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
        addInstrument(taiko.filename, taiko.x, taiko.y, taiko.angle);
    }
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
        updateScene(getTaikos());
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
                stream<<taiko_data.x<<","<<taiko_data.y<<","<<taiko_data.angle<<","<<taiko_data.filename<<endl;
            }
        }
        file.close();
    }
}

void MapaWidget::addInstrument(QString name, qreal x=0, qreal y=0, qreal angle=0) {
    Instrumento taiko(x,y,angle,name);
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

void MapaWidget::on_pushButton_clicked()
{
    edit();
}

void MapaWidget::on_pushButton_2_clicked()
{
    QImage white_bg (50*(int(data->width)+2),50*(int(data->height)+2),QImage::Format_ARGB32_Premultiplied);
    white_bg.fill(QColor(Qt::white));
    QPainter p(&white_bg);
    scene->render(&p);
    p.end();
    white_bg.save("XXX.bmp");
}
