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

class MapaScene : public QGraphicsScene
{
    Q_OBJECT
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

public slots:
    void onTaikoMoved(QGraphicsTaikoItem* taiko, qreal old_x, qreal old_y, qreal new_x, qreal new_y);
    void onTaikoRotated(QGraphicsTaikoItem* taiko, qreal old_alpha, qreal new_alpha);

protected:
    QUndoStack* undo_stack;
    void keyPressEvent(QKeyEvent * keyEvent) override;
};

#endif // MAPASCENE_H
