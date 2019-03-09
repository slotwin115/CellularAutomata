#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1024, 768);

    this->automata = new Automata(10, -546);

    this->canvas = new GLWidget(this, this->automata);
    this->canvas->setGeometry(15, 34, 700, 700);

    this->controls = new Controls(this, this->automata, this->canvas);
    this->controls->setGeometry(715, 34, 1024 - 715, this->height() - 34);


    this->canvas->show();
    this->controls->show();
}

Window::~Window()
{
    this->canvas->cleanup();
    delete this->controls;
    delete this->canvas;
    delete this->automata;
}
