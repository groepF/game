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

	void setLeftPressPosition(int leftPressX, int leftPressY);
	void setRightPressPosition(int rightPressX, int rightPressY);

	int getLeftPressX() const;
	int getLeftPressY() const;

	int getRightPressX() const;
	int getRightPressY() const;

	void setLeftReleasePosition(int leftReleaseX, int leftReleaseY);
	void setRightReleasePosition(int rightReleaseX, int rightReleaseY);

	int getLeftReleaseX() const;
	int getLeftReleaseY() const;

	int getRightReleaseX() const;
	int getRightReleaseY() const;

	bool isLeftPressed() const;
	bool isRightPressed() const;

	void consumeEvent();
private:
	int x, y;
	int leftPressX, leftPressY, rightPressX, rightPressY;
	int leftReleaseX, leftReleaseY, rightReleaseX, rightReleaseY;
	bool leftPressed, rightPressed;
};

