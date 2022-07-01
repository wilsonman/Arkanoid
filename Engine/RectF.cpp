#include "RectF.h"

RectF::RectF(double left_in, double right_in, double top_in, double bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(const Vec2& topLeft, const Vec2& bottomRight)
	:
	RectF(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{
}

RectF::RectF(const Vec2& topLeft, double width, double height)
	:
	RectF(topLeft, topLeft + Vec2(width, height))
{
}

auto RectF::IsOverlappingWith(const RectF& other) const -> bool
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}

auto RectF::IsContainedBy(const RectF& other) const -> bool
{
	return left >= other.left && right <= other.right &&
		top >= other.top && bottom <= other.bottom;
}

RectF RectF::FromCenter(const Vec2& center, double halfWidth, double halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(center - half, center + half);
}

RectF RectF::GetExpanded(double offset) const
{
	return RectF(left - offset, right + offset, top - offset, bottom + offset);
}

Vec2 RectF::GetCenter() const
{
	return Vec2((left + right) / 2.0, (top + bottom) / 2.0);

}
