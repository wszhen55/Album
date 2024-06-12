#include "widget.h"
#include "ui_widget.h"

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
    this->showMaximized();
}

void Widget::initMenu()
{

}

