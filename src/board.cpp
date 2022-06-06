#include "board.h"
Board::Board()
{
    index[0] = index[1] = 0;
    string colorMode;
    cin >> colorMode;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> board[i][j];
    int color;
    char t, c;
    Piece* sample; 
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            t = board[i][j][0];
            c = board[i][j][1];
            if(c == 'W')
                color = 0;
            else if (c == 'B')    
                color = 1;
            else
                color = -1;   
            if(t == 'K')
                sample = new King(i, j, color);
            else if(t == 'Q')
                sample = new Queen(i, j, color);
            else if(t == 'P')
                sample = new Pawn(i, j, color);
            else if(t == 'B')
                sample = new Bishop(i, j, color);
            else if(t == 'N')
                sample = new Knight(i, j, color); 
            else if(t == 'R')
                sample = new Rook(i, j, color);  
            else
                sample = new Piece(-1, -1, -1);    
            if(sample->color != -1) 
            {
                pieces[sample->color][index[sample->color]] = sample;
                index[sample->color]++;
            }
        }
    }
    int cl = (colorMode[0] == 'W') ? 0 : 1;
}
void Board::MoveThePiece(Piece* piece, Position dest, int mode = 1)
{
    if(mode == 1)
    {
        if(board[dest.x][dest.y] != "--" && board[dest.x][dest.y][0] != 'K' && board[dest.x][dest.y][1] != board[piece->strt.x][piece->strt.y][1])
        {
            int colorC;
            if(piece->color == 0)
                colorC = 1;
            else if(piece->color == 1)
                colorC= 0;   
            char colors = (colorC == 0) ? 'W' : 'B';        
        }
    }
    string colorstr;
    if(piece->color == 0)
        colorstr = "W";
    else if(piece->color == 1)
        colorstr = "B";     
    string tmp = piece->type + colorstr;
    board[piece->strt.x][piece->strt.y] = "--"; 
    Move m = {piece->strt, dest};
    piece->strt = dest;
    board[dest.x][dest.y] = tmp;
    whichPieceMoves w ={piece, m};
    if(mode == 1)
        plays.push_back(w);
}
void Board::reverseMoves()
{

}
void Board::printBoard()
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool Board::goodMove(Piece* piece, Move move)
{
    MoveThePiece(piece, move.end);
    if(inCheck(piece->color))
    {
        reverseMoves();
        return false;
    }
    else
    { 
        reverseMoves();
        return true;  
    }      
}
vector<Move> Board::allGoodMoves(Piece *piece)
{
    vector<Move> allposiblemoves; 
    vector<Move> moves = piece->PieceMoves(board);
    for(int k = 0; k < moves.size(); k++)
    {
        if(goodMove(piece, moves[k]))
            allposiblemoves.push_back(moves[k]);
    }
    return allposiblemoves;
}
Piece* Board::findKing(int color)
{
    for(int i = 0; i < index[color]; i++)
        if(pieces[color][i]->type == 'K')
            return pieces[color][i];
    return new Piece(-1, -1, -1);
}  
bool Board::inCheck(int color)
{
    Piece* kingsPos= findKing(color);
    int colorC;
    if(color == 0)
        colorC = 1;
    else if(color == 1)
        colorC= 0;    
    for(int i = 0; i < index[colorC]; i++)
    {
        if(pieces[colorC][i]->validMove(kingsPos->strt, board))
            return true;
    }
    return false;
}
bool Board::checkMate(int color)
{
    bool f = true;
    for(int i = 0; i < index[color]; i++)
    {
        if(allGoodMoves(pieces[color][i]).size() != 0)
        {
            f = false;   
            break;
        }
    }
    return f;
}
string Board::resultFormat(Piece* piece, Move move)
{
    string p0 = "  ";
    p0[0] = (char) ('a'+ move.start.y);
    p0[1] = ('8' - move.start.x) ;
    string pp = "  ";
    pp[0] = piece->type;
    char colstr = (piece->color == 0) ? 'W' : 'B';
    pp[1] = colstr;
    string p1 = "  ";
    p1[0] = (char) ('a'+ move.end.y);
    p1[1] =('8' - move.end.x) ;
    return p0+pp+p1;
}
