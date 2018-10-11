#ifndef COMMANMOVE_H
#define COMMANMOVE_H

#include <QUndoCommand>
#include <QPoint>
#include "qgraphicstaikoitem.h"

class CommandMove : public QUndoCommand
{
public:
    CommandMove(QGraphicsTaikoItem *item, qreal fromX, qreal fromY, qreal toX, qreal toY, QUndoCommand* parent = nullptr);
    void undo() override;
    void redo() override;
private:
    QGraphicsItem* mItem;
    QPointF mFrom;
    QPointF mTo;
};

#endif // COMMANMOVE_H
