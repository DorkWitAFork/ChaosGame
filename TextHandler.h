#ifndef TextHandler_H
#define TextHandler_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

void setAttributes(Text& textIn, float f1, float f2, Uint32 style);
void setAttributes(Text& textIn, float f1, float f2);
#endif