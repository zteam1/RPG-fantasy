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
#include "Entity.hpp"

class Player: public Entity
{
    public:
        void set_texture(sf::Texture texture, std::string img);
    private:
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
};


#endif // PLAYER_H_INCLUDED

