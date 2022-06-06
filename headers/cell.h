#ifndef cell_h
#define cell_h
#include <vector>
#include "data.h"
#include "mohre.h"
class Cell
{
    public:
        sf::RectangleShape rect;
        CellStatus cell_status = EMPTY;

};
typedef typename std::vector<std::vector<Cell>> Cells;
#endif