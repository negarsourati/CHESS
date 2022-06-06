#include "Rook.h"
Rook::Rook(int x, int y,int color)
    : Piece(x, y, color)
{
    type = 'R';
}
bool Rook::validMove(Position dest, string board[8][8])
{
    if(dest.x < 0 || dest.x >= 8 || dest.y < 0 || dest.y >= 8)
        return false;
    if(dest.y == strt.y && dest.x != strt.x)
    {
        if(dest.x > strt.x)
        {
            for(int i = strt.x + 1; i < dest.x; i++)
                if(board[i][strt.y] != "--")
                    return false;
        }
        else
        {
            for(int i = strt.x - 1; i > dest.x; i--)
                if(board[i][strt.y] != "--")
                    return false;
        }
        return true;
    }
    if(dest.x == strt.x && strt.y != dest.y)
    {
        if(dest.y > strt.y)
        {
            for(int i = strt.y + 1; i < dest.y; i++)
                if(board[strt.x][i] != "--")
                    return false;
        }
        else
        {
            for(int i = strt.y - 1; i > dest.y; i--)
                if(board[strt.x][i] != "--")
                    return false;
        }
        return true;
    }
    else
        return false;
}
vector<Move> Rook::PieceMoves(string board[8][8])
{
   vector<Move> allvalidmoves;
    //ofoghi
    for(int i = strt.x + 1; i < 8; i++)
    {
        if(board[i][strt.y]== "--")
        {
            Position p = {i, strt.y};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }
        else if (board[i][strt.y][1] == board[strt.x][strt.y][1])
            break;
        else
        {
            Position p = {i, strt.y};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
            break;
        }      
    }
    for(int i = strt.x - 1; i >= 0; i--)
    {
        if(board[i][strt.y]== "--")
        {
            Position p = {i, strt.y};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }
        else if (board[i][strt.y][1] ==board[strt.x][strt.y][1])
            break;
        else
        {
            Position p = {i, strt.y};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
            break;
        }      
    }
    //amudi
    for(int i = strt.y + 1; i < 8; i++)
    {
        if(board[strt.x][i]== "--")
        {
            Position p = {strt.x, i};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }
        else if (board[strt.x][i][1] == board[strt.x][strt.y][1])
            break;
        else
        {
            Position p = {strt.x, i};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
            break;
        }      
    }
    for(int i = strt.y - 1; i >= 0; i--)
    {
        if(board[strt.x][i]== "--")
        {
            Position p = {strt.x, i};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }
        else if (board[strt.x][i][1] == board[strt.x][strt.y][1] || board[strt.x][i][0] == 'K')
            break;
        else
        {
            Position p = {strt.x, i};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
            break;
        }      
    }
    return allvalidmoves; 
}