#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ModeBusRTU.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_crc_clicked();

    void on_pushButton_make_clicked();

    void on_pushButton_make_2_clicked();

private:
    Ui::MainWindow *ui;
    ModeBusRTU modeBus;
    QString makeStr;
};

#endif // MAINWINDOW_H
