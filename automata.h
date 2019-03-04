#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <vector>
#include <random>
#include <chrono>
#include <limits>
#include <iostream>
#include "cell.h"

class Automata
{
public:
    Automata(unsigned int nCells);
    Automata(unsigned int nCells, long seed);
    void randomize(long seed);
    void render(int resolution);
    void run();
    ~Automata();

private:
    std::vector<std::vector<Cell*>> grid;
    unsigned int nCells;
    long iteration;
};

#endif // AUTOMATA_H
