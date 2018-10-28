#ifndef QGRAPHICSTAIKOITEM_H
#define QGRAPHICSTAIKOITEM_H

#include <QGraphicsPixmapItem>
#include <instrumento.h>
#include <QGraphicsSceneMouseEvent>
#include <QVariant>
#include <QGraphicsScene>
#include <QtMath>

class QGraphicsTaikoItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QGraphicsTaikoItem(Instrumento taiko);
    QGraphicsTaikoItem(QGraphicsTaikoItem* taiko);
    Instrumento data;
    int height, width;
    void rotate(qreal da);
    void moveBy(qreal dx, qreal dy);

signals:
    void moved(QGraphicsTaikoItem* taiko, qreal dx, qreal dy);
    void rotated(QGraphicsTaikoItem* taiko, qreal da);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QPointF click_pos;

};

#endif // QGRAPHICSTAIKOITEM_H
