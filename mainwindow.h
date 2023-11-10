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
    /**
        * @brief Метод инициализации окна включающий в себя инициализацию компонентов и связывания сигналов слотов.
        */
    void Initialize();

    /**
        * @brief Метод инициализации компонентов.
        */
    void InitializeComponents();
    /**
        * @brief Метод связывания сигналов слотов.
        */
    void SetUpSignalSlots();

private:
    Ui::MainWindow *ui;
    Model model; /**< Модель данных для подобия паттерна MVVM. */

};
#endif // MAINWINDOW_H
