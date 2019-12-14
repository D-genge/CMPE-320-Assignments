#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 800), "SFML works!");
	sf::Texture texture;
	texture.setRepeated(true); //tile texture in window, doesn't repeat though?

	if (!texture.loadFromFile("I5.png"))
	{
		// error...
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(0, 0, 205));
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.draw(sprite);
		window.display();
	}

	return 0;
}