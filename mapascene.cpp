#include "mapascene.h"

MapaScene::MapaScene(QObject* parent):QGraphicsScene(parent)
{

}

void MapaScene::keyPressEvent(QKeyEvent * keyEvent)
{
    QList<QGraphicsItem*> selectedItems = this->selectedItems();
    switch(keyEvent->key()) {
    case Qt::Key_Up:
        foreach(QGraphicsItem* item, selectedItems)
        {
            item->moveBy(0,-1);
        }
        break;
    case Qt::Key_Down:
        foreach(QGraphicsItem* item, selectedItems)
        {
            item->moveBy(0,1);
        }
        break;
    case Qt::Key_Left:
        if (keyEvent->modifiers().testFlag(Qt::ShiftModifier)) {
            foreach(QGraphicsItem* item, selectedItems)
            {
                dynamic_cast<QGraphicsTaikoItem*>(item)->rotate(-5);
            }
        } else {
            foreach(QGraphicsItem* item, selectedItems)
            {
                item->moveBy(-1,0);
            }
        }
        break;
    case Qt::Key_Right:
        if (keyEvent->modifiers().testFlag(Qt::ShiftModifier)) {
            foreach(QGraphicsItem* item, selectedItems)
            {
                dynamic_cast<QGraphicsTaikoItem*>(item)->rotate(5);
            }
        } else {
            foreach(QGraphicsItem* item, selectedItems)
            {
                item->moveBy(1,0);
            }
        }
        break;
    case Qt::Key_Delete:
        foreach(QGraphicsItem* item, selectedItems)
        {
            delete item;
        }
        updateScene(data, ppm);
    break;
    }
}

