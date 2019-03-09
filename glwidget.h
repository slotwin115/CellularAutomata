#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QPainter>
#include <QOpenGLFunctions>
#include <iostream>
#include <QPoint>
#include <QSize>
#include "automata.h"
#include "cell.h"

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = nullptr, Automata *automata = nullptr);
    void cleanup();
    QPoint getMouseCoords();
    QSize getResolution();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    QSurfaceFormat *format;
    Automata *automata;
};

#endif // GLWIDGET_H
