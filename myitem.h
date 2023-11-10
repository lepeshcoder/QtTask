#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>

/**
 * @file MyItem.h
 * @brief Заголовочный файл для класса MyItem создан для хранения позиции обьекта и его иконки вместе
 * используетя в Model
 */

class MyItem
{

private:
    QGraphicsItem* item; /**< Графическое представление обьекта. */

public:
    /**
        * @brief конструктор копирования.
        * @param other по чему копировать обьект
        */
    MyItem(const MyItem& other);

    /**
        * @brief конструктор по полям.
        * @param item графическое представление
        * @param point позциция элемнта на сцене
        */
    MyItem(QGraphicsItem* item, QPointF &point);

    /**
        * @brief деструктор.
        */
    ~MyItem();

    /**
        * @brief setter для позиции элемента.
        * @param point новое значение позциии
        */
    void SetPosition(QPointF& point);

    /**
        * @brief getter для позиции элемента.
        */
    QPointF getPoint() const;

    /**
        * @brief getter для поля item.
        */
    QGraphicsItem* getItem() const;

};

#endif // MYITEM_H
