#pragma once

#include "Graphics.h"
#include "RectF.h"

class Beveler
{
public:
	Beveler() = default;
	Beveler(Color baseColor);
	void DrawOuterBevel(const RectF& rect, int size, Graphics& gfx) const;
	void DrawInnerBevel(const RectF& rect, int size, Graphics& gfx) const;
	void DrawBeveledBrick(const RectF& rect, int bevelSize, Graphics& gfx) const;
	void DrawBevelFrame(const RectF& rect, int bevelSize, Graphics& gfx) const;
	Color GetBaseColor() const;
	void SetBaseColor(Color base);
private:
	static constexpr double leftFactor = 1.10;
	static constexpr double topFactor = 0.93;
	static constexpr double bottomFactor = 0.80;
	static constexpr double rightFactor = 0.65;
	Color baseColor;
	Color topColor;
	Color bottomColor;
	Color leftColor;
	Color rightColor;
};