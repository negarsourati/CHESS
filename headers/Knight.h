#include"first.h"
#include "second.h"
#include "pieces.h"
class Knight : public Piece
{
    public:
        Knight(int x, int y,int color);
        bool validMove(Position dest, string board[8][8]);
        vector<Move> PieceMoves(string board[8][8]);
};    