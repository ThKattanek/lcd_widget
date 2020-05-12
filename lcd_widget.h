#ifndef LCDWIDGET_H
#define LCDWIDGET_H

#include <QWidget>
#include <QImage>

#define CHAR_WIDTH_PX         5
#define CHAR_HEIGHT_PX        8

#define CGRAM_STORAGE_CHARS  16
#define ROM_FONT_CHARS       (256 - CGRAM_STORAGE_CHARS)

class LCDWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LCDWidget(QWidget *parent = nullptr);
    ~LCDWidget();
    void paintEvent(QPaintEvent *event);

private:
    /* font roms */
    static const uint8_t fontA00[ROM_FONT_CHARS][CHAR_WIDTH_PX];
    static const uint8_t fontA02[ROM_FONT_CHARS][CHAR_WIDTH_PX];

    QImage *display;

signals:

};

#endif // LCDWIDGET_H
