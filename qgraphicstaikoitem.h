#ifndef QGRAPHICSTAIKOITEM_H
#define QGRAPHICSTAIKOITEM_H

#include <QGraphicsPixmapItem>
#include <instrumento.h>
#include <QGraphicsSceneMouseEvent>

class QGraphicsTaikoItem : public QGraphicsPixmapItem
{
public:
    QGraphicsTaikoItem(Instrumento taiko);
    Instrumento taiko;
    int height, width;
    void rotate(qreal angle);
};

#endif // QGRAPHICSTAIKOITEM_H
