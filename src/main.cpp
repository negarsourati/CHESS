#include"board.h"
using namespace sf;
int main()
{   
    RenderWindow window(VideoMode(900, 900), "CHESS", Style::Titlebar | Style::Close);
    Board chessBoard(&window);
    chessBoard.run();
}