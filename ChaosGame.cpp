// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

void SierpinskiTriangleConstruction(int sides, vector<Vector2f> vertexVec, vector<Vector2f>& pointVec)
{
    for (int i = 0; i < 1000; i++)
    {

        int random = rand() % sides; // random number between 0 and the value of our const SIDES to get our random vertex
        Vector2f midpoint = Vector2f((vertexVec.at(random).x + pointVec.at(pointVec.size() - 1).x) / 2,
            (vertexVec.at(random).y + pointVec.at(pointVec.size() - 1).y) / 2);
        pointVec.push_back(midpoint);
    }
}

void GreaterVertexConstruction(int sides, vector<Vector2f> vertexVec, vector<Vector2f>& pointVec)
{
    int previous = -1;
    for (int i = 0; i < 1000; i++)
    {

        int random = rand() % sides; // random number between 0 and the value of our const SIDES to get our random vertex
        if (random != previous)
        {
            Vector2f midpoint = Vector2f((vertexVec.at(random).x + pointVec.at(pointVec.size() - 1).x) / 2,
                (vertexVec.at(random).y + pointVec.at(pointVec.size() - 1).y) / 2);
            pointVec.push_back(midpoint);

            previous = random;
        }
        else
        {
            i--;
        }

    }
}

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
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if(vertices.size() < SIDES)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if(points.size() == 0)
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
        for (int i = 0; i < points.size(); i++)
        {
            RectangleShape fractal_point(Vector2f(1, 1));
            fractal_point.setPosition(points.at(i));
            window.draw(fractal_point);
        }

        for(int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rect(Vector2f(10,10));
            rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            rect.setFillColor(Color::Blue);
            window.draw(rect);
        }
        window.display();
    }
}