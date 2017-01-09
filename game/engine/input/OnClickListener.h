#pragma once

class Button;

class OnClickListener
{
public:
	virtual ~OnClickListener() {

	}

	OnClickListener(OnClickListener const &) = delete;
	OnClickListener & operator=(OnClickListener const &) = delete;

	virtual bool onClick(Button* button) = 0;

protected:
	OnClickListener() = default;

};
