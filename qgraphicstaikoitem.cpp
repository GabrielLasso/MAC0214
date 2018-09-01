#include "qgraphicstaikoitem.h"

QGraphicsTaikoItem::QGraphicsTaikoItem(Instrumento taiko):QGraphicsPixmapItem(QPixmap("Image/"+taiko.filename))
{
    this->height = QPixmap("Image/"+taiko.filename).height();
    this->width = QPixmap("Image/"+taiko.filename).width();
    this->taiko = taiko;
}


void QGraphicsTaikoItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setPos(this->pos() + event->pos());
//    if (event->pos().manhattanLength() >= (mapa_h+mapa_w)/2)
//        delete this;
}

void QGraphicsTaikoItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    this->setPos(this->pos() + event->pos());
}

