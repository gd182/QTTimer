#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimerLabel);
    ui->stopButton->setEnabled(false);

    countTimer = 0;
    tickCount = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    ui->stopButton->setEnabled(true);
    ui->startButton->setEnabled(false);
    countTimer = 0;
    tickCount = 0;
    ui->logTextEdit->clear();
    timer->start(10);
}


void MainWindow::on_stopButton_clicked()
{
    ui->stopButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    timer->stop();
}

void MainWindow::updateTimerLabel()
{
    countTimer++;

    int hours = countTimer / 3600 / 100;
    int minutes = ((countTimer / 100) % 3600) / 60;
    int seconds = (countTimer / 100) % 60;
    int pSec = countTimer % 100;

    ui->timerLable->setText(
        QString("%1:%2:%3.%4")
            .arg(hours, 2, 10, QChar('0'))
            .arg(minutes, 2, 10, QChar('0'))
            .arg(seconds, 2, 10, QChar('0'))
            .arg(pSec, 2, 10, QChar('0'))
        );
    if (tickCount != seconds)
    {
        tickCount = seconds;
        ui->logTextEdit->append("Tick " + QString::number(seconds));
    }
}
