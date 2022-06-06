#ifndef HELPER_H
#define HELPER_H
#include "first.h"
#include "SFML/Graphics.hpp"
#include "data.h"
#include "pieces.h"
string get_name_of_id();
sf::Vector2f get_cell_position(int row,int column);
int get_cell_index(int x);
string get_piece_path(Piece* piece);
#endif