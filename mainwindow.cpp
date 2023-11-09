#include "mainwindow.h"
#include "itemslistview.h"
#include "ui_mainwindow.h"
#include <QResizeEvent>

#include <QLayout>
#include <QVBoxLayout>
#include <qgraphicsitem.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Initialize()
{
    InitializeComponents();
    SetUpSignalSlots();
}

void MainWindow::InitializeComponents()
{
    // add scene on GraphicsView
    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->Initialize(scene);
    model.Initialize();
    ui->listWidget->Initialize(model.GetIcons());
}

void MainWindow::SetUpSignalSlots()
{
    QObject::connect(ui->graphicsView,&MyGraphicsView::OnItemDropSignal,&model,&Model::OnItemDropSlot);
    QObject::connect(&model,&Model::OnAddItemSignal,ui->graphicsView,&MyGraphicsView::OnModelAddItemSlot);
    QObject::connect(&model,&Model::OnAddItemSignal,ui->listView,&ItemsListView::OnModelAddItemSlot);
    QObject::connect(ui->listView,&ItemsListView::OnItemClickSignal,&model,&Model::OnItemClickSlot);
    QObject::connect(&model,&Model::OnItemClickSignal,ui->tableView,&MyTableView::OnItemClickSlot);
    QObject::connect(ui->tableView,&MyTableView::OnCommitDataSignal,&model,&Model::OnCommitPropertySlot);
    QObject::connect(&model,&Model::OnPropertyChangedSignal,ui->graphicsView,&MyGraphicsView::OnPropertyChangedSlot);
}


