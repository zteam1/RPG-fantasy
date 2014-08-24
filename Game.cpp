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

sf::Time const TimePerFrame = sf::seconds(1.f / 60.f);
Player yazid;

Game::Game() : mWindow(sf::VideoMode(800, 600, 32), "RPG Fantasy")
{

}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    //test zone
    yazid.set_texture("Media/Textures/Player.png");
    //test zone

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
}

void Game::render()
{
    mWindow.clear();
    mMap.load("Maps/Test_1.txt", mWindow);
    mWindow.draw(yazid);
    mWindow.display();
}
