#include"first.h"
#include "second.h"
#include"pieces.h"
class Bishop : public Piece
{
    public:
        Bishop(int x, int y,int color);
        bool validMove(Position dest, string board[8][8]);
        vector<Move> PieceMoves(string board[8][8]);
};    