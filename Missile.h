#pragma once

#include "GameObject.h"

class Missile : public GameObject
{
public:
	Missile();
	~Missile();

	void Initialize();

	Vector2 missilePosition;
	Vector2 missileOffSet;
	bool missileFired = false;
	float missileLife;


	void Update(float dt);
	void Draw(SDL_Renderer *renderer, float dt);
	void Reform(Vector2* point);
	void Reform3(Vector3* point);

	Transform& GetTransform();
	void SetTransform(Transform transform);
};