#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lcd_column->setValue(ui->lcd_widget->GetCurrentColumn());
    ui->lcd_row->setValue(ui->lcd_widget->GetCurrentRow());
    ui->lcd_widget->ClearLCD();

    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()));
    timer1.setInterval(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lcd_clear_clicked()
{
    ui->lcd_widget->ClearLCD();
}

void MainWindow::on_quit_clicked()
{
    this->close();
}

void MainWindow::on_lcd_text_enter_clicked()
{
    ui->lcd_widget->SetText(ui->lcd_text_edit->text());
}

void MainWindow::on_random_start_clicked()
{
    timer1.start();
}

void MainWindow::on_random_stop_clicked()
{
    timer1.stop();
}

void MainWindow::timer1_timeout()
{
    uint8_t *buffer = ui->lcd_widget->GetDisplayCharBuffer();
    int buffer_len = ui->lcd_widget->GetDisplayCharBufferLength();

    for(int i=0; i<buffer_len; i++)
        buffer[i] = rand() % 133 + 33;

    ui->lcd_widget->RefreshDisplay();
}

void MainWindow::on_action_Exit_triggered()
{
    this->close();
}

void MainWindow::on_actionSave_Image_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),QDir::homePath(),tr("Images (*.png *.xpm *.jpg)"));
    if(fileName != "")
    {
       ui->lcd_widget->SaveImage(fileName);
    }
}

void MainWindow::on_lcd_text_edit_returnPressed()
{
    on_lcd_text_enter_clicked();
}

void MainWindow::on_lcd_column_valueChanged(int arg1)
{
    ui->lcd_widget->SetColumn(arg1);
}

void MainWindow::on_lcd_row_valueChanged(int arg1)
{
    ui->lcd_widget->SetRow(arg1);
}
