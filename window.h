#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

#include "glwidget.h"
#include "automata.h"
#include "controls.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private:
    GLWidget *canvas;
    Controls *controls;
    Automata *automata;
};

#endif // WINDOW_H
