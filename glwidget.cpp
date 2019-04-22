#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent, Automata *automata) : QOpenGLWidget(parent), automata(automata)
{
/*
    this->format = new QSurfaceFormat();
    this->format->setSamples(0);
    this->setFormat(*this->format);
*/

    this->zoom = 0;
}

QSize GLWidget::getResolution()
{
    return this->size();
}

QPoint GLWidget::getMouseCoords()
{
//    return this->cursor().pos();
}

void GLWidget::animate()
{
    update();
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 0);
//    glEnable(GL_MULTISAMPLE);
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void GLWidget::paintEvent(QPaintEvent *event)
{
    makeCurrent();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, this->width(), this->width(), 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    this->automata->render(this->width());
}
void GLWidget::wheelEvent(QWheelEvent *event)
{
    this->zoom += event->angleDelta().y() / 8 / 15;
    makeCurrent();
    this->automata->render(this->width(), this->zoom);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    std::cout << getResolution().rwidth() << getResolution().rheight() << std::endl;
    QString text("x: ");
    text.append(QString::number(event->x()));
    text.append("\ny: ");
    text.append(QString::number(event->y()));
    QMessageBox::information(this, tr("Mouse click position"), text);
}

void GLWidget::cleanup()
{
//    delete this->format;
}
