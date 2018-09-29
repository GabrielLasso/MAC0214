#include "mapaview.h"

MapaView::MapaView(QWidget* parent) :
    QGraphicsView(parent) {
    zoom = 50;
    //setDragMode(QGraphicsView::ScrollHandDrag);
    setDragMode(QGraphicsView::RubberBandDrag);
}

void MapaView::setZoom(){
    QMatrix matrix;
    qreal scale = qPow(2,((qreal(zoom)-50)/17));
    matrix.scale(scale,scale);
    setTransform(QTransform(matrix));
}

void MapaView::wheelEvent(QWheelEvent *event) {
    if (scene()->selectedItems().empty())
        QGraphicsView::wheelEvent(event);

    foreach(QGraphicsItem* item, scene()->selectedItems())
    {
        if (event->delta() > 0) {
            dynamic_cast<QGraphicsTaikoItem*>(item)->rotate(5);
        }
        else {
            dynamic_cast<QGraphicsTaikoItem*>(item)->rotate(-5);
        }
    }
}
