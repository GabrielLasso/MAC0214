#include "commandadd.h"

CommandAdd::CommandAdd(QGraphicsTaikoItem *item, QUndoCommand* parent)
    : QUndoCommand (parent)
{
    mItem = item;
}

void CommandAdd::undo()
{
    delete(mItem);
}

void CommandAdd::redo()
{
}
