#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_crc_clicked()
{
    int nDevAddr = ui->lineEdit_devAddr->text().toInt();
    int nRW = ui->lineEdit_RW->text().toInt();
    int nAddr = ui->lineEdit_addr->text().toInt();
    int nChanel = ui->lineEdit_chanel->text().toInt();

    QString strDevAddr = QString("%1").arg(nDevAddr , 2, 16, QLatin1Char('0')).toUpper();
    QString strRW = QString("%1").arg(nRW , 2, 16, QLatin1Char('0')).toUpper();
    QString strAddr = QString("%1").arg(nAddr , 4, 16, QLatin1Char('0')).toUpper();
    QString strChanel = QString("%1").arg(nChanel , 4, 16, QLatin1Char('0')).toUpper();
    makeStr = strDevAddr + strRW + strAddr + strChanel;
    ui->lineEdit->setText(ModeBusRTU::CRC16ForModbus(makeStr));
}

void MainWindow::on_pushButton_make_clicked()
{
    int nDevAddr = ui->lineEdit_devAddr->text().toInt();
    int nRW = ui->lineEdit_RW->text().toInt();
    int nAddr = ui->lineEdit_addr->text().toInt();
    int nChanel = ui->lineEdit_chanel->text().toInt();

    QString strDevAddr = QString("%1").arg(nDevAddr , 2, 16, QLatin1Char('0')).toUpper();
    QString strRW = QString("%1").arg(nRW , 2, 16, QLatin1Char('0')).toUpper();
    QString strAddr = QString("%1").arg(nAddr , 4, 16, QLatin1Char('0')).toUpper();
    QString strChanel = QString("%1").arg(nChanel , 4, 16, QLatin1Char('0')).toUpper();
    makeStr = strDevAddr + strRW + strAddr + strChanel;
    makeStr += ModeBusRTU::CRC16ForModbus(makeStr);
    ui->lineEdit->setText(makeStr);
}

void MainWindow::on_pushButton_make_2_clicked()
{                             //要拷贝的内容
    QClipboard *clipboard = QApplication::clipboard();     //获取系统剪贴板指针
    clipboard->setText(ui->lineEdit->text());
}
