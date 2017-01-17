#pragma once
#include "../graphics/render-strategies/data-providers/IDrawableRenderDataProvider.h"
#include "../world/Body.h"

class DrawableEntity : public Body, public IDrawableRenderDataProvider
{
public:
	DrawableEntity(std::shared_ptr<Sprite> s, float x, float y, float width, float height, bool dynamic = false, float angularDamping = 0.0f, float linearDamping = 0.0f, bool isPlayer = false);
	~DrawableEntity() = default;

	void Render(Screen& screen, bool debug) const override;

	float getX() const override;
	float getY() const override;
	float getHeight() const override;
	float getWidth() const override;
	double getAngle() const override;
	Sprite* getSprite() const override;
	void setSprites(Sprite sprite, Sprite sprite2);
	void setSpriteJump();
	void toggleSprite();
	int getPPM() const override;

	void setDefaultRenderStrategy() override;

	void setLinearVelocity(int, int);

protected:
	std::shared_ptr<Sprite> sprite;
	std::shared_ptr<Sprite> secondSprite;

	std::shared_ptr<Sprite> stillSprite;
	std::shared_ptr<Sprite> walkSprite;
};

