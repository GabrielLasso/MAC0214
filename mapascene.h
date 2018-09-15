#ifndef MAPASCENE_H
#define MAPASCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QKeyEvent>
#include "qgraphicstaikoitem.h"

class MapaScene : public QGraphicsScene
{
public:
    MapaScene(QObject* parent);

protected:
    void keyPressEvent(QKeyEvent * keyEvent) override;
};

#endif // MAPASCENE_H
