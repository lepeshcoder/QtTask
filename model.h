#ifndef MODEL_H
#define MODEL_H


#include "myitem.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QIcon>
#include <QObject>



class Model : public QObject
{
   Q_OBJECT


private:
   QVector<MyItem*> items;

   QVector<QIcon> icons;


public:
    Model();

    ~Model();

    void Initialize();

    const QVector<QIcon>& GetIcons();

public slots:
    void OnItemDropSlot(QPixmap& pixmap);

    void OnItemClickSlot(int index);

    void OnCommitPropertySlot(int index,int valueType,int newValue);

signals:
    void OnAddItemSignal(MyItem* item);

    void OnItemClickSignal(int index, MyItem* item);

    void OnPropertyChangedSignal(int index, QPointF& newPosition);
};

#endif // MODEL_H
