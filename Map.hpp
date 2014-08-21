/**
 *
 * \Nom du fichier : Map.cpp
 * \fonction : editer , charger et afficher la map
 * \Auteur : Mohackz (de ZTeam)
 * \Project : Fantasy RPG
 * \Contributeur : Mohackz[developpeur] ; Maxia[developpeur] ; dalyl-zero[developpeur]
 *
 */

#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

    typedef std::vector<std::vector<sf::Vector2u> > Tab2D;

    class TileMap : public sf::Drawable
    {
    public:
        TileMap();
        TileMap(const std::string& mapPath);
        bool load(const std::string& mapPath);
        sf::Vector2u getMapSize();
        sf::Vector2i getTileSize();
        sf::Vector2u getTileCount();
        Tab2D getMap();
        sf::FloatRect getGlobalBoundsTile(int x_index,int y_index);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.texture = &_tileset;
            target.draw(_vertices, states);
        }
    protected:
        void fillMap();
        Tab2D _map;
        std::vector<std::vector<bool> > _isBlock;
        std::string _fileMapPath , _tilesetPath ;
        sf::Vector2i _tileSize;
        sf::Vector2u _tileCount;
        sf::Texture _tileset;
        sf::VertexArray _vertices;
    };
    class Editor : public TileMap
    {
    public:
        Editor();
        Editor(const std::string& mapPath);
        void run();
        void setExtension(const std::string& ext);
    private:
        void save();
        void init_map();
        void show_tileset();
        sf::Vector2i _posMouse;
        sf::Vector2u _currentObject;
        sf::RenderWindow _window;
        std::string _extension;
    };

#endif // MAP_HPP_INCLUDED
