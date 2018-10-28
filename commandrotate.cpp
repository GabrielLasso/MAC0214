#include "commandrotate.h"


CommandRotate::CommandRotate(QGraphicsTaikoItem *item, qreal da, QUndoCommand *parent)
    : QUndoCommand (parent)
{
    mItem = item;
    this->da = da;
}

void CommandRotate::undo()
{
    mItem->setRotation(mItem->rotation() - da);
}

void CommandRotate::redo()
{
    mItem->setRotation(mItem->rotation() + da);
}

bool CommandRotate::mergeWith(const QUndoCommand *command)
{
    const CommandRotate *rotateCommand = static_cast<const CommandRotate *>(command);
    QGraphicsTaikoItem *item = rotateCommand->mItem;

    if (mItem != item)
        return false;

    da += rotateCommand->da;

    return true;
}
