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

    if (!this->scene()->selectedItems().empty()) {
        QGraphicsTaikoItem* item = static_cast<QGraphicsTaikoItem*>(this->scene()->selectedItems().first());
        QSet<QGraphicsItem*> items = QSet<QGraphicsItem*>::fromList(this->scene()->selectedItems());
        if (event->delta() > 0) {
            emit item->rotated(items, 5);
        }
        else {
            emit item->rotated(items, -5);
        }
    }
}
