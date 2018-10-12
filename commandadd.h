#ifndef COMMANDADD_H
#define COMMANDADD_H

#include <QUndoCommand>
#include "qgraphicstaikoitem.h"

class CommandAdd : public QUndoCommand
{
public:
    CommandAdd(QGraphicsTaikoItem *item, QUndoCommand* parent = nullptr);
    void undo() override;
    void redo() override;
private:
    QGraphicsItem* mItem;
};

#endif // COMMANDADD_H
