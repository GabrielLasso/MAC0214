#ifndef COMMANDROTATE_H
#define COMMANDROTATE_H

#include <QUndoCommand>
#include "qgraphicstaikoitem.h"

class CommandRotate : public QUndoCommand
{
public:
    CommandRotate(QGraphicsTaikoItem *item, qreal old_alpha, qreal new_alpha, QUndoCommand* parent = nullptr);
    void undo() override;
    void redo() override;
private:
    QGraphicsItem* mItem;
    qreal old_alpha;
    qreal new_alpha;
};

#endif // COMMANDROTATE_H
