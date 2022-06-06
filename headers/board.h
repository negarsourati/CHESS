#ifndef board_h
#define board_h
#include "SFML/Graphics.hpp"
#include "first.h"
#include "second.h"
#include "pieces.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
class Board
{
    public:
        string board[8][8];
        Piece* pieces[2][16];
        vector<whichPieceMoves> plays;
        int index[2];
        Board();
        void MoveThePiece(Piece* piece, Position dest, int mode);
        void printBoard();
        void reverseMoves();
        bool goodMove(Piece* piece, Move move);
        vector<Move> allGoodMoves(Piece *piece);
        Piece* findKing(int color);
        bool inCheck(int color);
        bool checkMate(int color);
        string resultFormat(Piece* piece, Move move);
};
#endif