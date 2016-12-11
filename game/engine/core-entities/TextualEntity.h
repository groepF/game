#pragma once
#include "../util/Color.h"
#include "../graphics/Screen.h"
#include "../world/Body.h"
#include "../graphics/render-strategies/data-providers/ITextRenderDataPorvider.h"

class TextualEntity : public Body, public ITextRenderDataPorvider
{
public:
	~TextualEntity() = default;

	/*
	 * The TextualEntity constructor.
	 */
	TextualEntity(std::string identifier, int x = 0, int y = 0, int width = 100, int height = 100, Color color = Color("white"));

	/*
	 * Renders text on a screen.
	 * @param screen The screen to render text on.
	 */
	void Render(Screen& screen, bool debug) const override;

	std::string get_identifier() const;

	std::string getText() override;
	Color getColor() override;
	int getX() override;
	virtual int getY() override;
	int getWidth() override;
	int getHeight() override;

	void setDefaultRenderStrategy() override;
protected:

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

