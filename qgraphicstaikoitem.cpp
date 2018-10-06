#include "qgraphicstaikoitem.h"

QGraphicsTaikoItem::QGraphicsTaikoItem(Instrumento taiko):QGraphicsPixmapItem(QPixmap("Image/"+taiko.filename))
{
    setPos(taiko.x, taiko.y);
    this->height = QPixmap("Image/"+taiko.filename).height();
    this->width = QPixmap("Image/"+taiko.filename).width();
    this->data = taiko;
    this->setRotation(taiko.angle);
}

QGraphicsTaikoItem::QGraphicsTaikoItem(QGraphicsTaikoItem* taiko):QGraphicsPixmapItem(QPixmap("Image/"+taiko->data.filename))
{
    setPos(taiko->x(), taiko->y());
    this->height = QPixmap("Image/"+taiko->data.filename).height();
    this->width = QPixmap("Image/"+taiko->data.filename).width();
    this->data = taiko->data;
    this->data.x = taiko->x();
    this->data.y= taiko->y();
    this->setRotation(taiko->data.angle);
}

void QGraphicsTaikoItem::rotate(qreal angle) {
    data.angle += angle;
    this->setRotation(data.angle);
}
