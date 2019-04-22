#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QResizeEvent>
#include <QSize>

#include "glwidget.h"
#include "automata.h"
#include "controls.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window() override;

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    GLWidget *canvas;
    Controls *controls;
    Automata *automata;
    const int canvasOffset;
    int canvasSize;
};

#endif // WINDOW_H
