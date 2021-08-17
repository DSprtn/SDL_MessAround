#include "ConstrainToWindow.h"
#include <algorithm>
#include <Util\MathHelper.h>

ConstrainToWindow::ConstrainToWindow(Entity* owner, SDL_Window* window, TransformComponent* transform) :  Component(owner)
{
	m_gameWindow = window;
	m_transform = transform;
}

ConstrainToWindow::~ConstrainToWindow()
{
}

void ConstrainToWindow::OnRender()
{
	
}

void ConstrainToWindow::Update()
{
}

void ConstrainToWindow::LateUpdate()
{
	int sizeX = 0;
	int sizeY = 0;
	SDL_GetWindowSize(m_gameWindow, &sizeX, &sizeY);

	float minX = (float)m_transform->Rect.w / 2;
	float minY = (float)m_transform->Rect.y / 2;
	float maxX = sizeX - (float)m_transform->Rect.w / 2;
	float maxY = sizeY - (float) m_transform->Rect.h / 2;
	m_transform->PositionX = MathHelper::Clamp(m_transform->PositionX, minX, maxX);
	m_transform->PositionY = MathHelper::Clamp(m_transform->PositionY, minY, maxY);
}

void ConstrainToWindow::Start()
{
}