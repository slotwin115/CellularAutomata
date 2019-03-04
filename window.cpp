#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1024, 768);

    this->button = new QPushButton(tr("Click me"), this);
    this->button->setGeometry(this->width() - 150, 50, 100, 100);
    connect(this->button, SIGNAL(clicked()), this, SLOT(changeButtonText()));
    this->button->show();

    this->canvas = new GLWidget(this);
    this->canvas->setGeometry(50, 50, 700, 700);
    connect(this->button, SIGNAL(clicked()), this, SLOT(changeCanvas()));
    this->canvas->show();
    std::cout << this->canvas->width() << "\n" << this->canvas->height() << std::endl;
}

void Window::changeButtonText()
{
    if(this->button->text() == "Click me")
    {
        this->button->setText("I changed");
    }
    else
    {
        this->button->setText("Click me");
    }
}

void Window::changeCanvas()
{
    this->canvas->update();
}

Window::~Window()
{
    delete this->button;
    this->canvas->cleanup();
    delete this->canvas;
}
