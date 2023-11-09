#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>



class MyItem
{

private:
    QGraphicsItem* item;

public:

    MyItem(const MyItem& other);

    MyItem(QGraphicsItem* item, QPointF &point);

    ~MyItem();

    void SetPosition(QPointF& point);

    QPointF getPoint() const;

    QGraphicsItem* getItem() const;

};

#endif // MYITEM_H
