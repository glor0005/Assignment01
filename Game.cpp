#include "Game.h"
#include <SDL.h>
#include <math.h>
#include <cstdlib>
#include <time.h> 
#include <iostream>

// Initializing our static member pointer.
GameEngine* GameEngine::_instance = nullptr;

GameEngine* GameEngine::CreateInstance()
{
  if (_instance == nullptr)
  {
    _instance = new Game();
  }
  return _instance;
}

Game::Game() : GameEngine()
{

}

void Game::InitializeImpl()
{

	srand(time(NULL));

	player.Initialize();

	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		asteroid[i].Initialize();
	}

	// Using the default member-wise initializer for our new struct.
	pos = { 100.0f, 100.0f };
	endPointOffset = { 10.0f, 0.0f };
	speed = 10.0f;
	rotationSpeed = 360.0f;
	lives = 3;
	score = 0;

	//Display information on window
	sprintf(buffer, "Juan Marco Gloriani's Asteroids \t - \t Lives: %i \t\t - \t\t Score: %i", lives, score);
	SDL_SetWindowTitle(_window, buffer);


}

void Game::UpdateImpl(float dt)
{
	player.Update(dt);
	
	for (int i = 0; i < MAX_ASTEROIDS; i++)
	{
		asteroid[i].Update(dt);
	}

}

void Game::DrawImpl(SDL_Renderer *renderer, float dt)
{
  // Set the draw colour for our point.
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

  // Draw the point.
  //SDL_RenderDrawPoint(renderer, posX, posY);

  //draws player
  player.Draw(renderer, dt);

  //draw asteroid
  for (int i = 0; i < MAX_ASTEROIDS; i++)
  {
	  asteroid[i].Draw(renderer, dt);
  }

  //SDL_RenderDrawLine(renderer, pos.x, pos.y, transformedEndPoint.x, transformedEndPoint.y);
}