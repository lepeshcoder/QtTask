#ifndef ICONSLISTWIDGET_H
#define ICONSLISTWIDGET_H

#include <QListWidget>



class IconsListWidget : public QListWidget
{
    Q_OBJECT
public:
    IconsListWidget(QWidget* parent = nullptr);

    void Initialize(const QVector<QIcon>& icons);

    using QListWidget::QListWidget;

    // QAbstractItemView interface
protected:
    void startDrag(Qt::DropActions supportedActions) override;
};

#endif // ICONSLISTWIDGET_H
