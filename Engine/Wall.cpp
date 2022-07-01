#include <cassert>
#include "Wall.h"

Wall::Wall(const RectF& innerBounds_in, double thickness_in, Color baseColor)
	:
	innerBounds(innerBounds_in),
	thickness(thickness_in),
	bev(baseColor)
{
	// make sure the thickness divides evenly into 2 for layout purposes
	assert(int(thickness) % 2 == 0);
	assert(innerBounds.GetExpanded(thickness).IsContainedBy(Graphics::GetScreenRect()));
}

const RectF& Wall::GetInnerBounds() const
{
	return innerBounds;
}

void Wall::Draw(Graphics& gfx) const
{
	bev.DrawBevelFrame(innerBounds.GetExpanded(thickness), int(thickness) / 2, gfx);
}
