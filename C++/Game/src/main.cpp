#include <SFML/Graphics.hpp>
#include <vector>
#include "Menu.hh"
#include "Cscreen.hh"

int main()
{
    int nScreen;
    std::vector<Cscreen*> screens;
    sf::RenderWindow window(sf::VideoMode(1600,1000), "Final_Game");
    Menu menu(window.getSize().x, window.getSize().y);
    screens.push_back(&menu);

    nScreen = 0;
    while (nScreen >= 0)
	{
		nScreen = screens[nScreen]->Run(window);
	}
    return (0);
}
