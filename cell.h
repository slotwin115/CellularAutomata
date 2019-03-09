#ifndef CELL_H
#define CELL_H

#include <QOpenGLFunctions>
#include <QPainter>

class Cell
{
public:
    Cell(bool state = false);
    ~Cell();

    void setState(bool state);
    bool isAlive();
    void render(unsigned int x, unsigned int y, float size);
private:
    bool state;
};

#endif // CELL_H
