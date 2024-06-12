#include "widget.h"
#include "ui_widget.h"
#include <QMenuBar>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initUI();
    initMenu();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initUI()
{
    this->setWindowTitle("Album");
//    this->showMaximized();
}

void Widget::initMenu()
{
    //创建菜单
    QMenuBar* menubar = new QMenuBar(this);

    QMenu* menu_file = new QMenu(tr("文件(&F)"));
    menubar->addMenu(menu_file);

    QAction* act_create_pro = new QAction(QIcon(":/icon/createpro.png"),tr("创建项目"),this);
    act_create_pro->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    menu_file->addAction(act_create_pro);
    QAction* act_open_pro = new QAction(QIcon(":/icon/openpro.png"),tr("打开项目"),this);
    act_open_pro->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    menu_file->addAction(act_open_pro);

    QMenu* menu_set = new QMenu(tr("设置(&S)"));
    menubar->addMenu(menu_set);

    QAction* act_music = new QAction(QIcon(":/icon/music.png"),tr("背景音乐"),this);
    act_music->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_M));
    menu_set->addAction(act_music);

    connect(act_create_pro,&QAction::triggered,this,&Widget::slot_CreatePro);
    connect(act_open_pro,&QAction::triggered,this,&Widget::slot_OpenPro);
}

void Widget::slot_CreatePro()
{
    qDebug() << "创建项目";
}

void Widget::slot_OpenPro()
{
    qDebug() << "打开项目";
}

