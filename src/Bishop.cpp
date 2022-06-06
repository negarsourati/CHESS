#include"Bishop.h"
Bishop::Bishop(int x, int y,int color)
    : Piece(x, y, color)
{
    type = 'B';
    this->load_texture();
}
bool Bishop::validMove(Position dest, string board[8][8])
{
    if(dest.x < 0|| dest.x >= 8 || dest.y < 0|| dest.y >= 8)
        return false;
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
vector<Move> Bishop::PieceMoves(string board[8][8])
{
    vector<Move> allvalidmoves;
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
    for(int i = 1 ; i < 8; i++)
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
void Bishop::load_texture()
{
    //pieceTexture.loadFromFile(get_piece_path(this));
    this->sprite.setTexture(pieceTexture);
    float piece_scale_x = (float)100 / this->sprite.getTexture()->getSize().x;
    float piece_scale_y = (float)100 / this->sprite.getTexture()->getSize().y;
    this->sprite.setScale(piece_scale_x, piece_scale_y);
}
