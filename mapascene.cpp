#include "mapascene.h"

MapaScene::MapaScene(QObject* parent):QGraphicsScene(parent)
{

}

void MapaScene::keyPressEvent(QKeyEvent * keyEvent)
{
    QList<QGraphicsItem*> selectedItems = this->selectedItems();
    switch(keyEvent->key()) {
    case Qt::Key_Up:
        foreach(QGraphicsItem* item, selectedItems)
        {
            item->moveBy(0,-1);
        }
        break;
    case Qt::Key_Down:
        foreach(QGraphicsItem* item, selectedItems)
        {
            item->moveBy(0,1);
        }
        break;
    case Qt::Key_Left:
        if (keyEvent->modifiers().testFlag(Qt::ShiftModifier)) {
            foreach(QGraphicsItem* item, selectedItems)
            {
                dynamic_cast<QGraphicsTaikoItem*>(item)->rotate(-5);
            }
        } else {
            foreach(QGraphicsItem* item, selectedItems)
            {
                item->moveBy(-1,0);
            }
        }
        break;
    case Qt::Key_Right:
        if (keyEvent->modifiers().testFlag(Qt::ShiftModifier)) {
            foreach(QGraphicsItem* item, selectedItems)
            {
                dynamic_cast<QGraphicsTaikoItem*>(item)->rotate(5);
            }
        } else {
            foreach(QGraphicsItem* item, selectedItems)
            {
                item->moveBy(1,0);
            }
        }
        break;
    case Qt::Key_Delete:
        foreach(QGraphicsItem* item, selectedItems)
        {
            delete item;
        }
    break;
    }
}
