#include "guiwindow.h"



GuiWindow::GuiWindow(TextureHolder *textures)
{
    spriteClose.setTexture(textures->textureGui);
    spriteClose.setTextureRect(sf::IntRect(0,0,16,16));
    spriteClose.move(sf::Vector2f(150-16,0));
    if (!guiElemFont.loadFromFile("assets/fnt/8bitOperatorPlus-Regular.ttf"))
    {
        std::exit(1);
    };


    title = "Choose building:";
    guiTitleTxt.setFont(guiElemFont);
    guiTitleTxt.setCharacterSize(10);
    guiTitleTxt.setColor(sf::Color(0,0,0));
    guiTitleTxt.move(2,0);
    guiTitleTxt.setString(title);
}

GuiWindow::GuiWindow(){
    if (!guiElemFont.loadFromFile("assets/fnt/8bitOperatorPlus-Regular.ttf"))
    {
        std::exit(1);
    };
}

void GuiWindow::setTextureHolder(TextureHolder *textures)
{

    spriteClose.setTexture(textures->textureGui);

}


void GuiWindow::init(){
}

void GuiWindow::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    sf::RenderStates states2 = states;
    states2.transform *= getTransform();

    Hover::draw(target, states);
    if (active)
    {
        target.draw(spriteClose, states2);
        target.draw(guiTitleTxt, states2);
    }
}

std::string GuiWindow::getElem(sf::Vector2f mousePosition)
{
    sf::Vector2f hoverPos = getPosition();
    sf::FloatRect spriteBounds = spriteClose.getLocalBounds();
    sf::FloatRect closeRect;
    closeRect.left = spriteClose.getPosition().x;
    closeRect.top = spriteClose.getPosition().y;
    closeRect.width = spriteBounds.width;
    closeRect.height = spriteBounds.height;
    if (closeRect.contains(mousePosition.x - hoverPos.x,mousePosition.y - hoverPos.y))
    {
        return "close_gui";
    }
    else
        return "";
}