#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QVBoxLayout>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
    void addEntry();
    void printValue();

private:
    QComboBox *box = nullptr;
    QVBoxLayout *vboxLayout = nullptr;
    QPushButton *btn = nullptr;
};

#endif // MAINWINDOW_H
