#pragma once

#include <exception>

class MathHelper
{
public:
	template <typename T>
	static T Clamp(const T& n, const T& lower, const T& upper) {
		return std::max(lower, std::min(n, upper));
	}

	
	template<typename T>
	static float GetMagnitudeFrom2DCoords(T x, T y) {
		return std::sqrt(x * x + y * y);
	}

	static int GetIndexFrom2DCoord(int row, int col, int width, int height) {
		int index = row + col * width;
		return index;
	}

	static void Get2DCoordFromIndex(int index, int& row, int& col, int width) {
		
		if (index < width) {
			row = index;
			col = 0;
			return;
		}
		row = index % width;
		col = index / width;
	}

	static void SetPixel(SDL_Surface* surface, int x, int y, Uint32 pixel)
	{
		Uint32* const target_pixel = (Uint32*)((Uint8*)surface->pixels
			+ y * surface->pitch
			+ x * surface->format->BytesPerPixel);
		*target_pixel = pixel;
	}

	static Uint32* GetPixel(SDL_Surface* surface, int x, int y)
	{
		Uint32* const target_pixel = (Uint32*)((Uint8*)surface->pixels
			+ y * surface->pitch
			+ x * surface->format->BytesPerPixel);
		return target_pixel;
	}


	template<typename T>
	static T InverseLerp(T min, T max, T val) {
		if (val < min) {
			return 0;
		}
		if (val > max) {
			return 1;
		}
		
		val -= min;
		T range = max - min;
		return val / range;
	}

	/// <summary>
	/// Convert world position to surface texture pixel coordinate. Returns 'closest' point on texture if point is outside of it.
	/// </summary>
	static void GetTextureCoordFromWorldPosClamped(SDL_Surface* surf, TransformComponent* transform, float xPos, float yPos, int& outX, int& outY) {
		if (surf == nullptr) {
			throw std::exception("Null surface passed!");
		}
		const float xMin = transform->PositionX - transform->Rect.w / 2;
		const float xMax = transform->PositionX + transform->Rect.w / 2;
		const float yMin = transform->PositionY - transform->Rect.h / 2;
		const float yMax = transform->PositionY + transform->Rect.h / 2;


		// Clamp worldPos to transform rect

		xPos = Clamp(xPos, xMin, xMax);
		yPos = Clamp(yPos, yMin, yMax);

		outX = (int) (InverseLerp(xMin, xMax, xPos) * surf->w);
		outY = (int) (InverseLerp(yMin, yMax, yPos) * surf->h);
	}

	/// <summary>
	/// Convert surface texture position to world coordinates.
	/// </summary>
	static void GetWorldCoordFromTextureCoord(SDL_Surface* surf, TransformComponent* transform, int xPos, int yPos, float& outX, float& outY) {
		if (surf == nullptr) {
			throw std::exception("Null surface passed!");
		}
		const float xPosMin = transform->PositionX - transform->Rect.w / 2;
		const float yPosMin = transform->PositionY - transform->Rect.h / 2;
	
		const int xMax = surf->w;
		const int yMax = surf->h;

		outX = xPosMin + InverseLerp(0.0f, (float)xMax, (float)xPos) * transform->Rect.w;
		outY = yPosMin + InverseLerp(0.0f, (float)yMax, (float)yPos) * transform->Rect.h;
	}
};

