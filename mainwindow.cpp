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

    ui->lcd_column->setValue(20);
    ui->lcd_widget->SetColumn(20);

    ui->lcd_row->setValue(4);
    ui->lcd_widget->SetRow(4);

    uint8_t user_char01[] = {0xaa,0x55,0xaa,0x55,0xaa};
    uint8_t user_char02[] = {0xaa,0xaa,0xaa,0xaa,0xaa};
    uint8_t user_char03[] = {0xff,0x0,0xff,0x0,0xff};
    ui->lcd_widget->SetUserChar(0,user_char01);
    ui->lcd_widget->SetUserChar(1,user_char02);
    ui->lcd_widget->SetUserChar(2,user_char03);


    ui->lcd_widget->Clear();
    ui->lcd_widget->Data(0);

    ui->lcd_widget->SetCursor(1,1);
    ui->lcd_widget->Data(1);

    ui->lcd_widget->SetCursor(2,1);
    ui->lcd_widget->Data(2);

    ui->lcd_widget->SetCursor(4,1);
    ui->lcd_widget->String("16 User Chars");

    ui->lcd_widget->SetCursor(4,3);
    ui->lcd_widget->String("Hello World!");

    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()));
    timer1.setInterval(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lcd_clear_clicked()
{
    ui->lcd_widget->Clear();
}

void MainWindow::on_quit_clicked()
{
    this->close();
}

void MainWindow::on_lcd_text_enter_clicked()
{
    ui->lcd_widget->String(ui->lcd_text_edit->text());
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
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),QDir::homePath(),tr("PNG (*.png);; XPM (*.xpm);; XBM (*.xbm);; JPG (*.jpg);; JPEG (*.jpeg);; BMP (*.bmp);; PPM (*.ppm)"));

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
