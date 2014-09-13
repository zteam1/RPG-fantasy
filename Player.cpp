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

#define Largeur 800
#define Hauteur 600

void Player::set_texture(std::string img)
{
    if (!m_texture.loadFromFile(img))
    {
        std::cout<<"erreur chargement texture"<<std::endl;
    }
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
 {
    states.transform *= getTransform();
    target.setView(m_view);
    target.draw(m_sprite, states);
 }

 Player::Player()
 {
     m_vie = 100;
     m_mana = 100;
     m_nom = "";
     m_speed = 0.8f;
 }

 void Player::deplacement()
 {
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
     {
         m_anim.y = Left;
         m_sprite.move(-m_speed, 0);
     }

     else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
     {
         m_anim.y = Right;
         m_sprite.move(m_speed, 0);
     }

     else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
     {
         m_anim.y = Up;
         m_sprite.move(0, -m_speed);
     }

     else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
     {
         m_anim.y = Down;
         m_sprite.move(0, m_speed);
     }
    else
    {
        m_anim.y = Down;
        m_anim.x = 1;
        m_anim.x--;
    }
 }

 void Player::scrolling()
 {

    // gestion animation
    m_anim.x++;
    if(m_anim.x * 32 >= m_texture.getSize().x)
    {
        m_anim.x = 0;
    }
    m_sprite.setTextureRect(sf::IntRect(m_anim.x * 32, m_anim.y * 32, 32, 32));

    // gestion du scrolling
    m_view.reset(sf::FloatRect(0, 0, Largeur, Hauteur));
    sf::Vector2f position(Largeur / 2, Hauteur / 2);
    position.x = m_sprite.getPosition().x + 16 - (Largeur / 2);
    position.y = m_sprite.getPosition().y + 16 - (Hauteur / 2);
    if(position.x < 0)
    {
        position.x = 0;
    }
    if(position.y < 0)
    {
        position.y = 0;
    }
    m_view.reset(sf::FloatRect(position.x, position.y, Largeur, Hauteur));
 }

