/**
 *
 * \Nom du fichier : Player.cpp
 * \fonction : la classe du personnage [comme son nom l'indique]
 * \Auteur : Maxia (de ZTeam)
 * \Project : Fantasy RPG
 * \Contributeur : Mohackz[developpeur] ; Maxia[developpeur] ; dalyl-zero[developpeur]
 *
 */

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

    m_texture = texture;
    m_sprite.setTexture(m_texture);
}


