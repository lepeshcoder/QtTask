#include "mytableview.h"

#include <QMessageBox>
#include <QStandardItemModel>
#include <QHeaderView>
#include "constants.h"


MyTableView::MyTableView(QWidget *parent) : QTableView(parent)
{

}

void MyTableView::OnItemClickSlot(int index, MyItem *item)
{
    currentIndex = index;
    QStandardItemModel* model = new QStandardItemModel();

    QList<QStandardItem*> list;

    QStandardItem* x = new QStandardItem("X");
    x->setEditable(false);
    list.append(x);


    QStandardItem* valueX = new QStandardItem(QString::number(item->getItem()->pos().x()));
    valueX->setEditable(true);
    list.append(valueX);

    model->appendRow(list);

    QList<QStandardItem*> list1;

    QStandardItem* y = new QStandardItem("Y");
    y->setEditable(false);
    list1.append(y);


    QStandardItem* valueY = new QStandardItem(QString::number(item->getItem()->pos().y()));
    valueY->setEditable(true);
    list1.append(valueY);

    model->appendRow(list1);

    verticalHeader()->hide();
    horizontalHeader()->hide();

    setModel(model);
}


void MyTableView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
    Q_UNUSED(roles);
    if (topLeft == bottomRight)
    {
        if(topLeft.column() == PropertyConstants::EditableColumn)
        {
            switch(topLeft.row())
            {
            case PropertyConstants::xValue:
            {
                QVariant data = topLeft.data(Qt::DisplayRole);
                if (data.isValid()) {
                    bool ok;
                    int intValue = data.toInt(&ok);
                    if(ok)
                    {
                       emit OnCommitDataSignal(currentIndex,PropertyConstants::xValue,intValue);
                    }
                }
                break;
            }
            case PropertyConstants::yValue:
            {
                QVariant data = topLeft.data(Qt::DisplayRole);
                if (data.isValid()) {
                    bool ok;
                    int intValue = data.toInt(&ok);
                    if(ok)
                    {
                       emit OnCommitDataSignal(currentIndex,PropertyConstants::yValue,intValue);
                    }
                }
                break;
            }
            }
        }
    }


}
