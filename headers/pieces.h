#ifndef _pieces_h
#define _pieces_h
#include"first.h"
#include "helper.h"
#include "SFML/Graphics.hpp"
class Piece
{
    public:
        Position strt;
        char type;
        int color;
        int x, y;
        sf::Texture pieceTexture;    
        Piece(int , int , int);
        virtual bool validMove(Position dest, string board[8][8]);
        virtual vector<Move> PieceMoves(string board[8][8]);
        sf::Sprite sprite;
        virtual void load_texture();
};
#endif