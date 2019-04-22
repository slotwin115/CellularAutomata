#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QPainter>
#include <QOpenGLFunctions>
#include <iostream>
#include <QPoint>
#include <QSize>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QtOpenGL>
#include <iostream>
#include "automata.h"

class Controls;

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = nullptr, Automata *automata = nullptr);
    void cleanup();
    QPoint getMouseCoords();
    QSize getResolution();

public slots:
    void animate();

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintEvent(QPaintEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
//    QSurfaceFormat *format;
    Automata *automata;
    Controls *controls;
    //! \brief zoom -> respresents zoom factor.
    int zoom;
};

#endif // GLWIDGET_H
