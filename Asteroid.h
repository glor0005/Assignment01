#pragma once

#include "GameObject.h"
#include <SDL.h>

class Asteroid : public GameObject
{
public:
	Asteroid();
	~Asteroid();

	Vector2 asteroidPointA;
	Vector2 asteroidPointB;
	Vector2 asteroidPointC;
	Vector2 asteroidPointD;

	Vector2 asteroid;
	Vector2 asteroidVelocity;

	Vector2 rotatedOffsetA;
	Vector2 rotatedOffsetB;
	Vector2 rotatedOffsetC;
	Vector2 rotatedOffsetD;

	Vector2 transformedEndPointA;
	Vector2 transformedEndPointB;
	Vector2 transformedEndPointC;
	Vector2 transformedEndPointD;

	Vector2 velocity;

	float speed;
	float rotationDegrees;
	float rotationSpeed;
	float rotationRadians;
	float asteroidRadius;

	bool isAlive;

	void Initialize();

	void Update(float dt);
	void Draw(SDL_Renderer * renderer, float dt);
	float CalcDistance(Vector2 v1, Vector2 v2);
	float CalcDistanceOffset(Vector2 v1);
};