#ifndef QGRAPHICSTAIKOITEM_H
#define QGRAPHICSTAIKOITEM_H

#include <QGraphicsPixmapItem>
#include <instrumento.h>
#include <QGraphicsSceneMouseEvent>
#include <QVariant>
#include <QGraphicsScene>
#include <QtMath>
#include <QSet>

class QGraphicsTaikoItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QGraphicsTaikoItem(Instrumento taiko);
    QGraphicsTaikoItem(QGraphicsTaikoItem* taiko);
    Instrumento data;
    int height, width;

signals:
    void moved(QSet<QGraphicsItem*> items, qreal dx, qreal dy);
    void rotated(QSet<QGraphicsItem*> items, qreal da);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QPointF click_pos;

};

#endif // QGRAPHICSTAIKOITEM_H
