#include"first.h"
#include"pieces.h"

Piece::Piece(int x = -1, int y= -1, int cl= -1)
{
    strt.x = x;
    strt.y = y;
    color = cl;
}
bool Piece::validMove(Position dest, string board[8][8])
{
    return true;
}
vector<Move>Piece:: PieceMoves(string board[8][8])
{  
    vector<Move> allvalidmoves;
    return allvalidmoves;
}
