#ifndef MODEL_H
#define MODEL_H


#include "myitem.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QIcon>
#include <QObject>


/**
 * @file Model.h
 * @brief Заголовочный файл для класса Model создан для единоличного хранения общедоступных ресурсов таких как иконки
 * а также выполняет роль связывания виджетов по данным
 */

class Model : public QObject
{
   Q_OBJECT


private:


   QVector<MyItem*> items; /**< Список всех элементов отображающихся в graphicsView и TableView. */

   QVector<QIcon> icons;  /**< Доступные для использования иконки подгруженные из файла ресурсов. */


public:
   /**
       * @brief Конструктор по умолчанию.
       */
    Model();

    /**
        * @brief Деструктор класса.
        */
    ~Model();

    /**
        * @brief Метод для подгрузки иконок из файла ресурсов.
        */
    void Initialize();

    /**
        * @brief getter Для поля icons.
        */
    const QVector<QIcon>& GetIcons();

public slots:

    /**
        * @brief слот для обработки бросания обьекта на Graphicsview для последующего
        * добавления элемента в модель.
        * @param pixmap Pixmap брошенного элемента .
        */
    void OnItemDropSlot(QPixmap& pixmap);

    /**
        * @brief слот для обработки нажатия на элемент в listview, перенаправляет обьект по индексу в tableView
        * для отображения его свойств.
        * @param index индекс выбранного элемента на listview.
        */
    void OnItemClickSlot(int index);

    /**
        * @brief слот для обработки замены некоторых свойств элемента в tableView(обновляет модель)
        * и вызывает обновление graphicsView.
        * @param index индекс выбранного элемента на listview.
        * @param valueType один из описанных в constants.h свойств обьекта
        * @param newValue новое значения этого свойства
        */
    void OnCommitPropertySlot(int index,int valueType,int newValue);

signals:

    /**
        * @brief сигнал посылающийся при добавлении в модель нового элемента чтобы обновить graphicsView и listView.
        * @param item добавленный элемент.
        */
    void OnAddItemSignal(MyItem* item);

    /**
        * @brief сигнал посылающийся при вызове модели для получения данных о элементе по индексу затем обновляя список свойств
        * обьекта в tableView.
        * @param index индекс затронутого элемента
        * @param item затронутый элемент.
        */
    void OnItemClickSignal(int index, MyItem* item);

    /**
        * @brief сигнал посылающийся при обновлении свойства обьекта в модели
        * вызывает обновление tableView.
        * @param index индекс измененного элемента.
        * @param newPosition новая точка нахождения обьекта
        */
    void OnPropertyChangedSignal(int index, QPointF& newPosition);
};

#endif // MODEL_H
