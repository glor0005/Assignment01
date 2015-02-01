#include "Asteroid.h"
#include <SDL.h>
#include <math.h>
#include <cstdlib>

Asteroid::Asteroid() : GameObject()
{

}

Asteroid::~Asteroid()
{
}

void Asteroid::Initialize()
{
	isAlive = true;

	asteroid = {rand() % 640, rand() % 640};

	if (asteroid.x > 320)
	{
		if ((asteroid.x - 320) < 20)
		{
			asteroid.x += 20;
		}
	}
	else
	{
		if ((320 - asteroid.x) < 20)
		{
			asteroid.x -= 20;
		}
	}

	asteroidPointA = { rand() % 20, rand() % 20 };
	asteroidPointB = { rand() % 20, -(rand() % 20) };
	asteroidPointC = { -(rand() % 20), -(rand() % 20) };
	asteroidPointD = { -(rand() % 20), rand() % 20 };

	asteroidVelocity.x = rand() % 25 - 25;
	asteroidVelocity.y = rand() % 25 - 25;

	asteroidRadius = (CalcDistanceOffset(asteroidPointA)
		+ CalcDistanceOffset(asteroidPointB)
		+ CalcDistanceOffset(asteroidPointC)
		+ CalcDistanceOffset(asteroidPointD)) / 4;
}

void Asteroid::Update(float dt)
{

	if (asteroid.y > 645)
	{
		asteroid.y = 0;
	}
	else if (asteroid.y < 0)
	{
		asteroid.y = 640;
	}
	else if (asteroid.x > 645)
	{
		asteroid.x = 0;
	}
	else if (asteroid.x < 0)
	{
		asteroid.x = 640;
	}

	asteroid.x += asteroidVelocity.x * dt;
	asteroid.y += asteroidVelocity.y * dt;
}

void Asteroid::Draw(SDL_Renderer * renderer, float dt)
{
	if (isAlive)
	{
		rotationDegrees += (rotationDegrees >= 360.0f ? -360.0f : 0);

		rotationRadians = MathUtils::ToRadians(rotationDegrees);

		rotatedOffsetA =
		{
			asteroidPointA.x * cosf(rotationRadians) + asteroidPointA.y * sinf(rotationRadians),
			asteroidPointA.x * sinf(rotationRadians) - asteroidPointA.y * cosf(rotationRadians)
		};

		rotatedOffsetB =
		{
			asteroidPointB.x * cosf(rotationRadians) + asteroidPointB.y * sinf(rotationRadians),
			asteroidPointB.x * sinf(rotationRadians) - asteroidPointB.y * cosf(rotationRadians)
		};

		rotatedOffsetC =
		{
			asteroidPointC.x * cosf(rotationRadians) + asteroidPointC.y * sinf(rotationRadians),
			asteroidPointC.x * sinf(rotationRadians) - asteroidPointC.y * cosf(rotationRadians)
		};

		rotatedOffsetD =
		{
			asteroidPointD.x * cosf(rotationRadians) + asteroidPointD.y * sinf(rotationRadians),
			asteroidPointD.x * sinf(rotationRadians) - asteroidPointD.y * cosf(rotationRadians)
		};

		transformedEndPointA = { asteroid.x + rotatedOffsetA.x, asteroid.y + rotatedOffsetA.y };
		transformedEndPointB = { asteroid.x + rotatedOffsetB.x, asteroid.y + rotatedOffsetB.y };
		transformedEndPointC = { asteroid.x + rotatedOffsetC.x, asteroid.y + rotatedOffsetC.y };
		transformedEndPointD = { asteroid.x + rotatedOffsetD.x, asteroid.y + rotatedOffsetD.y };

		SDL_RenderDrawLine(renderer, transformedEndPointA.x, transformedEndPointA.y, transformedEndPointB.x, transformedEndPointB.y);
		SDL_RenderDrawLine(renderer, transformedEndPointB.x, transformedEndPointB.y, transformedEndPointC.x, transformedEndPointC.y);
		SDL_RenderDrawLine(renderer, transformedEndPointC.x, transformedEndPointC.y, transformedEndPointD.x, transformedEndPointD.y);
		SDL_RenderDrawLine(renderer, transformedEndPointD.x, transformedEndPointD.y, transformedEndPointA.x, transformedEndPointA.y);
	}
	
}

float Asteroid::CalcDistance(Vector2 v1, Vector2 v2)
{
	return (sqrt((v2.x - v1.x)*(v2.x - v1.x) + (v2.y - v1.y)*(v2.y - v1.y)));
}

float Asteroid::CalcDistanceOffset(Vector2 v1)
{
	return (sqrt((v1.x*v1.x) + (v1.y*v1.y)));
}