void MapaScene::updateScene(Mapa* data, int ppm) {
    int i,j;
    QPen pen3(QColor(0,0,0));
    QPen pen5(QColor(0,0,0));
    QList<Instrumento> taikos = getTaikoItems();
    this->data = data;
    this->ppm = ppm;

    clear();
    pen3.setWidth(3);
    pen5.setWidth(5);

    // Header
    QGraphicsTextItem *title = addText(data->titulo);
    QGraphicsTextItem *titleHUD = addText("Nome da música");
    title->setPos((200+ppm+titleHUD->boundingRect().width()-title->boundingRect().width())/2, -(data->height/2+1)*ppm);
    titleHUD->setPos(-data->width/2*ppm, -(data->height/2+1)*ppm);
    addRect(-data->width/2*ppm,-(data->height/2+1)*ppm,data->width*ppm+200+ppm,24,pen3);
    addLine(-data->width/2*ppm+titleHUD->boundingRect().width(), -(data->height/2+1)*ppm+24, -data->width/2*ppm+titleHUD->boundingRect().width(), -(data->height/2+1)*ppm);

    QGraphicsTextItem *team = addText(data->equipe);
    QGraphicsTextItem *teamHUD = addText("Equipe");
    team->setPos(((200+ppm)/2-data->width*ppm/2+teamHUD->boundingRect().width()-team->boundingRect().width())/2, -(data->height/2+1)*ppm-24);
    teamHUD->setPos(-data->width/2*ppm, -(data->height/2+1)*ppm-24);
    addRect(-data->width/2*ppm,-(data->height/2+1)*ppm-24,data->width*ppm/2+125,24,pen3);
    addLine(-data->width/2*ppm+teamHUD->boundingRect().width(), -(data->height/2+1)*ppm-24, -data->width/2*ppm+teamHUD->boundingRect().width(), -(data->height/2+1)*ppm);

    QGraphicsTextItem *city = addText(data->cidade);
    QGraphicsTextItem *cityHUD = addText("Cidade");
    city->setPos((200+ppm)/2+cityHUD->boundingRect().width() + ((200+ppm*(1+data->width))/2-cityHUD->boundingRect().width())/2-city->boundingRect().width()/2, -(data->height/2+1)*ppm-24);
    cityHUD->setPos((200+ppm)/2,-(data->height/2+1)*ppm-24);
    addRect((200+ppm)/2,-(data->height/2+1)*ppm-24,data->width*ppm/2+(200+ppm)/2,24,pen3);
    addLine((200+ppm)/2+cityHUD->boundingRect().width(), -(data->height/2+1)*ppm-24, (200+ppm)/2+cityHUD->boundingRect().width(), -(data->height/2+1)*ppm);

    // Grid
    addLine(-data->width/2*ppm+2,0,data->width/2*ppm-2,0,pen5);
    addLine(0,-data->height/2*ppm+2,0,data->height/2*ppm-2,pen5);
    for (i=-int(data->height/2);i<=data->height/2;i++){
        for(j=-int(data->width/2);j<=data->width/2;j++){
            if (j%2==0)
                addLine(j*ppm,-data->height*ppm/2+1,j*ppm,data->height*ppm/2-1, pen3);
            else
                addLine(j*ppm,-data->height*ppm/2,j*ppm,data->height*ppm/2);
        }
        if (i%2==0)
            addLine(-data->width*ppm/2+1,i*ppm,data->width*ppm/2-1,i*ppm, pen3);
        else
            addLine(-data->width*ppm/2,i*ppm,data->width*ppm/2,i*ppm);
    }
    addLine(data->width/2*ppm,-data->height/2*ppm,data->width/2*ppm,data->height/2*ppm);
    addLine(-data->width/2*ppm,data->height/2*ppm,data->width/2*ppm,data->height/2*ppm);
    addLine(-data->width/2*ppm,-data->height/2*ppm,-data->width/2*ppm,data->height/2*ppm);
    addLine(-data->width/2*ppm,-data->height/2*ppm,data->width/2*ppm,-data->height/2*ppm);

    // Taikos
    for (Instrumento taiko : taikos) {
        addInstrument(taiko.filename, taiko.x, taiko.y, taiko.angle);
    }

    // Instrument List
    QHash<QString, int> instrument_hash;
    addRect((data->width/2+1)*ppm, -data->height/2*ppm,200,data->height*ppm);
    QGraphicsTextItem *instrumentos_title = addText("Instrumentos");
    instrumentos_title->setPos((data->width/2+1)*ppm+100-instrumentos_title->boundingRect().width()/2, -data->height/2*ppm);
    for (Instrumento taiko : taikos) {
        instrument_hash.insert(taiko.filename,instrument_hash.value(taiko.filename)+1);
    }
    QHashIterator<QString, int> iterator(instrument_hash);
    for (i = 2; iterator.hasNext(); i++) {
        iterator.next();
        QGraphicsTextItem *instrument_name = addText(iterator.key());
        instrument_name->setPos((data->width/2+1)*ppm, -data->height/2*ppm+16*i);
        QGraphicsTextItem *instrument_count = addText(QString::number(iterator.value()));
        instrument_count->setPos((data->width/2+1)*ppm+184, -data->height/2*ppm+16*i);
    }
}

void MapaScene::addInstrument(QString name, qreal x, qreal y, qreal angle) {
    Instrumento taiko(x,y,angle,name);
    QGraphicsTaikoItem *t = new QGraphicsTaikoItem(taiko);
    t->setOffset(-t->width/2,-t->height/2);
    t->setFlag(QGraphicsItem::ItemIsSelectable);
    t->setFlag(QGraphicsItem::ItemIsMovable);
    addItem(t);
}

QList<Instrumento> MapaScene::getTaikoItems() {
    QList<Instrumento> taikos;
    foreach (QGraphicsItem* taiko, items()){
        if (taiko->type() == QGraphicsTaikoItem::Type) {
            Instrumento taiko_data = dynamic_cast<QGraphicsTaikoItem*>(taiko)->taiko;
            taiko_data.x = taiko->x();
            taiko_data.y = taiko->y();
            taikos.append(taiko_data);
        }
    }
    return taikos;
}
