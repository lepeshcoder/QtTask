#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include "myitem.h"

#include <QGraphicsView>



class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT

private:

    QList<QGraphicsItem*> items;
public:
    explicit MyGraphicsView(QWidget* parent = nullptr);

    void Initialize(QGraphicsScene* scene);

    using QGraphicsView::QGraphicsView;

    // QWidget interface
protected:
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;

signals:
    void OnItemDropSignal(QPixmap& icon);

public slots:
    void OnModelAddItemSlot(MyItem* item);

    void OnPropertyChangedSlot(int index, QPointF& newPosition);


    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // MYGRAPHICSVIEW_H
