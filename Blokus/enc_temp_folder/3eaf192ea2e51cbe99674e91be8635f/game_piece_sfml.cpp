#include <SFML/Graphics.hpp>
#include "game_piece.h"
#include "player.h"


void setColor(int player);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	sf::Texture texturePiece;
	sf::Texture textureBoard;
	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2u WindowSize;   //Added to store window size.
	sf::Sprite gameBoard;
	sf::Sprite gamePiece;

	//load gamepiece images by filename
	if (!textureBoard.loadFromFile("C:\\Users\\neila\\Desktop\\CMPE320\\game_pieces\\board.png")) //!texture.loadFromFile(GamePiece.config+".png")
	{
		// error...
	}
	else
	{
		TextureSize = textureBoard.getSize(); //Get size of texture.
		WindowSize = window.getSize();             //Get size of window.

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

		gameBoard.setTexture(textureBoard);
		gameBoard.setScale(ScaleX, ScaleY);      //Set scale.  
		gameBoard.setColor(sf::Color(128, 128, 128));
	}

	if (!texturePiece.loadFromFile("C:\\Users\\neila\\Desktop\\CMPE320\\game_pieces\\I5.png")) //!texture.loadFromFile(GamePiece.config+".png")
	{ //error...
	}
	else
	{

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.
		gamePiece.setScale(ScaleX, ScaleY);      //Set scale. 
		gamePiece.setTexture(texturePiece);
		gamePiece.setColor(sf::Color(255, 255, 0));
	}

	//figure out how to rescale board and pieces



	/*
	//set colour of gamepiece based upon player id and pass to availPieces
	void setColor(int player, sf::Sprite gamePiece) {
		switch (player) {
		case 1:
			gamePiece.setColor(sf::Color(0, 0, 205)); //set Blue
			break; //optional
		case 2:
			gamePiece.setColor(sf::Color(0, 153, 76)); // set Green
			break; //optional
		case 3:
			gamePiece.setColor(sf::Color(255, 255, 0)); //set Yellow
			break; //optional
		case 4:
			gamePiece.setColor(sf::Color(204, 0, 0)); // set Red
			break; //optional
		}
	

	}
	*/
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(gameBoard);
		window.draw(gamePiece);
		window.display();
	}

	return 0;
}