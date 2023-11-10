#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

#include "ChaosConstruction.h"

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

void drawFracPoints(vector<Vector2f> pointVec, RenderWindow& window)
{
    for (int i = 0; i < pointVec.size(); i++)
    {
        RectangleShape fractal_point(Vector2f(1, 1));
        fractal_point.setPosition(pointVec.at(i));
        window.draw(fractal_point);
    }
}

void drawVertices(vector<Vector2f> Vec, RenderWindow& window)
{
    for (int i = 0; i < Vec.size(); i++)
    {
        RectangleShape rect(Vector2f(10, 10));
        rect.setPosition(Vector2f(Vec[i].x, Vec[i].y));
        rect.setFillColor(Color::Blue);
        window.draw(rect);
    }
}