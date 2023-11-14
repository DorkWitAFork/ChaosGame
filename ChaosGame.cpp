// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include "ChaosConstruction.h"
#include "TextHandler.h"

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game", Style::Fullscreen);

	vector<Vector2f> vertices;
	vector<Vector2f> points;
	string playerInput;

	Font font;
	font.loadFromFile("Pixellettersfull-BnJ5.ttf");

	Text titleText("CHAOS GAME >:)", font, 32);
	Text askForInputText("Please enter the amount of vertices for your shape: ", font, 32);
	Text resetText("Press Q to reset", font, 32);
	Text vertexNumText("", font, 32);
	Text clickInputText("", font, 32);

	/*
		setAttributes is a TextHandler function that sets Position, includes an optional Style parameter, and defaults Color
		to white in the following formats:
			setAttributes(Text object, leftmost position, topmost position, Style parameter);
			setAttributes(Text object, leftmost position, topmost position);
	*/

	setAttributes(titleText, 20, 8, Text::Bold);
	FloatRect referenceRect1 = titleText.getGlobalBounds();

	setAttributes(askForInputText, 20, referenceRect1.top + referenceRect1.height + 10);
	FloatRect referenceRect2 = askForInputText.getGlobalBounds();

	FloatRect resetTextBounds = resetText.getLocalBounds();
	setAttributes(resetText, 1920 - resetTextBounds.width - 20, 1080 - resetTextBounds.height - 36);

	setAttributes(vertexNumText, referenceRect2.width + 30, referenceRect1.top + referenceRect1.height + 10);
	setAttributes(clickInputText, 20, referenceRect2.top + referenceRect2.height + 10);

	int n = 0;

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				// Quit the game when the window is closed
				window.close();
			}

			if (event.type == sf::Event::TextEntered && n == 0)
			{
				if (isdigit(event.text.unicode))
				{
					playerInput += event.text.unicode;
					vertexNumText.setString(playerInput);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				if (playerInput != "")
				{
					n = stoi(playerInput);

					ostringstream out;
					out << "Please click " << n << " points to create your vertices:";

					clickInputText.setString(out.str());
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Backspace) && n == 0)
			{
				if (playerInput.length() > 0)
				{
					playerInput.pop_back();
					vertexNumText.setString(playerInput);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Q) && points.size() > (10000 * n))
			{
				n = 0;
				playerInput = "";

				vertexNumText.setString("");
				clickInputText.setString("");

				vertices.clear();
				points.clear();
			}

			if (event.type == Event::MouseButtonPressed && n > 2)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					if (vertices.size() < n)
					{
						vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
					}
					else if (points.size() == 0)
					{
						// Last click from user input, pushes back into points vector
						points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
					}
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		****************************************
		Update
		****************************************
		*/

		if (points.size() > 0)
		{
			if (n == 3)
			{
				SierpinskiTriangleConstruction(n, vertices, points); // Constructs a Sierpinski triangle
			}
			else
			{
				GreaterVertexConstruction(n, vertices, points); // Constructs fractals composed of 4 or more vertices
			}
		}

		/*
		****************************************
		Draw
		****************************************
		*/


		window.clear();

		window.draw(titleText);
		window.draw(askForInputText);
		window.draw(vertexNumText);
		window.draw(clickInputText);
		if (points.size() > (10000 * n))
		{
			window.draw(resetText);
		}

		// Function call to draw the vertices
		drawVertices(vertices, window);
		drawFracPoints(points, window);

		window.display();
	}
}
