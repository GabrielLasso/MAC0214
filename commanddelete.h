#ifndef COMMANDDELETE_H
#define COMMANDDELETE_H

#include <QUndoCommand>
#include <QGraphicsScene>
#include "qgraphicstaikoitem.h"

class CommandDelete : public QUndoCommand
{
public:
    CommandDelete(QGraphicsScene* scene, QGraphicsTaikoItem *item, QUndoCommand* parent = nullptr);
    void undo() override;
    void redo() override;
private:
    QGraphicsScene* scene;
    QGraphicsItem* mItem;
};
#endif // COMMANDDELETE_H
