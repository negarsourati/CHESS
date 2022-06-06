#include "helper.h"

sf::Vector2f get_cell_position(int row,int column)
{
    return sf::Vector2f(
        column * (100),
        row * (100));
}
int get_cell_index(int x)
{
    if (x<0)
        return -1;
    int cell_plus_space = 100;
    int index = x / cell_plus_space;
    if (index > 2 || x > index * cell_plus_space + 100)
        return -1;
    return index;
}
string get_piece_path(Piece* piece)
{
    string path = "resources/images/"; 
    path += (piece->color == 0 ? "W" : "B");
    path+= piece->type;
    return path + ".png";
}
