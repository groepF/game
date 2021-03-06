#pragma once
#include "../../../util/Color.h"

class ITextRenderDataProvider
{
public:
	virtual ~ITextRenderDataProvider() {}

	virtual std::string getText() = 0;
	virtual Color getColor() = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
};

