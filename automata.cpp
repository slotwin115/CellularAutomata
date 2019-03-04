#include "automata.h"

Automata::Automata(unsigned int nCells)
{
    this->nCells = nCells;
    std::vector<Cell*> tmp;
    for(unsigned int i = 0; i < nCells; ++i)
    {
        for(unsigned int j = 0; j < nCells; ++j)
        {
            tmp.push_back(new Cell());
        }
        this->grid.push_back(tmp);
        tmp.clear();
    }
}

Automata::Automata(unsigned int nCells, long seed)
{
    auto rand = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine(seed));
    this->nCells = nCells;
    std::vector<Cell*> tmp;
    for(unsigned int i = 0; i < nCells; ++i)
    {
        for(unsigned int j = 0; j < nCells; ++j)
        {
            tmp.push_back(new Cell(rand()));
        }
        this->grid.push_back(tmp);
        tmp.clear();
    }
}

Automata::~Automata() {}

void Automata::render(int resolution)
{
    float cellSize = static_cast<float>(resolution) / static_cast<float>(this->nCells);
    float ratio = cellSize / resolution;
    for(unsigned int i = 0; i < nCells; ++i)
    {
        for(unsigned int j = 0; j < nCells; ++j)
        {
            this->grid[i][j]->render(i, j, ratio);
        }
    }
}

void Automata::randomize(long seed)
{
    auto rand = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine(seed));
    std::vector<std::vector<Cell*>>::iterator i;
    std::vector<Cell*>::iterator j;
    for(i = this->grid.begin(); i != this->grid.end(); i++)
    {
        for(j = i->begin(); j != i->end(); j++)
        {
            (*j)->setState(rand());
        }
    }
}
