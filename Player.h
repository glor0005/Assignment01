#pragma once

#include "GameObject.h"
#include "Missile.h"
#include <SDL.h>

#define XLR8 20.0
#define MAX_MISSILE 12


class Player : public GameObject
{
public:
  Player();
  ~Player();

  Missile missile[MAX_MISSILE];

  Vector2 pointOne;
  Vector2 pointTwo;
  Vector2 pointThree;

  Vector2 shipMid;

  Vector2 rotatedOffsetA;
  Vector2 rotatedOffsetB;
  Vector2 rotatedOffsetC;

  Vector2 transformedEndPointA;
  Vector2 transformedEndPointB;
  Vector2 transformedEndPointC;

  Vector2 velocity;

  float rotationDegrees;
  float rotationSpeed;
  float rotationRadians;

  float friction;

  bool fireKeyDown;

  //SDL_Rect ship;

  void Initialize();

  void Update(float dt);
  void Draw(SDL_Renderer *renderer, float dt);
};