#pragma once

#include "Ball.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "RectF.h"
#include "Vec2.h"

class Paddle
{
public:
	Paddle(const Vec2& pos_in, double halfWidth_in, double halfHeight_in);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const RectF& wall);
	void Update(const Keyboard& kbd, double dt);
	RectF GetRect() const;
	void ResetCooldown();
private:
	static constexpr Color wingColor = { 210,255,210 };
	static constexpr Color color = { 200,220,200 };
	static constexpr double wingWidth = 6.0;
	static constexpr double speed = 360.0;
	// control the paddle rebound behavior here
	static constexpr double maximumExitRatio = 2.6;
	static constexpr double fixedZoneWidthRatio = 0.2;
	// ----------------------------------------
	double halfWidth;
	double halfHeight;
	// these are derived from above controls
	double exitXFactor;
	double fixedZoneHalfWidth;
	double fixedZoneExitX;
	// -------------------------------------
	Vec2 pos;
	bool isCooldown = false;
};
