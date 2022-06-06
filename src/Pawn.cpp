#include"Pawn.h"
Pawn::Pawn(int x, int y,int color)
    : Piece(x, y, color)
{
    type = 'P';
}
bool Pawn::validMove(Position dest, string board[8][8])
{
    if(dest.x < 0 || dest.x >= 8 || dest.y < 0 || dest.y >= 8)
        return false;
    if(color == 1)
    {
        if(strt.x == 1 && dest.x == 3 && board[dest.x][dest.y] == "--")
            return true;
        if(dest.x - strt.x == 1 && abs(dest.y - strt.y) == 1&& board[dest.x][dest.y][1] == 'W')
            return true;
        if(dest.x - strt.x == 1 && abs(dest.y - strt.y) == 0 && board[dest.x][dest.y] == "--")
            return true;        
    }
    if(color == 0)
    {
        if(strt.x == 6 && dest.x == 4 && board[dest.x][dest.y] == "--")
            return true;
        if(dest.x - strt.x == -1 && abs(dest.y - strt.y) == 1 && board[dest.x][dest.y][1] == 'B')
            return true;
        if(dest.x - strt.x == -1 && abs(dest.y - strt.y) == 0 && board[dest.x][dest.y] == "--")
            return true;      
    }
    return false;
}
vector<Move> Pawn::PieceMoves(string board[8][8])
{
    vector<Move> allvalidmoves;
    if(color == 1)
    {
        if(strt.x == 1 && board[3][strt.y] == "--")
        {
            Position p = {3, strt.y};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }    
        if(board[strt.x+1][strt.y] == "--")
        {
            Position p = {strt.x+1, strt.y};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }    
        if(board[strt.x + 1][strt.y-1][1] == 'W' && (strt.x + 1 >= 0 && strt.x + 1 < 8 && strt.y-1 >= 0 && strt.y-1 < 8))
        {
            Position p = {strt.x+1, strt.y-1};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }    
        if(board[strt.x + 1][strt.y+1][1] == 'W' && (strt.x + 1 >= 0 && strt.x + 1 < 8 && strt.y+1 >= 0 && strt.y+1 < 8))
        {
            Position p = {strt.x+1, strt.y+1};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }    
    }
    if(color == 0)
    {
        if(strt.x == 6 && board[4][strt.y] == "--")
        {
            Position p = {4, strt.y};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }    
        if(board[strt.x-1][strt.y] == "--")
        {
            Position p = {strt.x-1, strt.y};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }    
        if(board[strt.x - 1][strt.y+1][1] == 'B' && (strt.x - 1 >= 0 && strt.x - 1 < 8 && strt.y+1 >= 0 && strt.y+1 < 8))
        {
            Position p = {strt.x-1, strt.y+1};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }    
        if(board[strt.x - 1][strt.y-1][1] == 'B' && (strt.x - 1 >= 0 && strt.x - 1 < 8 && strt.y-1 >= 0 && strt.y-1 < 8))
        {
            Position p = {strt.x-1, strt.y-1};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }    
    }
    return allvalidmoves;
}

