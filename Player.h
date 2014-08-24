/**
 *
 * \Nom du fichier : Player.hpp
 * \fonction : la classe du personnage [comme son nom l'indique]
 * \Auteur : Maxia (de ZTeam)
 * \Project : Fantasy RPG
 * \Contributeur : Mohackz[developpeur] ; Maxia[developpeur] ; dalyl-zero[developpeur]
 *
 */

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.h"

class Player: public Entity
{
    public:
        Player();
        void set_texture(std::string img);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        int m_vie;
        int m_mana;
        std::string m_nom;
};


#endif // PLAYER_H_INCLUDED


