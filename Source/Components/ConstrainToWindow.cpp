#include "ConstrainToWindow.h"
#include <algorithm>
#include <MathHelper.h>

ConstrainToWindow::ConstrainToWindow(Entity* owner, SDL_Window* window, TransformComponent* transform) :  Component(owner)
{
	m_gameWindow = window;
	Transform = transform;
}


void ConstrainToWindow::LateUpdate()
{
	int sizeX = 0;
	int sizeY = 0;
	SDL_GetWindowSize(m_gameWindow, &sizeX, &sizeY);

	const float minX = (float)Transform->Rect.w / 2;
	const float minY = (float)Transform->Rect.y / 2;
	const float maxX = sizeX - (float)Transform->Rect.w / 2;
	const float maxY = sizeY - (float) Transform->Rect.h / 2;
	Transform->PositionX = MathHelper::Clamp(Transform->PositionX, minX, maxX);
	Transform->PositionY = MathHelper::Clamp(Transform->PositionY, minY, maxY);
}