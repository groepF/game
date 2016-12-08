#pragma once
enum MouseType
{
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_MIDDLE
};

class Mouse
{
public:
	Mouse();
	~Mouse();

	void setPosition(int x, int y);

	int getX() const;
	int getY() const;

	void setLeftPressed(bool pressed);
	void setRightPressed(bool pressed);

	void setLeftPressX(int leftPressX);
	void setLeftPressY(int leftPressY);

	int getLeftPressX() const;
	int getLeftPressY() const;

	bool isLeftPressed() const;
	bool isRightPressed() const;
private:
	int x, y;
	int leftPressX, leftPressY;
	bool leftPressed, rightPressed;
};

