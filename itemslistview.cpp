#include "itemslistview.h"
#include "qevent.h"
#include <QMessageBox>
#include <QStandardItemModel>


void ItemsListView::OnModelAddItemSlot()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel *>(this->model());
    QStandardItem* newItem = new QStandardItem("[icon]");
    model->appendRow(newItem);
}

void ItemsListView::mousePressEvent(QMouseEvent *event)
{
    QModelIndex index = indexAt(event->pos());
    if(index.isValid())
    {
        emit OnItemClickSignal(index.row());
    }
}

ItemsListView::ItemsListView(QWidget *parent) : QListView(parent)
{
    QStandardItemModel* model = new QStandardItemModel();
    setModel(model);
}
