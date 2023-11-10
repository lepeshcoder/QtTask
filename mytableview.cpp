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
    // Обновляем индекс выбранного элемента
    currentIndex = index;

    // Создаём и заполняем модель данными из модели
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

    // отключяем индексные строки и стоблцы
    verticalHeader()->hide();
    horizontalHeader()->hide();

    // устанавливаем модель
    setModel(model);
}


void MyTableView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
    Q_UNUSED(roles);
    if (topLeft == bottomRight)
    {
        // если колонка это свойство
        if(topLeft.column() == PropertyConstants::EditableColumn)
        {
            // выбираем тип измененного свойства
            switch(topLeft.row())
            {
            case PropertyConstants::xValue:
            {
                // конвертируем его
                QVariant data = topLeft.data(Qt::DisplayRole);
                if (data.isValid()) {
                    bool ok;
                    int intValue = data.toInt(&ok);
                    if(ok)
                    {
                        // вызываем обновление модели
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
