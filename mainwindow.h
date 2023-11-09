#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"

#include <QGraphicsScene>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void Initialize();
    void InitializeComponents();
    void SetUpSignalSlots();

private:
    Ui::MainWindow *ui;
    Model model;

};
#endif // MAINWINDOW_H
