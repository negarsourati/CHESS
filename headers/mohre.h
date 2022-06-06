#ifndef mohre_h
#define mohre_h
#include "SFML/Graphics.hpp"
#include "pieces.h"
class mohre
{
    public:
        mohre(Piece*);
        sf::Sprite sprite;
        void load_texture();
};
#endif