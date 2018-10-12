#include "commanddelete.h"

CommandDelete::CommandDelete(QGraphicsScene* scene, QGraphicsTaikoItem *item, QUndoCommand* parent)
    : QUndoCommand (parent)
{
    this->scene = scene;
    mItem = item;
}

void CommandDelete::undo()
{
    scene->addItem(mItem);
}

void CommandDelete::redo()
{
    scene->removeItem(mItem);
}
