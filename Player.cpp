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

void Player::set_texture(std::string img)
{
    if (!m_texture.loadFromFile(img))
    {
        std::cout<<"erreur chargement texture"<<std::endl;
    }

    m_sprite.setTexture(m_texture);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
 {
     states.transform *= getTransform();
     target.draw(m_sprite, states);
 }

 Player::Player()
 {
     m_vie = 100;
     m_mana = 100;
     m_nom = "";
 }

