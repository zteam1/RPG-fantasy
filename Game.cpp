/**
 *
 * \Nom du fichier : Game.cpp
 * \fonction : la classe de base du game engine
 * \Auteur : Maxia (de ZTeam)
 * \Project : Fantasy RPG
 * \Contributeur : Mohackz[developpeur] ; Maxia[developpeur] ; dalyl-zero[developpeur]
 *
 */

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Map.hpp"
#include "Player.h"
#include "Entity.h"
#include "Fonctions.h"

sf::Time const TimePerFrame = sf::seconds(1.f / 60.f);
Player yazid;

Game::Game() : mWindow(sf::VideoMode(800, 600, 32), "RPG Fantasy")
{
    mWindow.setFramerateLimit(60);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    yazid.set_texture("Media/Textures/player.png");

    while(mWindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        processEvents();
        update(TimePerFrame);
        while(timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::handlePlayerInput(sf::Keyboard key, bool isPressed)
{
}


// récuperer les evenements
void Game::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed :
                mWindow.close();
                break;

            default :
                break;
        }
    }
}

void Game::update(sf::Time)
{
    yazid.deplacement();
    yazid.scrolling();
}


// le rendu final
void Game::render()
{
    mWindow.clear();
    mMap.load("Maps/Test_1.txt", mWindow);
    mWindow.draw(yazid);
    mWindow.display();
}
