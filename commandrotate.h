#ifndef COMMANDROTATE_H
#define COMMANDROTATE_H

#include <QUndoCommand>
#include "qgraphicstaikoitem.h"

class CommandRotate : public QUndoCommand
{
public:
    CommandRotate(QSet<QGraphicsItem*> items, qreal da, QUndoCommand *parent = nullptr);
    void undo() override;
    void redo() override;
    bool mergeWith(const QUndoCommand *command) override;
    int id() const override { return 4242; }
private:
    QSet<QGraphicsItem*> items;
    qreal da;
};

#endif // COMMANDROTATE_H
