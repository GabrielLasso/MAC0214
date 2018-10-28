#include "commandmove.h"

CommandMove::CommandMove(QGraphicsTaikoItem *item, qreal dx, qreal dy, QUndoCommand* parent)
    : QUndoCommand (parent)
{
    mItem = item;
    this->dx = dx;
    this->dy = dy;
}

void CommandMove::undo()
{
    mItem->setPos(mItem->x()-dx, mItem->y()-dy);
}

void CommandMove::redo()
{
    mItem->setPos(mItem->x()+dx, mItem->y()+dy);
}

bool CommandMove::mergeWith(const QUndoCommand *command)
{
    const CommandMove *moveCommand = static_cast<const CommandMove *>(command);
    QGraphicsTaikoItem *item = moveCommand->mItem;

    if (mItem != item)
        return false;

    dx += moveCommand->dx;
    dy += moveCommand->dy;

    return true;
}
