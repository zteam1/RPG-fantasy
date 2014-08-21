/**
 *
 * \Nom du fichier : Map.cpp
 * \fonction : editer , charger et afficher la map
 * \Auteur : Mohackz (de ZTeam)
 * \Project : Fantasy RPG
 * \Contributeur : Mohackz[developpeur] ; Maxia[developpeur] ; dalyl-zero[developpeur]
 *
 */

#include "Map.hpp"
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <windows.h>

using namespace std;

TileMap::TileMap() : sf::Drawable()
{
    _fileMapPath = "";
    _tilesetPath = "";
    _tileSize = sf::Vector2i(0,0);
    _tileCount = sf::Vector2u(0,0);
}

TileMap::TileMap(const std::string& mapPath)
{
    load(mapPath);
}

void extract_int(const std::string& str,unsigned int* x,unsigned int* y)
{
    string str2;
    if(isdigit(str.c_str()[0]))
    {
        *x = atoi(str.c_str());
    }
    size_t found = str.find(",");
    if(found!=string::npos)
    {
        for(unsigned int i=found+1;i<str.size();i++)
        {
            str2 += str[i];
        }
        *y = atoi(str2.c_str());
    }

}

bool TileMap::load(const std::string& mapPath)
{
    _fileMapPath = mapPath;
        std::ifstream open_map(_fileMapPath,std::ios::in);

        if(open_map.is_open())
        {
            open_map >> _tileSize.y;
            open_map >> _tileSize.x;

            open_map >> _tilesetPath ;

            if(!_tileset.loadFromFile(_tilesetPath))
            {
                std::cout << "Erreur lors du chargement du tileset (Raison : fichier " << _tilesetPath << " introuvable )" << std::endl;
                return false;
            }

            open_map >> _tileCount.y;
            open_map >> _tileCount.x;

            for(unsigned int j=0;j<_tileCount.y;j++)
            {
                std::vector<sf::Vector2u> b;
                _map.push_back(b);
                for(unsigned int i=0;i<_tileCount.x;i++)
                {
                    sf::Vector2u tabb;
                    std::string a;
                    open_map >> a;
                    extract_int(a,&tabb.x,&tabb.y);
                    _map[j].push_back(tabb);
                }
            }

        fillMap();
        open_map.close();
    }
    else
    {
        std::cout << "Erreur lors du chargement du fichier de map (Raison : fichier " << _fileMapPath << " introuvable )" << std::endl;
        return false;
    }

    return true;
}

void TileMap::fillMap()
{
     _vertices.setPrimitiveType(sf::Quads);
    _vertices.resize(_tileCount.x * _tileCount.y * 4);
    for (unsigned int i = 0; i < _tileCount.y; ++i)
    {
        for (unsigned int j = 0; j < _tileCount.x; ++j)
        {

            sf::Vertex* quad = &_vertices[(i + j * _tileCount.y) * 4];

            quad[0].position = sf::Vector2f(j * _tileSize.x, i * _tileSize.y);
            quad[1].position = sf::Vector2f((j + 1) * _tileSize.x, i * _tileSize.y);
            quad[2].position = sf::Vector2f((j + 1) * _tileSize.x, (i + 1) * _tileSize.y);
            quad[3].position = sf::Vector2f(j * _tileSize.x, (i + 1) * _tileSize.y);

            quad[0].texCoords = sf::Vector2f(_map[i][j].x * _tileSize.x, _map[i][j].y * _tileSize.y);
            quad[1].texCoords = sf::Vector2f((_map[i][j].x + 1) * _tileSize.x, _map[i][j].y * _tileSize.y);
            quad[2].texCoords = sf::Vector2f((_map[i][j].x + 1) * _tileSize.x, (_map[i][j].y + 1) * _tileSize.y);
            quad[3].texCoords = sf::Vector2f(_map[i][j].x * _tileSize.x, (_map[i][j].y + 1) * _tileSize.y);
        }
    }

}

sf::Vector2u TileMap::getMapSize()
{
    return sf::Vector2u(_tileCount.x*_tileSize.x,_tileCount.y*_tileSize.y);
}

Tab2D TileMap::getMap()
{
    return _map;
}

sf::FloatRect TileMap::getGlobalBoundsTile(int x_index,int y_index)
{
    return sf::FloatRect(x_index*_tileSize.y,y_index*_tileSize.y,_tileSize.x,_tileSize.y);
}

