#include "Shield.h"

#include "Engine.h"
#include <RenderComponent.h>
#include <MathHelper.h>
#include <random>

Shield::Shield() : Entity("Shield", 128,128)
{
	AddComponent<Collider>(Transform);
	m_renderer = AddComponent<RenderComponent>(Engine::Instance->Renderer);
	m_surface = IMG_Load("Assets/shield.png");
	m_texture = SDL_CreateTextureFromSurface(Engine::Instance->Renderer, m_surface);
	m_renderer->SetTexture(m_texture);
}

void Shield::OnHit(float posX, float posY, float radius)
{
	

	int pixelHitPointX = 0;
	int pixelHitpointY = 0;

	const int maxW = m_surface->w;
	const int maxH = m_surface->h;

	// Radius is in world space pixels --- We need to convert to texture space pixels to be consistent across multiple size textures
	const int worldSpacePixelDiameter = (radius * (maxW / (float)Transform->Rect.w)) / 2;

	MathHelper::GetTextureCoordFromWorldPosClamped(m_surface, Transform, posX, posY, pixelHitPointX, pixelHitpointY);



	SDL_LockSurface(m_surface);
	Uint32* tex = (Uint32*)m_surface->pixels;

	std::random_device rd;

	for (int x = 0 - worldSpacePixelDiameter; x < worldSpacePixelDiameter; x++) {
		for (int y = 0 - worldSpacePixelDiameter; y < worldSpacePixelDiameter; y++) {
			int xCoord = pixelHitPointX + x;
			int yCoord = pixelHitpointY + y;

			// Check array bounds
			if (xCoord >= 0 && xCoord < maxW && yCoord >= 0 && yCoord < maxH) {

				// Delete pixels in a 'circle' within the given radius
				float magnitude = MathHelper::GetMagnitudeFrom2DCoords(std::abs(x), std::abs(y));
				if (magnitude < worldSpacePixelDiameter) {
					// Delete pixels randomly with a higher or guaranteed chance of deletion closer to the center
					std::mt19937 mt(rd());
					std::uniform_real_distribution<float> delVal(0, 1);
					
					if (delVal(mt) < 1 - (std::max(0.0f, magnitude - worldSpacePixelDiameter / 3) / worldSpacePixelDiameter)) {
						const int index = MathHelper::GetIndexFrom2DCoord(xCoord, yCoord, m_surface->w, m_surface->h);
						Uint32* pixel = tex + index;
						// Pixel data is encoded as 4 bytes within a 32 bit int (RGBA 0-255, by default.) 
						// Setting a pixel to 0 sets all colors and alpha to 0 simultaneously.
						*pixel = 0;
					}
				}
			}
		}
	}
	
	SDL_UnlockSurface(m_surface);
	SDL_DestroyTexture(m_texture);
	m_texture = SDL_CreateTextureFromSurface(Engine::Instance->Renderer, m_surface);

	m_renderer->SetTexture(m_texture);
}

void Shield::OnCollide(Entity* entity)
{
	if (entity->HasTag("Projectile")) {
		float outX = 0;
		float outY = 0;
		if (CollideRectPerPixel(entity, outX, outY)) {
			entity->Delete();
			OnHit(outX, outY, 32);
		}
	}
}

bool Shield::CollideRectPerPixel(Entity* other, float& outX, float& outY)
{
	TransformComponent* otherT = other->Transform;

	const float otherMinX = otherT->PositionX - otherT->Rect.w / 2;
	const float otherMaxX = otherT->PositionX + otherT->Rect.w / 2;
	const float otherMaxY = otherT->PositionY + otherT->Rect.h / 2;
	const float otherMinY = otherT->PositionY - otherT->Rect.h / 2;

	int minX, minY, maxX, maxY;

	MathHelper::GetTextureCoordFromWorldPosClamped(m_surface, Transform, otherMinX, otherMinY, minX, minY);
	MathHelper::GetTextureCoordFromWorldPosClamped(m_surface, Transform, otherMaxX, otherMaxY, maxX, maxY);

	SDL_LockSurface(m_surface);
	Uint32* tex = (Uint32*)m_surface->pixels;
	bool hit = false;
	for (int x = minX; x < maxX; x++) {
		for (int y = minY ; y < maxY; y++) {
			const int index = MathHelper::GetIndexFrom2DCoord(x, y, m_surface->w, m_surface->h);
			Uint32* pixel = tex + index;
			Uint32 pixelAlpha = *pixel & 0xFF;
			if (pixelAlpha > 0) {

				*pixel = 0;
				if (!hit) {
					MathHelper::GetWorldCoordFromTextureCoord(m_surface, Transform, x, y, outX, outY);
				}
				hit = true;
			}
		}
	}
	SDL_UnlockSurface(m_surface);
	return hit;
}
