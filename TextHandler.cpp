#include "TextHandler.h"

void setAttributes(Text& textIn, float left, float top, Uint32 style)
{
	textIn.setPosition(left, top);
	textIn.setStyle(style);
	textIn.setFillColor(Color::White);
}

void setAttributes(Text& textIn, float left, float top)
{
	textIn.setPosition(left, top);
	textIn.setFillColor(Color::White);
}