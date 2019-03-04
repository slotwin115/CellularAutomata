#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    this->format = new QSurfaceFormat();
    this->format->setSamples(16);
    this->setFormat(*this->format);

    this->painter = new QPainter();

    this->automata = new Automata(300);
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

//    int dim = 700;
//    int nCells = 301;
//    float cellSize = static_cast<float>(dim) / static_cast<float>(nCells);
//    float ratio = cellSize / dim;

//    int c = 0;
//    for(int x = 0; x < nCells; ++x)
//    {
//        for(int y = 0; y < nCells; ++y)
//        {
//            float leftTop[] = {(x * ratio) * 2 - 1.0f, 1.0f - (y * ratio) * 2};

//            float rightTop[] = {((x + 1) * ratio)  * 2 - 1.0f, 1.0f - (y * ratio) * 2};

//            float rightbottom[] = {((x + 1) * ratio) * 2 - 1.0f, 1.0f - ((y + 1) * ratio) * 2};

//            float leftbottom[] = {(x * ratio) * 2 - 1.0f, 1.0f - ((y + 1) * ratio) * 2};

//            c = (c == 0 ? 1 : 0);

//            glBegin(GL_QUADS);
//                glColor3f(c, c, c);
//                glVertex2f(leftTop[0], leftTop[1]);

//                glColor3f(c, c, c);
//                glVertex2f(rightTop[0], rightTop[1]);

//                glColor3f(c, c, c);
//                glVertex2f(rightbottom[0], rightbottom[1]);

//                glColor3f(c, c, c);
//                glVertex2f(leftbottom[0], leftbottom[1]);
//            glEnd();
//        }
//    }
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void GLWidget::cleanup()
{
    delete this->format;
    delete this->painter;
    delete this->automata;
}
