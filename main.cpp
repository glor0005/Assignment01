#include <iostream>
#include "Game.h"

/*
	Name: Juan Marco Gloriani
	Class: CST8237 - Game Programming
*/
using namespace std;

int main(int argc, char** argv)
{
  GameEngine *engine = GameEngine::CreateInstance();
  engine->Initialize();

  while(true)
  {
    engine->Update();
    engine->Draw();
  }

  engine->Shutdown();

  return 0;
}