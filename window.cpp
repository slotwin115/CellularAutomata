#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent), canvasOffset(15)
{   
    this->resize(1024, 768);
    this->canvasSize = this->height() - this->canvasOffset * 2;

    this->automata = new Automata(10);

    this->canvas = new GLWidget(this, this->automata);
    this->canvas->setGeometry(this->canvasOffset, this->canvasOffset, this->canvasSize, this->canvasSize);

    this->controls = new Controls(this, this->automata, this->canvas);
    this->controls->setGeometry(this->height(), this->canvasOffset, this->width() - this->height(), this->height());


    this->canvas->show();
    this->controls->show();
}

void Window::resizeEvent(QResizeEvent *event)
{
    const QSize newSize = event->size();
    this->canvasSize = newSize.height() - this->canvasOffset * 2;
    this->canvas->setGeometry(this->canvasOffset, this->canvasOffset, this->canvasSize, this->canvasSize);
    this->controls->setGeometry(newSize.height(), this->canvasOffset, newSize.width() - newSize.height(), newSize.height());
}

Window::~Window()
{
    this->canvas->cleanup();
    delete this->controls;
    delete this->canvas;
    delete this->automata;
}
