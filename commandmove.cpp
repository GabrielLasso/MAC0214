#include "commandmove.h"

CommandMove::CommandMove(QSet<QGraphicsItem*> items, qreal dx, qreal dy, QUndoCommand* parent)
    : QUndoCommand (parent)
{
    this->items = items;
    this->dx = dx;
    this->dy = dy;
}

void CommandMove::undo()
{
    foreach (QGraphicsItem* item, items) {
        QGraphicsTaikoItem* taiko = dynamic_cast<QGraphicsTaikoItem*>(item);
        taiko->setPos(taiko->x()-dx, taiko->y()-dy);
    }
}

void CommandMove::redo()
{
    foreach (QGraphicsItem* item, items) {
        QGraphicsTaikoItem* taiko = dynamic_cast<QGraphicsTaikoItem*>(item);
        taiko->setPos(taiko->x()+dx, taiko->y()+dy);
    }
}

bool CommandMove::mergeWith(const QUndoCommand *command)
{
    const CommandMove *moveCommand = static_cast<const CommandMove *>(command);

    if (this->items != moveCommand->items)
        return false;

    dx += moveCommand->dx;
    dy += moveCommand->dy;

    return true;
}
