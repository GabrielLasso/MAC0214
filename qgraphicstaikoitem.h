#ifndef QGRAPHICSTAIKOITEM_H
#define QGRAPHICSTAIKOITEM_H

#include <QGraphicsPixmapItem>
#include <instrumento.h>
#include <QGraphicsSceneMouseEvent>
#include <QVariant>

class QGraphicsTaikoItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QGraphicsTaikoItem(Instrumento taiko);
    QGraphicsTaikoItem(QGraphicsTaikoItem* taiko);
    Instrumento data;
    int height, width;
    void rotate(qreal angle);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

signals:
    void moved(QGraphicsTaikoItem* taiko, qreal old_x, qreal old_y, qreal new_x, qreal new_y);
    void rotated(QGraphicsTaikoItem* taiko, qreal old_alpha, qreal new_alpha);
};

#endif // QGRAPHICSTAIKOITEM_H
