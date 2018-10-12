#include "commandrotate.h"


CommandRotate::CommandRotate(QGraphicsTaikoItem *item, qreal old_alpha, qreal new_alpha, QUndoCommand *parent)
    : QUndoCommand (parent)
{
    mItem = item;
    this->old_alpha = old_alpha;
    this->new_alpha = new_alpha;
}

void CommandRotate::undo()
{
    mItem->setRotation(old_alpha);
}

void CommandRotate::redo()
{
//    mItem->setRotation(new_alpha);
}
