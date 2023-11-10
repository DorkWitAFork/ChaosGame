// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include "ChaosConstruction.h"

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game", Style::Default);

	vector<Vector2f> vertices;
	vector<Vector2f> points;


	int n;
	cout << "Hey, enter how many sides you would like your shape to have: ";
	cin >> n;

	const int SIDES = n;


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
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					if (vertices.size() < SIDES)
					{
						vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
					}
					else if (points.size() == 0)
					{
						///fourth click
						///push back to points vector
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
			if (SIDES == 3)
			{
				SierpinskiTriangleConstruction(SIDES, vertices, points);
			}
			else
			{
				GreaterVertexConstruction(SIDES, vertices, points);
			}
		}
		/*
		****************************************
		Draw
		****************************************
		*/


		window.clear();
		//function call to draw the vertices
		drawVertices(vertices, window);
		drawFracPoints(points, window);

		window.display();
	}
}
