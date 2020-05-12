#ifndef LCDWIDGET_H
#define LCDWIDGET_H

#include <QWidget>
#include <QImage>

#define CHAR_WIDTH_PX         5
#define CHAR_HEIGHT_PX        8

#define CGRAM_STORAGE_CHARS  16
#define ROM_FONT_CHARS       (256 - CGRAM_STORAGE_CHARS)

#define LCD_BORDER_SIZE 10
#define LCD_PIXEL_SIZE_W 3
#define LCD_PIXEL_SIZE_H 3
#define LCD_PIXEL_SPACE_X 1
#define LCD_PIXEL_SPACE_Y 1

#define LCD_CHAR_W 5
#define LCD_CHAR_H 8

#define LCD_CHAR_PIXEL_SIZE_W (LCD_PIXEL_SIZE_W + LCD_PIXEL_SPACE_X) * LCD_CHAR_W
#define LCD_CHAR_PIXEL_SIZE_H (LCD_PIXEL_SIZE_H + LCD_PIXEL_SPACE_Y) * LCD_CHAR_H
#define LCD_CHAR_SPACE_X (LCD_PIXEL_SIZE_W + LCD_PIXEL_SPACE_X) * 1
#define LCD_CHAR_SPACE_Y (LCD_PIXEL_SIZE_H + LCD_PIXEL_SPACE_Y) * 4


class LCDWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LCDWidget(QWidget *parent = nullptr);
    ~LCDWidget();
    void paintEvent(QPaintEvent *event);

private:
    void CalculateDisplaySize();
    /* font roms */
    static const uint8_t fontA00[ROM_FONT_CHARS][CHAR_WIDTH_PX];
    static const uint8_t fontA02[ROM_FONT_CHARS][CHAR_WIDTH_PX];

    QImage *display;
    int row, column;

    int display_size_w, display_size_h;

signals:

};

#endif // LCDWIDGET_H
