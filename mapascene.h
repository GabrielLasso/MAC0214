#ifndef MAPASCENE_H
#define MAPASCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QKeyEvent>
#include "qgraphicstaikoitem.h"
#include "mapa.h"
#include <QUndoStack>
#include "commandmove.h"
#include "commandrotate.h"
#include "commandadd.h"
#include "commanddelete.h"

class MapaScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MapaScene(QObject* parent);
    void updateScene(Mapa* data, int ppm);
    void addInstrument(QString name, qreal x=0, qreal y=0, qreal angle=0, bool newInstrument = true);
    QList<QGraphicsTaikoItem*> getTaikoItems();
    Mapa* data;
    int ppm;
    static QList<QGraphicsTaikoItem*> clipboard;
    void copy();
    void paste();

private:
    void removeItemsAndClearBackground();

public slots:
    void onTaikoMoved(QGraphicsTaikoItem* taiko, qreal dx, qreal dy);
    void onTaikoRotated(QGraphicsTaikoItem* taiko, qreal da);

protected:
    QUndoStack* undo_stack;
    void keyPressEvent(QKeyEvent * keyEvent) override;
};

#endif // MAPASCENE_H

