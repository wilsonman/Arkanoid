#include "Beveler.h"


Beveler::Beveler(Color baseColor)
{
	SetBaseColor(baseColor);
}

void Beveler::DrawOuterBevel(const RectF& rect, int size, Graphics& gfx) const
{
	const int left = int(rect.left);
	const int right = int(rect.right);
	const int top = int(rect.top);
	const int bottom = int(rect.bottom);
	// left side bevel (corner,side,corner)
	gfx.DrawIsoRightTriLL(left, top, size, leftColor);
	gfx.DrawRect(left, top + size, left + size, bottom - size, leftColor);
	gfx.DrawIsoRightTriUL(left, bottom - size, size, leftColor);
	// top side bevel
	gfx.DrawIsoRightTriUR(left, top, size, topColor);
	gfx.DrawRect(left + size, top, right - size, top + size, topColor);
	gfx.DrawIsoRightTriUL(right - size, top, size, topColor);
	// right side bevel
	gfx.DrawIsoRightTriLR(right - size, top, size, rightColor);
	gfx.DrawRect(right - size, top + size, right, bottom - size, rightColor);
	gfx.DrawIsoRightTriUR(right - size, bottom - size, size, rightColor);
	// bottom side bevel
	gfx.DrawIsoRightTriLR(left, bottom - size, size, bottomColor);
	gfx.DrawRect(left + size, bottom - size, right - size, bottom, bottomColor);
	gfx.DrawIsoRightTriLL(right - size, bottom - size, size, bottomColor);
}

void Beveler::DrawInnerBevel(const RectF& rect, int size, Graphics& gfx) const
{
	const int left = int(rect.left);
	const int right = int(rect.right);
	const int top = int(rect.top);
	const int bottom = int(rect.bottom);
	// left side bevel (corner,side,corner)
	gfx.DrawIsoRightTriLL(left, top, size, rightColor);
	gfx.DrawRect(left, top + size, left + size, bottom - size, rightColor);
	gfx.DrawIsoRightTriUL(left, bottom - size, size, rightColor);
	// top side bevel
	gfx.DrawIsoRightTriUR(left, top, size, bottomColor);
	gfx.DrawRect(left + size, top, right - size, top + size, bottomColor);
	gfx.DrawIsoRightTriUL(right - size, top, size, bottomColor);
	// right side bevel
	gfx.DrawIsoRightTriLR(right - size, top, size, leftColor);
	gfx.DrawRect(right - size, top + size, right, bottom - size, leftColor);
	gfx.DrawIsoRightTriUR(right - size, bottom - size, size, leftColor);
	// bottom side bevel
	gfx.DrawIsoRightTriLR(left, bottom - size, size, topColor);
	gfx.DrawRect(left + size, bottom - size, right - size, bottom, topColor);
	gfx.DrawIsoRightTriLL(right - size, bottom - size, size, topColor);
}

void Beveler::DrawBeveledBrick(const RectF& rect, int bevelSize, Graphics& gfx) const
{
	DrawOuterBevel(rect, bevelSize, gfx);
	gfx.DrawRect(rect.GetExpanded(-double(bevelSize)), baseColor);
}

void Beveler::DrawBevelFrame(const RectF& rect, int bevelSize, Graphics& gfx) const
{
	DrawOuterBevel(rect, bevelSize, gfx);
	DrawInnerBevel(rect.GetExpanded(-double(bevelSize)), bevelSize, gfx);
}

Color Beveler::GetBaseColor() const
{
	return baseColor;
}

void Beveler::SetBaseColor(Color base_in)
{
	baseColor = base_in;
	topColor = Color(
		int(double(baseColor.GetR()) * topFactor),
		int(double(baseColor.GetG()) * topFactor),
		int(double(baseColor.GetB()) * topFactor));
	bottomColor = Color(
		int(double(baseColor.GetR()) * bottomFactor),
		int(double(baseColor.GetG()) * bottomFactor),
		int(double(baseColor.GetB()) * bottomFactor));
	leftColor = Color(
		int(double(baseColor.GetR()) * leftFactor),
		int(double(baseColor.GetG()) * leftFactor),
		int(double(baseColor.GetB()) * leftFactor));
	rightColor = Color(
		int(double(baseColor.GetR()) * rightFactor),
		int(double(baseColor.GetG()) * rightFactor),
		int(double(baseColor.GetB()) * rightFactor));
}

