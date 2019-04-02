#include <QDebug>
#include <QLineEdit>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    box = new QComboBox();
    box->setEditable(true);
    btn = new QPushButton("Add entry");

    vboxLayout = new QVBoxLayout();
    vboxLayout->addWidget(box);
    vboxLayout->addWidget(btn);

    QWidget *widget = new QWidget();
    widget->setLayout(vboxLayout);
    setCentralWidget(widget);

    connect(btn, &QPushButton::clicked, this, &MainWindow::addEntry);
    connect(box->lineEdit(), &QLineEdit::editingFinished, this, &MainWindow::printValue);
}

void MainWindow::addEntry()
{
    static int i = 0;
    box->setCurrentText(QString::number(i++));
    box->lineEdit()->selectAll();
    box->setFocus();
}

void MainWindow::printValue()
{
    qDebug() << box->currentText();
}
