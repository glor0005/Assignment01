#pragma once

#include "GameEngine.h"

#define MAX_ASTEROIDS 10
#define ASTEROID_POINT 100

class Game: public GameEngine
{
  friend class GameEngine;

protected:
  Game();

  void InitializeImpl();
  void UpdateImpl(float dt);
  void DrawImpl(SDL_Renderer *renderer, float dt);

  Player player;
  Asteroid asteroid[MAX_ASTEROIDS];


  // Using the default member-wise initializer for our new struct.
  Vector2 pos;
  Vector2 endPointOffset;

  int lives;
  int score;
  float speed;
  float rotationSpeed;

  char buffer[50];
};