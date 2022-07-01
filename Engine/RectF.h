#pragma once

#include "Vec2.h"

class RectF {
public:
	RectF() = default;
	RectF(double left_in, double right_in, double top_in, double bottom_in);
	RectF(const Vec2& topLeft, const Vec2& bottomRight);
	RectF(const Vec2& topLeft, double width, double height);
	auto IsOverlappingWith(const RectF& other) const -> bool;
	auto IsContainedBy(const RectF& other) const -> bool;
	static RectF FromCenter(const Vec2& center, double halfWidth, double halfHeight);
	RectF GetExpanded(double offset) const;
	Vec2 GetCenter() const;
	double left;
	double right;
	double top;
	double bottom;
};