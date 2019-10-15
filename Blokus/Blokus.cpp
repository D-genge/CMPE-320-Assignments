// Blokus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Blokus!");
	window.setFramerateLimit(60);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	
	Game game = Game();
	GamePiece currentPiece = game.currentPlayer().getAvalPiece();
	GridLoc placement = GridLoc(0,0);
	while (window.isOpen())
	{
		
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::W) {
					placement = GridLoc(placement.x, placement.y+1);
				}
				if (event.key.code == sf::Keyboard::A) {
					placement = GridLoc(placement.x-1, placement.y);
				}
				if (event.key.code == sf::Keyboard::S) {
					placement = GridLoc(placement.x, placement.y-1);
				}
				if (event.key.code == sf::Keyboard::D) {
					placement = GridLoc(placement.x+1, placement.y);
				}
				if (event.key.code == sf::Keyboard::R) {
					currentPiece.rotate(1);
				}
				if (event.key.code == sf::Keyboard::E) {
					currentPiece.rotate(-1);
				}
				if (event.key.code == sf::Keyboard::F) {
					currentPiece.flip();
				}
				if (event.key.code == sf::Keyboard::C) {
					currentPiece = game.currentPlayer().getAvalPiece();
					// Change Piece - picks different random one, would be better to cycle through
				}
				if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space) {
					bool placed = game.getGameBoard().placePiece(currentPiece, placement, game.currentPlayer());
					if (placed) {
						game.change_turn();
						currentPiece = game.currentPlayer().getAvalPiece();
					}
				}
				break;
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
		game.terminalDraw(placement, currentPiece); 

	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
