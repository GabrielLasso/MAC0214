#include "qgraphicstaikoitem.h"

QGraphicsTaikoItem::QGraphicsTaikoItem(Instrumento taiko):QGraphicsPixmapItem(QPixmap("Image/"+taiko.filename))
{
    this->taiko = taiko;
}