sf::Vector2i TileMap::getTileSize()
{
    return _tileSize;
}

sf::Vector2u TileMap::getTileCount()
{
    return _tileCount;
}

/*********************************************************************************************************************/
/***************************** La classe Editor (l'editeur de map)  **************************************************/
/*********************************************************************************************************************/
Editor::Editor() : TileMap()
{
    _posMouse = sf::Vector2i(0,0);
    _currentObject = sf::Vector2u(0,0);
    _extension = "lvl";
}

Editor::Editor(const std::string& mapPath) : TileMap(mapPath)
{
    _posMouse = sf::Vector2i(0,0);
    _currentObject = sf::Vector2u(0,0);
    _extension = "lvl";
}

void Editor::init_map()
{
    _map.clear();
    for(unsigned int j=0;j<_tileCount.y;j++)
    {
        std::vector<sf::Vector2u> b;
        _map.push_back(b);
        for(unsigned int i=0;i<_tileCount.x;i++)
        {
            sf::Vector2u d = sf::Vector2u(1,1);
            _map[j].push_back(d);
        }
    }
}

void Editor::run()
{
    _window.create(sf::VideoMode(_tileCount.x*_tileSize.x,_tileCount.y*_tileSize.y,32),"Editor Map");

    while(_window.isOpen())
    {
        sf::Event even;
        while(_window.pollEvent(even))
        {
            switch(even.type)
            {
            case sf::Event::Closed:  _window.close();  break;
            case sf::Event::KeyPressed:
                switch(even.key.code)
                {
                case sf::Keyboard::Space: show_tileset(); break;
                case sf::Keyboard::S: save(); break;
                default: break;
                }
            break;
            case sf::Event::LostFocus: show_tileset(); break;
            default:  break;
            }
        }

        _posMouse.x = sf::Mouse::getPosition(_window).x;
        _posMouse.y = sf::Mouse::getPosition(_window).y;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            _map[_posMouse.y/_tileSize.y][_posMouse.x/_tileSize.x].x = _currentObject.x;
            _map[_posMouse.y/_tileSize.y][_posMouse.x/_tileSize.x].y = _currentObject.y;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            _map[_posMouse.y/_tileSize.y][_posMouse.x/_tileSize.x].x = 9;
            _map[_posMouse.y/_tileSize.y][_posMouse.x/_tileSize.x].y = 1;
        }

        fillMap();

        _window.draw(*this);
        _window.display();
        _window.clear();
    }
}

void Editor::show_tileset()
{
    bool continuer(true);
    sf::RectangleShape rect(sf::Vector2f(_tileSize.x,_tileSize.y));
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(-1);

    sf::Sprite tileset;
    tileset.setTexture(_tileset);

    while(continuer)
    {
        sf::Event even;
        while(_window.pollEvent(even))
        {
            if(even.type == sf::Event::KeyPressed && even.key.code == sf::Keyboard::Escape)
                continuer = false;
        }

        _posMouse.x = sf::Mouse::getPosition(_window).x;
        _posMouse.y = sf::Mouse::getPosition(_window).y;
        unsigned int x = _posMouse.x/_tileSize.x;
        unsigned int y = _posMouse.y/_tileSize.y;

        rect.setPosition(x*_tileSize.x,y*_tileSize.y);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            _currentObject.x = x;
            _currentObject.y = y;
        }

        _window.draw(tileset);
        _window.draw(rect);
        _window.display();
        _window.clear();
    }
}

void Editor::save()
{
    cout << "Saving map ..." << endl;
    ofstream mapTosave("editMap."+_extension,ios::out|ios::trunc);

    if(mapTosave.is_open())
    {
        mapTosave << _tileSize.y << " " << _tileSize.x << endl;
        mapTosave << _tilesetPath << endl;
        mapTosave << _tileCount.y << " " << _tileCount.x << endl;
        for(unsigned int j=0;j<_tileCount.y;j++)
        {
            for(unsigned int i=0;i<_tileCount.x;i++)
            {
                mapTosave << _map[j][i].x << "," << _map[j][i].y << " ";
            }
            mapTosave << endl;
        }
    }
    cout << "Map saved !" << endl;
}

void Editor::setExtension(const std::string& ext)
{
    _extension = ext;
}
