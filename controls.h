#ifndef CONTROLS_H
#define CONTROLS_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSlider>
#include <QTimer>
#include <QPoint>
#include <QGridLayout>
#include <QApplication>

#include <limits>
#include <random>
#include <chrono>
#include <iostream>

#include "automata.h"
#include "glwidget.h"

class Controls : public QWidget
{
    Q_OBJECT

public:
    Controls(QWidget *parent = nullptr, Automata *automata = nullptr, GLWidget *canvas = nullptr);
    ~Controls();
    void show();
    void pollSeed();
    void disableControls();
    void enableControls();

public slots:
    void updateResolutionTextBox(int value);
    void updateResolutionScrollBar(const QString &value);
    void updateResolutionScrollBar(int value);
    void updateSeedTextBox();
    void updateSeed(const QString &value);
    void updateIteration(const QString &value);
    void changeCanvas();
    void changeButtonText();

private:
    QPushButton *startButton;
    QPushButton *randomSeed;
    QLabel *seedLabel;
    QLabel *resolutionLabel;
    QLineEdit *seedTextBox;
    QLineEdit *resolutionTextBox;
    QSlider *resolutionScrollBar;
    Automata *automata;
    GLWidget *canvas;
    QTimer *timer;
    QLabel *iterationLabel;
    QLineEdit *iterationTextBox;
    QGridLayout *layout;
    long seed;
    unsigned long long iteration;
};

#endif // CONTROLS_H
