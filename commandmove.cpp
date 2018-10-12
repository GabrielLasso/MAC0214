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
//    mItem->setPos(toX, toY);
}
