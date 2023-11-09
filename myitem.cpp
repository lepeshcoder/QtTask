#include "myitem.h"


QGraphicsItem* MyItem::getItem() const
{
    return item;
}

QPointF MyItem::getPoint() const
{
    return item->pos();
}

MyItem::MyItem(const MyItem &other)
{
  QGraphicsPixmapItem *pixmapItem = qgraphicsitem_cast<QGraphicsPixmapItem*>(other.item);
  this->item = new QGraphicsPixmapItem(pixmapItem->pixmap());
  this->item->setPos(other.getPoint());
}

MyItem::MyItem(QGraphicsItem *item, QPointF &point)
{
    this->item = item;
    item->setPos(point);
}

MyItem::~MyItem()
{
    delete item;
}

void MyItem::SetPosition(QPointF &point)
{
    this->item->setPos(point);
}
