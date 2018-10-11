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
    data.angle += angle;
    this->setRotation(data.angle);
}

QVariant QGraphicsTaikoItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange){
        emit moved(x(), y(), value.toPointF().rx(), value.toPointF().ry());
    } else if (change == ItemRotationChange) {
        emit rotated(rotation(), value.toReal());
    }
    return QGraphicsItem::itemChange(change, value);
}
