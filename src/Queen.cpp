#include"Queen.h"
Queen::Queen(int x, int y,int color)
    : Piece(x, y, color)
{
    type = 'Q';
}
bool Queen::validMove(Position dest, string board[8][8])
{
    if(dest.x < 0|| dest.x >= 8 || dest.y < 0 || dest.y >= 8)
        return false;
    //amudi
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
    //ofoghi
    if(dest.x == strt.x && dest.y != strt.y)
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
    //ghotri
    if(abs(dest.x - strt.x) == abs(dest.y - strt.y))
    {
        int deltax = abs(strt.x - dest.x);
        if(dest.x > strt.x && dest.y > strt.y)
        {
            for(int i = 1; i < deltax; i++)
                if(board[strt.x + i][strt.y + i] != "--")
                    return false;       
        }            
        else if(dest.x > strt.x && dest.y < strt.y)
        {
            for(int i = 1; i < deltax; i++)
                if(board[strt.x + i][strt.y - i] != "--")
                    return false;       
        }
        else if(dest.x < strt.x && dest.y > strt.y)
        {
            for(int i = 1; i < deltax; i++)
                if(board[strt.x - i][strt.y + i] != "--")
                    return false;        
        }
        else
        {
            for(int i = 1; i < deltax; i++)
                if(board[strt.x - i][strt.y - i] != "--")
                    return false;      
        } 
        return true;           
    }
    else
        return false;
        
}
vector<Move> Queen::PieceMoves(string board[8][8])
{
    vector<Move> allvalidmoves;
    //amudi
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
    //ofoghi
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
    //ghotri
    for(int i =  1 ; i < 8; i++)
    {
        if(strt.x+i == 8 || strt.y+i == 8)
            break;
        if(board[strt.x + i][strt.y + i]== "--")
        {
            Position p = {strt.x+i, strt.y+i};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }
        else if (board[strt.x + i][strt.y + i][1] == board[strt.x][strt.y][1])
            break;
        else
        {
            Position p = {strt.x+i, strt.y+i};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
            break;
        }     
    }
    for(int i =  1 ; i < 8; i++)
    {
        if(strt.x-i == -1 || strt.y+i == 8)
            break;
        if(board[strt.x - i][strt.y + i]== "--")
            {
                Position p = {strt.x-i, strt.y+i};
                Move m = {strt, p};
                allvalidmoves.push_back(m);
            }
        else if (board[strt.x - i][strt.y + i][1] == board[strt.x][strt.y][1])
            break;
        else
        {
            Position p = {strt.x-i, strt.y+i};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
            break;
        }     
    }
    for(int i =  1 ; i < 8; i++)
    {
        if(strt.x+i == 8 || strt.y-i == -1)
            break;
        if(board[strt.x + i][strt.y - i]== "--")
        {
            Position p = {strt.x+i, strt.y-i};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }
        else if (board[strt.x + i][strt.y - i][1] == board[strt.x][strt.y][1])
            break;
        else
        {
            Position p = {strt.x+i, strt.y-i};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
            break;
        }     
    }
    for(int i =  1 ; i < 8; i++)
    {
        if(strt.x-i == -1 || strt.y-i == -1)
            break;
        if(board[strt.x - i][strt.y - i]== "--")
        {
            Position p = {strt.x-i, strt.y-i};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
        }
        else if (board[strt.x - i][strt.y - i][1] == board[strt.x][strt.y][1])
            break;
        else
        {
            Position p = {strt.x-i, strt.y-i};
            Move m = {strt, p};
            allvalidmoves.push_back(m);
            break;
        }     
    }
    return allvalidmoves;
}