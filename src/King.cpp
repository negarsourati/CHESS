#include "King.h"
King::King(int x, int y, int color)
    : Piece(x, y, color)
{
    type = 'K';
}
bool King::validMove(Position dest, string board[8][8])
{
    int deltax = abs(dest.x - strt.x);
    int deltay = abs(dest.y - strt.y);
    if(dest.x < 0|| dest.x >= 8|| dest.y < 0 || dest.y >= 8)
        return false;
    if((deltax == 1 && deltay == 1) || (deltax == 0 && deltay == 1) || (deltax == 1 && deltay == 0))     
        return true;
    return false;    
}
vector<Move> King::PieceMoves(string board[8][8])
{
    vector<Move> allvalidmoves;
    int deltax[8] = {1, 1, 1, 0, 0, -1, -1, -1}; 
    int deltay[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    for(int i = 0; i < 8; i++)
    {   
        if((strt.x+deltax[i] >= 0 && strt.x+deltax[i] < 8 && strt.y+deltay[i] >= 0 && strt.y+deltay[i] < 8) && board[strt.x+deltax[i]][strt.y+deltay[i]][1] != board[strt.x][strt.y][1] )
        {  
            Position p = {strt.x+deltax[i], strt.y+deltay[i]};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }    
    }
    return allvalidmoves;
}    
