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
        foreach(QGraphicsItem* item, selectedItems)
        {
            item->moveBy(-1,0);
        }
        break;
    case Qt::Key_Right:
        foreach(QGraphicsItem* item, selectedItems)
        {
            item->moveBy(1,0);
        }
        break;
    case Qt::Key_Delete:
        foreach(QGraphicsItem* item, selectedItems)
        {
            delete item;
        }
    break;
    case Qt::Key_Q:
        foreach(QGraphicsItem* item, selectedItems)
        {
            dynamic_cast<QGraphicsTaikoItem*>(item)->rotate(-15);
        }
    break;
    case Qt::Key_W:
        foreach(QGraphicsItem* item, selectedItems)
        {
            dynamic_cast<QGraphicsTaikoItem*>(item)->rotate(15);
        }
    break;
    }
}
