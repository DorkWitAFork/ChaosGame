#ifndef ChaosConstruction_H
#define ChaosConstruction_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

using namespace sf;
using namespace std;

void SierpinskiTriangleConstruction(int sides, vector<Vector2f> vertexVec, vector<Vector2f>& pointVec);
void GreaterVertexConstruction(int sides, vector<Vector2f> vertexVec, vector<Vector2f>& pointVec);
void drawFracPoints(vector<Vector2f> pointVec, RenderWindow& window);
void drawVertices(vector<Vector2f> Vec, RenderWindow& window);

#endif 
