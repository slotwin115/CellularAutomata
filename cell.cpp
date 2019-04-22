#include "cell.h"

Cell::Cell(bool state)
{
    this->state = state;
}

void Cell::setState(bool state)
{
    this->state = state;
}

bool Cell::isAlive()
{
    return this->state;
}

void Cell::render(unsigned int x, unsigned int y, float ratio)
{
    // optimalization
    /*
     * (baseX, baseY)                    (baseX + ratio, baseY)
     *              *---------------------*
     *              |                     |
     *              |                     |
     *              |                     |
     *              |                     |
     *              |                     |
     *              |                     |
     *              |                     |
     *              *---------------------*
     *  (baseX, baseY + ratio)      (baseX + ratio, baseY + ratio)
    */
    float baseX = x * ratio;
    float baseY = y * ratio;

    float leftTop[2] = {baseX, baseY};
    float rightTop[2] = {baseX + ratio, baseY};
    float rightBottom[2] = {baseX + ratio, baseY + ratio};
    float leftBottom[2] = {baseX, baseY + ratio};

    int c = this->state ? 1 : 0;

    glBegin(GL_QUADS);
        glColor3f(c, c, c);
        glVertex2f(leftTop[0], leftTop[1]);

        glColor3f(c, c, c);
        glVertex2f(rightTop[0], rightTop[1]);

        glColor3f(c, c, c);
        glVertex2f(rightBottom[0], rightBottom[1]);

        glColor3f(c, c, c);
        glVertex2f(leftBottom[0], leftBottom[1]);
    glEnd();
}

Cell::~Cell() {}
