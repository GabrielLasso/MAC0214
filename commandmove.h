#ifndef COMMANMOVE_H
#define COMMANMOVE_H

#include <QUndoCommand>
#include "qgraphicstaikoitem.h"

class CommandMove : public QUndoCommand
{
public:
    CommandMove(QGraphicsTaikoItem *item, qreal fromX, qreal fromY, qreal toX, qreal toY, QUndoCommand* parent = nullptr);
    void undo() override;
    bool mergeWith(const QUndoCommand *command) override;
    int id() const override { return 1729; }
private:
    QGraphicsTaikoItem* mItem;
    qreal fromX, fromY, toX, toY;
};

#endif // COMMANMOVE_H
