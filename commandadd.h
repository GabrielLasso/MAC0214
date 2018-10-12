#ifndef COMMANDADD_H
#define COMMANDADD_H

#include <QUndoCommand>
#include <QGraphicsScene>
#include "qgraphicstaikoitem.h"

class CommandAdd : public QUndoCommand
{
public:
    CommandAdd(QGraphicsScene* scene, QGraphicsTaikoItem *item, QUndoCommand* parent = nullptr);
    void undo() override;
    void redo() override;
private:
    QGraphicsScene* scene;
    QGraphicsItem* mItem;
};

#endif // COMMANDADD_H
