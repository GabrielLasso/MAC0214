#include "qgraphicstaikoitem.h"

#include <QSet>

QGraphicsTaikoItem::QGraphicsTaikoItem(Instrumento taiko):QGraphicsPixmapItem(QPixmap(":/res/Image/"+taiko.filename))
{
    setPos(taiko.x, taiko.y);
    this->height = QPixmap(":/res/Image/"+taiko.filename).height();
    this->width = QPixmap(":/res/Image/"+taiko.filename).width();
    this->data = taiko;
    this->setRotation(taiko.angle);
}

QGraphicsTaikoItem::QGraphicsTaikoItem(QGraphicsTaikoItem* taiko):QGraphicsPixmapItem(QPixmap(":/res/Image/"+taiko->data.filename))
{
    this->height = QPixmap(":/res/Image/"+taiko->data.filename).height();
    this->width = QPixmap(":/res/Image/"+taiko->data.filename).width();
    this->data = taiko->data;
    this->data.x = taiko->x();
    this->data.y= taiko->y();
    this->setPos(taiko->x(), taiko->y());
    this->setRotation(taiko->data.angle);
}

void QGraphicsTaikoItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qreal a = qDegreesToRadians(rotation());
    QTransform rotationMatrix(qCos(a), qSin(a), -qSin(a), qCos(a), 0, 0);
    click_pos = event->scenePos() - rotationMatrix.map(event->pos());
    QGraphicsItem::mousePressEvent(event);
}

void QGraphicsTaikoItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
}

void QGraphicsTaikoItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qreal dx = x() - click_pos.rx();
    qreal dy = y() - click_pos.ry();
    QSet<QGraphicsItem*> items = QSet<QGraphicsItem*>::fromList(this->scene()->selectedItems());
    if (int(dx) != 0 || int(dy) != 0) {
        emit moved(items, dx, dy);
        foreach (QGraphicsItem* item, this->scene()->selectedItems()) {
            item->setPos(item->x()-dx, item->y()-dy);
        }
    }
    QGraphicsItem::mouseReleaseEvent(event);
}

