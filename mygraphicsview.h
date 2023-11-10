#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include "myitem.h"

#include <QGraphicsView>

/**
 * @file MyGraphicsView.h
 * @brief Заголовочный файл для класса MyGraphicsView создан для переопределения стандартного
 * поведения QGraphicsView(используется как виджет отрисовывающий элементы).
 */

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT

private:

    QList<QGraphicsItem*> items; /**< Список всех элементов отображающихся в graphicsView. */
public:
    /**
        * @brief Конструктор базового класса.
        * @param parent родительский виджет
        */
    explicit MyGraphicsView(QWidget* parent = nullptr);

    /**
        * @brief Метод для выставления сцены и её размера.
        * @param scene Сцена
        */
    void Initialize(QGraphicsScene* scene);

    using QGraphicsView::QGraphicsView;

    // QWidget interface
protected:
    /**
        * @brief Стандартное событие для обработки бросания элемента на виджет.
        * @param event событие бросания
        */
    void dropEvent(QDropEvent *event) override;

    /**
        * @brief Стандартное событие для обработки входа drag на виджет.
        * @param event событие входа
        */
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;

signals:

    /**
        * @brief сигнал посылающийся в модель для обновления после завершение операции бросания элемента на виджет.
        * @param icon иконка обьекта
        */
    void OnItemDropSignal(QPixmap& icon);

public slots:

    /**
        * @brief слот для обновления виджета при добавлении в модель нового обьекта.
        * @param item обьект
        */
    void OnModelAddItemSlot(MyItem* item);

    /**
        * @brief слот для обновления виджета при изменении свойств обьекта в модели.
        * @param index индекс измененного обьекта
        * @param newPosition новая позиция элемента в модели
        */
    void OnPropertyChangedSlot(int index, QPointF& newPosition);


    // QWidget interface
protected:
    /**
        * @brief Событие обновления размера окна для изменения геометрии сцены.
        * @param event событие ресайза
        */
    void resizeEvent(QResizeEvent *event) override;
};

#endif // MYGRAPHICSVIEW_H
