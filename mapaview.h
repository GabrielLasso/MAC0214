#ifndef MAPAVIEW_H
#define MAPAVIEW_H
#include <QWheelEvent>
#include <QGraphicsView>
#include <QMatrix>
#include <QtMath>
#include <QPointF>
#include "qgraphicstaikoitem.h"

class MapaView : public QGraphicsView
{
    Q_OBJECT

public:
    MapaView(QWidget* parent);
    int zoom;
    void setZoom();

protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // MAPAVIEW_H
