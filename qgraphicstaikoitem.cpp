#include "qgraphicstaikoitem.h"

QGraphicsTaikoItem::QGraphicsTaikoItem(Instrumento taiko):QGraphicsPixmapItem(QPixmap("Image/"+taiko.filename))
{
    setPos(taiko.x, taiko.y);
    this->height = QPixmap("Image/"+taiko.filename).height();
    this->width = QPixmap("Image/"+taiko.filename).width();
    this->taiko = taiko;
    this->setRotation(taiko.angle);
}

void QGraphicsTaikoItem::rotate(qreal angle) {
    taiko.angle += angle;
    this->setRotation(taiko.angle);
}
