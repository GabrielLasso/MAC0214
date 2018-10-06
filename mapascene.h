#ifndef MAPASCENE_H
#define MAPASCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QKeyEvent>
#include "qgraphicstaikoitem.h"
#include "mapa.h"

class MapaScene : public QGraphicsScene
{
public:
    MapaScene(QObject* parent);
    void updateScene(Mapa* data, int ppm);
    void addInstrument(QString name, qreal x=0, qreal y=0, qreal angle=0);
    QList<Instrumento> getTaikoItems();
    Mapa* data;
    int ppm;
    static QList<QGraphicsTaikoItem*> clipboard;
    void copy();
    void paste();

protected:
    void keyPressEvent(QKeyEvent * keyEvent) override;
};

#endif // MAPASCENE_H
