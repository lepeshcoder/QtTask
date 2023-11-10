#ifndef ICONSLISTWIDGET_H
#define ICONSLISTWIDGET_H

#include <QListWidget>

/**
 * @file IconsListWidget.h
 * @brief Заголовочный файл для класса IconsListWidget создан для переопределения стандартного
 * поведения QListWidget(используется как виджет с списком доступных иконок).
 */

class IconsListWidget : public QListWidget
{
    Q_OBJECT
public:
    /**
        * @brief Конструктор базового класса.
        * @param parent Родительский виджет.
        */
    IconsListWidget(QWidget* parent = nullptr);

    /**
        * @brief Метод инициализации данных полученных из model.
        * @param icons Список иконок подгруженных из файла ресурсов.
        */
    void Initialize(const QVector<QIcon>& icons);

    using QListWidget::QListWidget;

    // QAbstractItemView interface
protected:
    /**
        * @brief Стандартное qt событие для обработки начала dragndrop.
        * @param supportedActions Стандартный параметр.
        */
    void startDrag(Qt::DropActions supportedActions) override;
};

#endif // ICONSLISTWIDGET_H
