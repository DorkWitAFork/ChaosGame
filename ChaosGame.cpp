// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

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

        if(points.size() > 0)
        {
            ///generate more point(s)
            ///select random vertex
            int previous = -1;
            for (int i = 0; i < 1000; i++)
            {
               
            	int random = rand() % SIDES; // random number between 0 and the value of our const SIDES to get our random vertex
                if (random != previous)
                {
                    Vector2f midpoint = Vector2f((vertices.at(random).x + points.at(points.size() - 1).x) / 2,
												(vertices.at(random).y + points.at(points.size() - 1).y) / 2);
                    points.push_back(midpoint);

                    previous = random;
                }
                else
                {
                    i--;
                }

            }
            ///calculate midpoint between random vertex and the last point in the vector
            ///push back the newly generated coord.
        }
        /*
		****************************************
		Draw
		****************************************
		*/

        
        window.clear();
        for (int i = 0; i < points.size(); i++)
        {
            RectangleShape fractal_point(Vector2f(3, 3));
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