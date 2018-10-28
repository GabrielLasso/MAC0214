#ifndef COMMANMOVE_H
#define COMMANMOVE_H

#include <QUndoCommand>
#include "qgraphicstaikoitem.h"

class CommandMove : public QUndoCommand
{
public:
    CommandMove(QGraphicsTaikoItem *item, qreal dx, qreal dy, QUndoCommand* parent = nullptr);
    void undo() override;
    void redo() override;
    bool mergeWith(const QUndoCommand *command) override;
    int id() const override { return 1729; }
private:
    QGraphicsTaikoItem* mItem;
    qreal dx, dy;
};

#endif // COMMANMOVE_H
