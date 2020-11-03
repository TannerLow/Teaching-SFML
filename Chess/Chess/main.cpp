#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::Sprite shape;
    //shape.setFillColor(sf::Color::Green);

    sf::Texture pog;
    pog.loadFromFile("board.png");
    shape.setTexture(pog);

    while (window.isOpen())
    {
        //poll for events (While loop constantly runs)
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            cout << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << endl;

        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}