#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent, Automata *automata) : QOpenGLWidget(parent), automata(automata)
{
    this->format = new QSurfaceFormat();
    this->format->setSamples(16);
    this->setFormat(*this->format);
}

QSize GLWidget::getResolution()
{
    return this->size();
}

QPoint GLWidget::getMouseCoords()
{
    return this->cursor().pos();
}

void GLWidget::initializeGL()
{
    glClearColor(0, 0, 0, 0);
    glEnable(GL_MULTISAMPLE);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    this->automata->render(this->width());
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void GLWidget::cleanup()
{
    delete this->format;
}
