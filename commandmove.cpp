#include "commandmove.h"

CommandMove::CommandMove(QGraphicsTaikoItem *item, qreal fromX, qreal fromY, qreal toX, qreal toY, QUndoCommand* parent) : QUndoCommand (parent)
{
    mItem = item;
    mFrom = QPointF(fromX, fromY);
    mTo = QPointF(toX, toY);
//    setText(QString("Point move (%1,%2) -> (%3,%4)").arg(mFrom.x()).arg(mFrom.y()).arg(mTo.x()).arg(mTo.y()));
}

void CommandMove::undo()
{
    mItem->setPos(mFrom);
}

void CommandMove::redo()
{
    mItem->setPos(mTo);
}
