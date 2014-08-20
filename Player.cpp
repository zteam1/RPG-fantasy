#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

void Player::set_texture(sf::Texture& texture, std::string img)
{
    if (!texture.loadFromFile(img))
    {
        std::cout<<"erreur chargement texture"<<std::endl;
    }

    m_texture = texture;
    m_sprite.setTexture(m_texture);
}
