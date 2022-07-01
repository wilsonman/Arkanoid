#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"

class Ball
{
public:
	Ball() = default;
	Ball(const Vec2& pos_in, const Vec2& dir_in);
	void Draw(Graphics& gfx) const;
	void Update(double dt);
	// return: 0=nada 1=hit wall 2=hit bottom
	int DoWallCollision(const RectF& wall);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	Vec2 GetVelocity() const;
	Vec2 GetPosition() const;
	void SetDirection(const Vec2& dir);
private:
	static constexpr double radius = 7.0;
	double speed = 400.0;
	Vec2 pos;
	Vec2 vel{};
};
