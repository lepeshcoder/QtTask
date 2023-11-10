#include "model.h"
#include "constants.h"
#include "myitem.h"
#include <QMessageBox>
#include <QApplication>
#include <QDir>
#include <QListWidgetItem>

Model::Model()
{

}

Model::~Model()
{
    foreach(MyItem* item,items)
    {
        delete item;
    }
}

void Model::Initialize()
{
    QString resDir = ":resources/res";
    if(!resDir.isNull())
       {
           QDir directory(resDir);

           QStringList nameFilters;
           nameFilters << "*.png";

           QFileInfoList files = directory.entryInfoList(nameFilters, QDir::Files);

           foreach (QFileInfo fileInfo, files) {
               QString filePath = fileInfo.absoluteFilePath();
               this->icons.append(QIcon(filePath));
        }
    }
}

const QVector<QIcon> &Model::GetIcons()
{
    return icons;
}

void Model::OnItemDropSlot(QPixmap& pixmap)
{
    // добавляем новый элемент в модель
    QPointF point(0,0);
    MyItem* item = new MyItem(new QGraphicsPixmapItem(pixmap),point);
    items.append(item);

    // вызываем событие обновления graphicsView и TableView
    emit OnAddItemSignal(item);
}

void Model::OnItemClickSlot(int index)
{
    emit OnItemClickSignal(index,this->items[index]);
}

void Model::OnCommitPropertySlot(int index, int valueType, int newValue)
{

    switch(valueType)
    {
    case PropertyConstants::xValue:
    {
        // Получаем новую позицию элемента
        QPointF oldPoint = items[index]->getPoint();
        QPointF newPoint(oldPoint);
        newPoint.setX(newValue);
        items[index]->SetPosition(newPoint);
        // Вызываем обновление graphicsView
        emit OnPropertyChangedSignal(index,newPoint);
        break;
    }
    case PropertyConstants::yValue:
    {
        // Получаем новую позицию элемента
        QPointF oldPoint = items[index]->getPoint();
        QPointF newPoint(oldPoint);
        newPoint.setY(newValue);
        items[index]->SetPosition(newPoint);
         // Вызываем обновление graphicsView
        emit OnPropertyChangedSignal(index,newPoint);
        break;
    }
    }
}
