#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lcd_clear_clicked();
    void on_quit_clicked();
    void on_lcd_text_enter_clicked();
    void on_random_start_clicked();
    void on_random_stop_clicked();

    void timer1_timeout();

    void on_action_Exit_triggered();

    void on_actionSave_Image_triggered();

    void on_lcd_text_edit_returnPressed();

    void on_lcd_column_valueChanged(int arg1);

    void on_lcd_row_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QTimer timer1;
};
#endif // MAINWINDOW_H
