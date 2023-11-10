#ifndef ITEMSLISTVIEW_H
#define ITEMSLISTVIEW_H

#include "myitem.h"

#include <QListView>

/**
 * @file ItemsListView.h
 * @brief Заголовочный файл для класса ItemsListView создан для переопределения стандартного
 * поведения QListView (используется как виджет с перечислением обьектов на GraphicsView).
 */

class ItemsListView : public QListView
{
    Q_OBJECT
public:
    /**
        * @brief Конструктор базового класса.
        * @param parent Родительский виджет.
        */
    ItemsListView(QWidget *parent = nullptr);

    using QListView::QListView;

public slots:

    /**
        * @brief слот для обработки обновления виджета при добавлении обьекта в модель.
        */
    void OnModelAddItemSlot();


signals:

    /**
        * @brief сигнал посылающийся в модель при клике на обьект этого виджета.
        * @param index индекс обьекта в аиджете.
        */
    void OnItemClickSignal(int index);


    // QWidget interface
protected:
    /**
        * @brief Стандартное событие qt для обработки на нажатие мышью на обьект в виджете.
        * @param event событие нажатия.
        */
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // ITEMSLISTVIEW_H
