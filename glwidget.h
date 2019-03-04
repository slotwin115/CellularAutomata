#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QPainter>
#include <QOpenGLFunctions>
#include <iostream>
#include "automata.h"
#include "cell.h"

class GLWidget : public QOpenGLWidget
{
public:
    GLWidget(QWidget *parent = nullptr);
    void cleanup();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    QSurfaceFormat *format;
    QPainter *painter;
    Automata *automata;
};

#endif // GLWIDGET_H
