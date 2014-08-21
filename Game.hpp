/**
 *
 * \Nom du fichier : Game.hpp
 * \fonction : la classe de base du game engine
 * \Auteur : Maxia (de ZTeam)
 * \Project : Fantasy RPG
 * \Contributeur : Mohackz[developpeur] ; Maxia[developpeur] ; dalyl-zero[developpeur]
 *
 */

#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "Map.hpp"

class Game
{
public :

    Game();
    void run();
    void handlePlayerInput(sf::Keyboard key, bool isPressed);

private :

    void processEvents();
    void update(sf::Time);
    void render();

private :

    sf::RenderWindow mWindow;
    TileMap mMap;

};

#endif // GAME_HPP_INCLUDED
