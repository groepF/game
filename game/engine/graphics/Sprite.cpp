#include "Sprite.h"

Sprite::Sprite() : x(0), y(0), width(0), height(0), identifier(nullptr)
{ }

Sprite::Sprite(std::string identifier, int x, int y, int width, int height) : x(x), y(y), width(width), height(height), identifier(identifier)
{ }

Sprite::~Sprite()
{ }

int Sprite::getX() const { return x; }

int Sprite::getY() const { return y; }
int Sprite::getWidth() const { return width; }
int Sprite::getHeight() const { return height; }
std::string Sprite::getIdentifier() const { return identifier; }