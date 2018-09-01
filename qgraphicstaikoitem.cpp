#include "qgraphicstaikoitem.h"

QGraphicsTaikoItem::QGraphicsTaikoItem(Instrumento taiko):QGraphicsPixmapItem(QPixmap("Image/"+taiko.filename))
{
    setPos(taiko.x, taiko.y);
    this->height = QPixmap("Image/"+taiko.filename).height();
    this->width = QPixmap("Image/"+taiko.filename).width();
    this->taiko = taiko;
}
