#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.hh"
#include "Menu.hh"
#include "Cscreen.hh"

int main()
{
    int action;
    sf::RenderWindow window(sf::VideoMode(1600,1000), "Final_Game");

    Menu menu(window.getSize().x, window.getSize().y);
    action = menu.Run(window);

    if (action == PLAY)
    {
        Game game(window.getSize().x, window.getSize().y, menu.getSelectedItem() + 2);
        game.Run(window);
    }

    window.close();
    return (0);
}
