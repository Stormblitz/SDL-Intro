#include "engine.h"

int main() 
{ 
  GameEngine* engine = new GameEngine();
  
  int startTime = 0;
  int currentDuration = 0;
  int frameDuration = 0;

  while(engine->GetCurrentGameState == RUNNING){
    
    startTime = SDL_GetTicks(); //Milliseconds since start of game

    engine->HandleEvents();
    engine->UpdateMechanics();
    engine->Render();

    currentDuration = SDL_GetTicks() - startTime;
    if (currentDuration < frameDuration){
      SDL_Delay(frameDuration - currentDuration);
    }
  }

  delete engine;
  
  return 0; 
}
