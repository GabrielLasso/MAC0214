#include "commandmove.h"

CommandMove::CommandMove(QGraphicsTaikoItem *item, qreal fromX, qreal fromY, qreal toX, qreal toY, QUndoCommand* parent)
    : QUndoCommand (parent)
{
    mItem = item;
    this->fromX = fromX;
    this->fromY = fromY;
    this->toX = toX;
    this->toY = toY;
}

void CommandMove::undo()
{
    mItem->setPos(fromX, fromY);
}

void CommandMove::redo()
{
    mItem->setPos(toX, toY);
}

bool CommandMove::mergeWith(const QUndoCommand *command)
{
    const CommandMove *moveCommand = static_cast<const CommandMove *>(command);
    QGraphicsTaikoItem *item = moveCommand->mItem;

    if (mItem != item)
        return false;

    toX = item->x();
    toY = item->y();

    return true;
}
