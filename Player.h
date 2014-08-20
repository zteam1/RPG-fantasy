#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.h"

class Player: public Entity
{
    public:
        void set_texture(sf::Texture texture, std::string img);

    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
};


#endif // PLAYER_H_INCLUDED
