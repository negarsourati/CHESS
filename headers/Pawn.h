#include"first.h"
#include "second.h"
#include "pieces.h"
class Pawn : public Piece
{
    public:
        Pawn(int x, int y,int color);
        bool validMove(Position dest, string board[8][8]);
        vector<Move> PieceMoves(string board[8][8]);
};    