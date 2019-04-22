#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <QPaintEvent>
#include <vector>
#include <random>
#include "cell.h"

class Automata
{
public:
    Automata(unsigned int nCells);
    Automata(unsigned int nCells, long seed);
    void initGrid();
    void initRandomGrid(long seed);
    void randomize(long seed);
    void render(int resolution, int zoom = 0);
    void run();
    unsigned int getnCells();
    void setNCells(unsigned int nCells, bool randomize = false, long seed = 0);
    ~Automata();

private:
    std::vector<std::vector<Cell*>> grid;
    unsigned int nCells;
    long iteration;
};

#endif // AUTOMATA_H
