#ifndef QGRAPHICSTAIKOITEM_H
#define QGRAPHICSTAIKOITEM_H

#include <QGraphicsPixmapItem>
#include <instrumento.h>

class QGraphicsTaikoItem : public QGraphicsPixmapItem
{
public:
    QGraphicsTaikoItem(Instrumento taiko);
    Instrumento taiko;
};

#endif // QGRAPHICSTAIKOITEM_H
