#ifndef COMMANDROTATE_H
#define COMMANDROTATE_H

#include <QUndoCommand>
#include "qgraphicstaikoitem.h"

class CommandRotate : public QUndoCommand
{
public:
    CommandRotate(QGraphicsTaikoItem *item, qreal old_alpha, qreal new_alpha, QUndoCommand* parent = nullptr);
    void undo() override;
    bool mergeWith(const QUndoCommand *command) override;
    int id() const override { return 4242; }
private:
    QGraphicsTaikoItem* mItem;
    qreal old_alpha;
    qreal new_alpha;
};

#endif // COMMANDROTATE_H
