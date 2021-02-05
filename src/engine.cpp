#include "engine.h"

GameEngine::GameEngine()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
  }

  //Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);
  
  my_window = SDL_CreateWindow("my_game", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       SCREEN_WIDTH,
			       SCREEN_HEIGHT, 0);

  my_renderer = SDL_CreateRenderer(my_window,-1,0);
}

GameEngine::~GameEngine()
{
  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
}

GAME_STATE_ENUM GameEngine::GetCurrentGameState()
{
    (this->currentState < 0 || this->currentState > GAME_STATE_ENUM.RUNNING) ? 
        return GAME_STATE_ENUM.INVALID : 
        return this->currentState;
} 

void GameEngine::StopCurrentGame()
{
    currentState = GAME_STATE_ENUM.STOPPED;
}

void GameEngine::PauseCurrentGame()
{
    currentState = GAME_STATE_ENUM.PAUSED;
}

void GameEngine::RunCurrentGame()
{
    currentState = GAME_STATE_ENUM.RUNNING;
}

void GameEngine::HandleEvents()
{
    //Possibility of handling multiple events by popping 
    SDL_Event gameEvent;
    SDL_PollEvent(&gameEvent);

    if (gameEvent.type == SQL_QUIT) {
        StopCurrentGame();
    }
    //if (gameEvent.type == SDL_KEYDOWN) {
    //  switch ( gameEvent.key.keysym.sym ) {}
    //      case SDLK_UP:
    //          break;
    //  }
    //}
}

void GameEngine::UpdateMechanics()
{
    //FunctionNotImplementedException
}

void GameEngine::Render()
{
    SDL_Surface* watermarkMeme = IMG_Load("./UnregisteredHypercam2.png");
    SDL_Texture* watermarkMemeTexture = SDL_CreateTextureFromSurface(my_renderer, watermark);

    SDL_FreeSurface(watermarkMeme);

    SDL_Rect rect {0, 0, 150, 40};
    //rect.x = 0;
    //rect.y = 0;
    //rect.w = 150;
    //rect.h = 40;

    SDL_RenderClear(my_renderer);
    SDL_RenderCopy(my_renderer, my_texture, NULL, &rect);
    SDL_RenderPresent(my_renderer);
}