#include "Player.h"
#include <SDL.h>
#include <math.h>
#include "InputManager.h"


Player::Player() : GameObject()
{
  _transform.position = { 400.0f, 400.0f, 0.0f };
}

Player::~Player()
{
}

void Player::Initialize()
{

	shipMid = { 320, 320 };

	pointOne = { 0, -10};
	pointTwo = { -5, 5};
	pointThree = { 5, 5};

	rotationDegrees = 25.0f;
	rotationSpeed = 300.0f;

	fireKeyDown = false;

	velocity = { 0.0f, 0.0f };

	//ship = {200, 250, 100, 100};
}

void Player::Update(float dt)
{

	InputManager *im = InputManager::GetInstance();
	
	im->Update(dt);

	// Check for user input.
	if (im->IsKeyDown(SDLK_UP) == true) // Thrust forward
	{
		velocity.x -= (sinf(rotationRadians)*dt*XLR8);
		velocity.y += (cosf(rotationRadians)*dt*XLR8);
	}
	if (im->IsKeyDown(SDLK_DOWN) == true) // Thrust backward
	{
		velocity.x += (sinf(rotationRadians)*dt*XLR8);
		velocity.y -= (cosf(rotationRadians)*dt*XLR8);
	}
	if (im->IsKeyDown(SDLK_LEFT) == true) // Rotate 
	{
		rotationDegrees -= (rotationSpeed * dt);
	}
	if (im->IsKeyDown(SDLK_RIGHT) == true) // Rotate
	{
		rotationDegrees += (rotationSpeed * dt);
	}
	if (im->IsKeyDown(SDLK_SPACE) == true) // Shoot Missile
	{
		if (!fireKeyDown)
		{
			for (int i = 0; i < 10; i++)
			{
				if (missile[i].missileFired == false)
				{
					missile[i].missileFired = true;
					missile[i].SetTransform(_transform);
					missile[i].Initialize();
					printf("Missile Shot.\n");
					break;
				}
			}
			fireKeyDown = true;
		}
	}
	if (im->IsKeyDown(SDLK_SPACE) == false) // Missle is not being shot
	{
		fireKeyDown = false;
	}

	// Boundries
	if (shipMid.y > 645)
	{
		shipMid.y = 0;
	}
	else if (shipMid.y < 0)
	{
		shipMid.y = 640;
	}
	else if (shipMid.x > 645)
	{
		shipMid.x = 0;
	}
	else if (shipMid.x < 0)
	{
		shipMid.x = 640;
	}

	// Update Ship
	shipMid.x += velocity.x * dt * XLR8;
	shipMid.y += velocity.y * dt * XLR8;

	// Update Missiles
	for (int i = 0; i < 10; i++)
	{
		if (missile[i].missileFired) {
			missile[i].Update(dt);
		}
	}
}

void Player::Draw(SDL_Renderer *renderer, float dt)
{
	rotationDegrees += (rotationDegrees >= 360.0f ? -360.0f : 0);

	rotationRadians = MathUtils::ToRadians(rotationDegrees);

	rotatedOffsetA =
	{
		pointOne.x * cosf(rotationRadians) + pointOne.y * sinf(rotationRadians),
		pointOne.x * sinf(rotationRadians) - pointOne.y * cosf(rotationRadians)
	};

	rotatedOffsetB =
	{
		pointTwo.x * cosf(rotationRadians) + pointTwo.y * sinf(rotationRadians),
		pointTwo.x * sinf(rotationRadians) - pointTwo.y * cosf(rotationRadians)
	};

	rotatedOffsetC =
	{
		pointThree.x * cosf(rotationRadians) + pointThree.y * sinf(rotationRadians),
		pointThree.x * sinf(rotationRadians) - pointThree.y * cosf(rotationRadians)
	};

	transformedEndPointA = { shipMid.x + rotatedOffsetA.x, shipMid.y + rotatedOffsetA.y };
	transformedEndPointB = { shipMid.x + rotatedOffsetB.x, shipMid.y + rotatedOffsetB.y };
	transformedEndPointC = { shipMid.x + rotatedOffsetC.x, shipMid.y + rotatedOffsetC.y };

	SDL_RenderDrawLine(renderer, transformedEndPointA.x, transformedEndPointA.y, transformedEndPointB.x, transformedEndPointB.y);
	SDL_RenderDrawLine(renderer, transformedEndPointB.x, transformedEndPointB.y, transformedEndPointC.x, transformedEndPointC.y);
	SDL_RenderDrawLine(renderer, transformedEndPointC.x, transformedEndPointC.y, transformedEndPointA.x, transformedEndPointA.y);

	//Draw Missiles
	for (int i = 0; i < 10; i++)
	{
		if (missile[i].missileFired) {
			missile[i].Draw(renderer, dt);
		}
	}

}