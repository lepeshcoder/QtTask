#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include "myitem.h"

#include <QTableView>


class MyTableView : public QTableView
{
    Q_OBJECT

private:
    int currentIndex = -1;
public:

    MyTableView(QWidget *parent = nullptr);


    using QTableView::QTableView;

public slots:

    void OnItemClickSlot(int index, MyItem* item);


signals:
    void OnCommitDataSignal(int index, int valueType,int newValue);


    // QAbstractItemView interface
protected slots:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles) override;
};

#endif // MYTABLEVIEW_H
