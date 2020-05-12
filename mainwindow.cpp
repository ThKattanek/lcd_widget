#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lcd_column->setValue(ui->lcd_widget->GetCurrentColumn());
    ui->lcd_row->setValue(ui->lcd_widget->GetCurrentRow());
    ui->lcd_widget->ClearLCD();
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
