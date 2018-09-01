#include "mapaview.h"

MapaView::MapaView(QWidget* parent):QGraphicsView (parent) {
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
    if (event->delta() > 0) {
        zoom += 1;
    }
    else {
        zoom -= 1;
    }
    setZoom();
}