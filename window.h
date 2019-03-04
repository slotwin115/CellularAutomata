#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include "glwidget.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

public slots:
    void changeButtonText();
    void changeCanvas();

private:
    QPushButton *button;
    GLWidget *canvas;
};

#endif // WINDOW_H
