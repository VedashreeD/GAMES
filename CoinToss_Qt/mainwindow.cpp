#include <QLabel>
#include <QTimer>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int coinToss(void)
{
    return 1 + rand() % 2;
}

void MainWindow::on_pushButton_clicked()
{
    // Create a QWidget to hold the QLabel
    QWidget *window = new QWidget;
    window->setWindowTitle("Coin Toss Result");
    // Create a QLabel to display the image
    QLabel *label = new QLabel(window);

    int randomNumber = coinToss();
    if (randomNumber == 1)
    {
        QPixmap pixmap("heads.jpeg");
        if (pixmap.isNull()) {
            qDebug() << "Failed to load image heads.jpeg";
            delete label;
            return;
        }
        else
        {
            pixmap = pixmap.scaled(window->size(), Qt::KeepAspectRatio);
            label->setPixmap(pixmap);
        }
    }
    else
    {
        QPixmap pixmap("tails.jpeg");
        if (pixmap.isNull()) {
            qDebug() << "Failed to load image tails.jpeg";
            delete label;
            return;
        }
        else
        {
            pixmap = pixmap.scaled(window->size(), Qt::KeepAspectRatio);
            label->setPixmap(pixmap);
        }
    }

    // Set window size to match the MainWindow size
    QSize mainWindowSize = this->size();
    window->resize(mainWindowSize);

    // Show the window
    window->show();

    // Create a QTimer to close the window after 5 seconds
    QTimer::singleShot(1000, window, &QWidget::close);
}

