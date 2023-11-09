#include "iconslistwidget.h"
#include <QApplication>
#include <QBuffer>
#include <QDir>
#include <QDrag>
#include <QLabel>
#include <QMessageBox>
#include <QMimeData>

IconsListWidget::IconsListWidget(QWidget *parent) : QListWidget(parent)
{
    setIconSize(QSize(64,64));
    setDragEnabled(true);
}

void IconsListWidget::Initialize(const QVector<QIcon> &icons)
{
    foreach (auto icon, icons) {
        QListWidgetItem* item = new QListWidgetItem(icon,"item");
        addItem(item);
    }
}

void IconsListWidget::startDrag(Qt::DropActions supportedActions)
{
    QModelIndex currentIndex = this->currentIndex();
    QAbstractItemModel *model = this->model();

    if (currentIndex.isValid() && model) {
        QVariant iconData = model->data(currentIndex, Qt::DecorationRole);
        if (iconData.isValid()) {
            QIcon icon = qvariant_cast<QIcon>(iconData);
            QPixmap pixmap = icon.pixmap(QSize(64, 64));
            QLabel *dragLabel = new QLabel(this);
            dragLabel->setPixmap(icon.pixmap(QSize(64,64)));
            dragLabel->move(QCursor::pos());

            QDrag *drag = new QDrag(this);
            QMimeData *mimeData = new QMimeData;

            QByteArray imageData;
            QBuffer buffer(&imageData);
            buffer.open(QIODevice::WriteOnly);
            pixmap.save(&buffer, "PNG");

            mimeData->setData("image/png", imageData);

            drag->setMimeData(mimeData);
            drag->setPixmap(*dragLabel->pixmap());
            drag->setHotSpot(QPoint(dragLabel->width() / 2, dragLabel->height() / 2));

            drag->exec(supportedActions, Qt::CopyAction);
        }
    }
}
