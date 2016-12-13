#include "Widget.h"

Widget::Widget()
{
	
}

std::string Widget::getId() const
{
	return id;
}

void Widget::setId(std::string id)
{
	this->id = id;
}
