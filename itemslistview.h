#ifndef ITEMSLISTVIEW_H
#define ITEMSLISTVIEW_H

#include "myitem.h"

#include <QListView>



class ItemsListView : public QListView
{
    Q_OBJECT
public:
    ItemsListView(QWidget *parent = nullptr);

    using QListView::QListView;
public slots:

    void OnModelAddItemSlot();


signals:

    void OnItemClickSignal(int index);


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // ITEMSLISTVIEW_H
