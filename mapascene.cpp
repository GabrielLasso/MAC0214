#include "mapascene.h"

MapaScene::MapaScene(QObject* parent):QGraphicsScene(parent)
{

}

void MapaScene::keyReleaseEvent(QKeyEvent * keyEvent)
{
    printf ("%d\n",keyEvent->key());
    if(keyEvent->key() == Qt::Key_Delete)
    {
        QList<QGraphicsItem*> selectedItems = this->selectedItems(); // get list of selected items
        foreach(QGraphicsItem* item, selectedItems)
        {
            delete item;
        }
    }
}
