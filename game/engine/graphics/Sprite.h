#pragma once

#include <string>

class Sprite
{
public:
	Sprite();
	Sprite(std::string identifier, int x, int y, int width, int height);
	~Sprite();

	/// Returns the x0 value of the sprite.
	int getX() const;
	/// Returns the y0 value of the sprite.
	int getY() const;
	/// Returns the x1 value of the sprite.
	int getWidth() const;
	/// Returns the y1 value of the sprite.
	int getHeight() const;
	/// Returns the identifier of the spritesheet.
	std::string getIdentifier() const;

private:
	unsigned int x, y, width, height;
	std::string identifier;
};