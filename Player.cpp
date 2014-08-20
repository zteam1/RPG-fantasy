#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

void Player::set_texture(sf::Texture texture, std::string img)
{
    if (!texture.loadFromFile(img))
    {
        std::cout<<"Erreur lors du chargement texture"<<std::endl;
        //exit(-1); 
    }

    m_sprite.setTexture(m_texture);
}

virtual void Player::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    states *= getTransform();
    target.draw(m_sprite,states);
}

