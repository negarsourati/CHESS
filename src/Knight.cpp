#include "Knight.h"
Knight::Knight(int x, int y,int color)
    : Piece(x, y, color)
{
    type = 'N';
}
bool Knight::validMove(Position dest, string board[8][8])
{
    if(dest.x < 0 || dest.x >= 8 || dest.y < 0 || dest.y >= 8)
        return false;
    int deltax = abs(dest.x - strt.x);
    int deltay = abs(dest.y - strt.y);
    if((deltax == 2 && deltay == 1) || (deltay == 2 && deltax == 1))
    {
        if(board[dest.x][dest.y] == "--"||(board[dest.x][dest.y][1] != board[strt.x][strt.y][1]))
            return true;  
    }
    return false;
}
vector<Move> Knight::PieceMoves(string board[8][8])
{
    vector<Move> allvalidmoves;
    int deltax[8] = {2, 2, 1, 1, -1, -1, -2, -2};
    int deltay[8] = {1, -1, 2, -2, 2, -2, 1, -1};
    for(int i = 0; i < 8; i++)
    {
        if((strt.x+deltax[i] >= 0 && strt.x+deltax[i] < 8 && strt.y+deltay[i] >= 0 && strt.y+deltay[i] < 8) &&( board[strt.x+deltax[i]][strt.y+deltay[i]][1] != board[strt.x][strt.y][1]  ||  board[strt.x+deltax[i]][strt.y+deltay[i]] == "--"))
        {
            Position p = {strt.x+deltax[i], strt.y+deltay[i]};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }    
    }
    return allvalidmoves;
}

