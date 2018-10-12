#include "commandadd.h"

CommandAdd::CommandAdd(QGraphicsScene* scene, QGraphicsTaikoItem *item, QUndoCommand* parent)
    : QUndoCommand (parent)
{
    this->scene = scene;
    mItem = item;
}

void CommandAdd::undo()
{
    scene->removeItem(mItem);
}

void CommandAdd::redo()
{
    scene->addItem(mItem);
}
