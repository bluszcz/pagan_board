#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H
#include <set>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "data.h"


namespace efc {

std::set<int> getTerrainSet();

}



class TextureHolder
{
public:
    TextureHolder();
    sf::Texture textureTiles;
    sf::Texture textureFaces;
    sf::Texture textureGui;
    sf::Texture textureMenu;
    sf::Texture textureSymbols;
    sf::Texture textureSeasons;
    sf::Texture backgroundDark;
    sf::Texture textureCharacters;
    sf::Texture textureGameBackground;
    sf::Texture textureBoardDiamond;

    std::map<int, std::map<int, int>> tilesDescription;
    std::map<int, std::string> tilesTxt;

};

#endif // TEXTUREHOLDER_H
