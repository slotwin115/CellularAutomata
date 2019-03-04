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
    float leftTop[] = {(x * ratio) * 2 - 1.0f, 1.0f - (y * ratio) * 2};

    float rightTop[] = {((x + 1) * ratio)  * 2 - 1.0f, 1.0f - (y * ratio) * 2};

    float rightbottom[] = {((x + 1) * ratio) * 2 - 1.0f, 1.0f - ((y + 1) * ratio) * 2};

    float leftbottom[] = {(x * ratio) * 2 - 1.0f, 1.0f - ((y + 1) * ratio) * 2};

    int c = this->state ? 1 : 0;

    glBegin(GL_QUADS);
        glColor3f(c, c, c);
        glVertex2f(leftTop[0], leftTop[1]);

        glColor3f(c, c, c);
        glVertex2f(rightTop[0], rightTop[1]);

        glColor3f(c, c, c);
        glVertex2f(rightbottom[0], rightbottom[1]);

        glColor3f(c, c, c);
        glVertex2f(leftbottom[0], leftbottom[1]);
    glEnd();
}
