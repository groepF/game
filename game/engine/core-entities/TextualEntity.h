#pragma once
#include "../util/Color.h"
#include "../graphics/Screen.h"

class TextualEntity
{
public:
	virtual ~TextualEntity() = default;

	/*
	 * The TextualEntity constructor.
	 */
	TextualEntity(std::string identifier, int x = 0, int y = 0, int width = 100, int height = 100, Color color = Color("white"));

	/*
	 * Renders text on a screen.
	 * @param screen The screen to render text on.
	 */
	void Render(Screen& screen);

	std::string get_identifier() const;

protected:
	virtual std::string GetText() = 0;

	/*
	 * An sting to identify the object with.
	 */
	std::string identifier;

	/*
	 * The amount of pixcels from the left.
	 */
	int x;

	/*
	* The amount of pixcels from the top.
	*/
	int y;

	/*
	* The amount of pixcels the text is wide.
	*/
	int width;

	/*
	* The amount of pixcels the text is high.
	*/
	int height;

	/*
	* The color of the text.
	*/
	Color color;
};

