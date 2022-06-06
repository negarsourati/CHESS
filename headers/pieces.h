#ifndef _pieces_h
#define _pieces_h
#include"first.h"
class Piece
{
    public:
        Position strt;
        char type;
        int color;
        int x, y;    
        Piece(int , int , int);
        virtual bool validMove(Position dest, string board[8][8]);
        virtual vector<Move> PieceMoves(string board[8][8]);
};
#endif