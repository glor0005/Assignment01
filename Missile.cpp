#include "Missile.h"
#include <SDL.h>
#include <math.h>
#include <iostream>

Missile::Missile() : GameObject()
{

}

Missile::~Missile()
{

}

void Missile::Initialize()
{
	missilePosition = { _transform.position.x, _transform.position.y };
	missileOffSet =
	{
		10 * sinf(MathUtils::ToRadians(_transform.rotation.x)),
		(-10) * cosf(MathUtils::ToRadians(_transform.rotation.x))
	};
	missileLife = 0.7;

}

void Missile::Update(float dt)
{
	if (missileFired)
	{
		missileLife -= dt;
		missilePosition.x += (missileOffSet.x*dt * 50);
		missilePosition.y += (missileOffSet.y*dt * 50);
	}
	if (missileLife < 0.0)
	{
		printf("Missle Erased\n");
		missileFired = false;
	}

	// Boundry checks
	if (missilePosition.x > 640)
	{
		missilePosition.x -= 640;
	}
	if (missilePosition.x < 0)
	{
		missilePosition.x += 640;
	}
	if (missilePosition.y > 640)
	{
		missilePosition.y -= 640;
	}
	if (missilePosition.y < 0)
	{
		missilePosition.y += 640;
	}

}

void Missile::Draw(SDL_Renderer *renderer, float dt)
{
	if (missileFired)
	{
		Reform(&missilePosition);
		SDL_RenderDrawLine
			(renderer,
			missilePosition.x,
			missilePosition.y,
			missilePosition.x + missileOffSet.x,
			missilePosition.y + missileOffSet.y
			);
	}

}

void Missile::Reform(Vector2* point)
{
	if (point->x > 640)
		point->x -= 640;
	if (point->x < 0)
		point->x += 640;
	if (point->y > 640)
		point->y -= 640;
	if (point->y < 0)
		point->y += 640;


}

void Missile::Reform3(Vector3* point)
{
	if (point->x > 640)
		point->x -= 640;
	if (point->x < 0)
		point->x += 640;
	if (point->y > 640)
		point->y -= 640;
	if (point->y < 0)
		point->y += 640;
	if (point->z > 640)
		point->z -= 640;
	if (point->z < 0)
		point->z += 640;
}

Transform& Missile::GetTransform()
{
	return _transform;
}

void Missile::SetTransform(Transform transform)
{

	this->_transform = transform;

}
