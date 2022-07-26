#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(400.f, 300.f);
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color(250, 150, 100));

    sf::View view = window.getDefaultView();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized)
            {
                // resize my view
                view.setSize({static_cast<float>(event.size.width),
                              static_cast<float>(event.size.height)});
                window.setView(view);
                // and align shape
                shape.setPosition(window.mapPixelToCoords(sf::Vector2i{window.getSize() / 2u}));
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}