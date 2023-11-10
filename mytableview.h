#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include "myitem.h"

#include <QTableView>

/**
 * @file MyTableView.h
 * @brief Заголовочный файл для класса MyTableView создан для переопределения стандартного
 * поведения QTableView(используется как виджет с списком свойств обьектов ).
 */
class MyTableView : public QTableView
{
    Q_OBJECT

private:
    int currentIndex = -1; /**< Индекс текущего выбранного элемента . */
public:

    /**
        * @brief конструктор базового класса.
        * @param parent родительский виджет
        */
    MyTableView(QWidget *parent = nullptr);


    using QTableView::QTableView;

public slots:

    /**
        * @brief слот для отображения данных модели при нажатии на обьект.
        * @param index индекс нажатого элемента
        * @param item данные для отображения
        */
    void OnItemClickSlot(int index, MyItem* item);


signals:

    /**
        * @brief сигнал для оповещения модели о изменении свойств
        * @param index индекс измененного обьекта
        * @param valueType тип измененного свойств описанный в constants.h
        * @param newValue новое значнеие элемента
        */
    void OnCommitDataSignal(int index, int valueType,int newValue);


    // QAbstractItemView interface
protected slots:

    /**
        * @brief событие для обработки изменения данных в tableView.
        */
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles) override;
};

#endif // MYTABLEVIEW_H
