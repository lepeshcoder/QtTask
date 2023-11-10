#include "mygraphicsview.h"
#include "qmimedata.h"
#include<QDragEnterEvent>
#include<QDragLeaveEvent>
#include<QDropEvent>
#include <QGraphicsPixmapItem>
#include <QMessageBox>


MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    setAcceptDrops(true);
}

void MyGraphicsView::Initialize(QGraphicsScene *scene)
{
   setScene(scene);
   setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

void MyGraphicsView::dropEvent(QDropEvent *event)
{
    // получаем картинку из mimedata
    QImage image;
    QByteArray data = event->mimeData()->data("image/png");
    if (image.loadFromData(data))
    {
        QPixmap pixmap = QPixmap::fromImage(image);
        // оповещаем модель о добавлении нового элемента
        emit OnItemDropSignal(pixmap);
    }
}

void MyGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}

void MyGraphicsView::dragLeaveEvent(QDragLeaveEvent *event)
{
   // event->accept();
}

void MyGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
   // event->accept();
   // event->acceptProposedAction();
}

void MyGraphicsView::OnModelAddItemSlot(MyItem* item)
{
    items.append(item->getItem());
    scene()->addItem(items[items.size() - 1]);
}

void MyGraphicsView::OnPropertyChangedSlot(int index, QPointF& newPosition)
{
    items[index]->setPos(newPosition);
}

void MyGraphicsView::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    scene()->setSceneRect(sceneRect());
}
