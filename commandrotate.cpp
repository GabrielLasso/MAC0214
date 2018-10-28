#include "commandrotate.h"


CommandRotate::CommandRotate(QSet<QGraphicsItem *> items, qreal da, QUndoCommand *parent)
    : QUndoCommand (parent)
{
    this->items = items;
    this->da = da;
}


void CommandRotate::undo()
{
    foreach (QGraphicsItem* item, items) {
        QGraphicsTaikoItem* taiko = dynamic_cast<QGraphicsTaikoItem*>(item);
        taiko->setRotation(taiko->rotation() - da);
    }
}

void CommandRotate::redo()
{
    foreach (QGraphicsItem* item, items) {
        QGraphicsTaikoItem* taiko = dynamic_cast<QGraphicsTaikoItem*>(item);
        taiko->setRotation(taiko->rotation() + da);
    }
}

bool CommandRotate::mergeWith(const QUndoCommand *command)
{
    const CommandRotate *rotateCommand = static_cast<const CommandRotate *>(command);

    if (this->items != rotateCommand->items)
        return false;

    da += rotateCommand->da;

    return true;
}
