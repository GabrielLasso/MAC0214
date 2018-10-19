#include "qgraphicstaikoitem.h"

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
    setPos(taiko->x(), taiko->y());
    this->height = QPixmap(":/res/Image/"+taiko->data.filename).height();
    this->width = QPixmap(":/res/Image/"+taiko->data.filename).width();
    this->data = taiko->data;
    this->data.x = taiko->x();
    this->data.y= taiko->y();
    this->setRotation(taiko->data.angle);
}

void QGraphicsTaikoItem::rotate(qreal angle) {
    data.angle = rotation() + angle;
    emit rotated(this, rotation(), rotation() + angle);
    this->setRotation(data.angle);
}

void QGraphicsTaikoItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    click_pos += event->lastPos() - event->pos();
    QGraphicsItem::mouseMoveEvent(event);
}

void QGraphicsTaikoItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    click_pos = QPointF();
    QGraphicsItem::mousePressEvent(event);
}


void QGraphicsTaikoItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    click_pos += event->lastPos() - event->pos();
    foreach (QGraphicsItem* item, this->scene()->selectedItems())
        emit moved(static_cast<QGraphicsTaikoItem*>(item), item->x()-click_pos.rx(), item->y()-click_pos.ry(), item->x(), item->y());
    QGraphicsItem::mouseReleaseEvent(event);
}
