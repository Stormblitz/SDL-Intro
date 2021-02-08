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

  RunCurrentGame();
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
    return (this->currentState < 0 || this->currentState > RUNNING) ? 
        INVALID : 
        this->currentState;
} 

void GameEngine::StopCurrentGame()
{
    currentState = STOPPED;
}

void GameEngine::PauseCurrentGame()
{
    currentState = PAUSED;
}

void GameEngine::RunCurrentGame()
{
    currentState = RUNNING;
}

void GameEngine::HandleEvents()
{
    //Possibility of handling multiple events by popping 
    SDL_Event gameEvent;
    SDL_PollEvent(&gameEvent);

    if (gameEvent.type == SDL_QUIT) {
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
    //SDL_Rect __ {x, y, w, h};

    SDL_Surface* windowsBliss = IMG_Load("./WindowsBliss.jpg");
    SDL_Texture* windowsBlissTexture = SDL_CreateTextureFromSurface(my_renderer, windowsBliss);
    SDL_Rect windowsBlissRect {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_FreeSurface(windowsBliss);

    SDL_Surface* watermarkMeme = IMG_Load("./UnregisteredHypercam2.png");
    SDL_Texture* watermarkMemeTexture = SDL_CreateTextureFromSurface(my_renderer, watermarkMeme);
    SDL_Rect watermarkMemeRect {0, 0, 150, 40};
    SDL_FreeSurface(watermarkMeme);

    SDL_Surface* droid = IMG_Load("./Droid.png");
    SDL_Texture* droidTexture = SDL_CreateTextureFromSurface(my_renderer, droid);
    SDL_Rect droidRect {20, SCREEN_HEIGHT - (99 + 32), 32, 32};
    SDL_FreeSurface(droid);

    SDL_RenderClear(my_renderer);

    SDL_SetRenderDrawColor(my_renderer, 61, 40, 51, 255);
    SDL_Rect platformRect {0, SCREEN_HEIGHT - 100, 300, 100};

    SDL_RenderCopy(my_renderer, windowsBlissTexture, NULL, &windowsBlissRect);
    SDL_RenderCopy(my_renderer, watermarkMemeTexture, NULL, &watermarkMemeRect);
    SDL_RenderFillRect(my_renderer, &platformRect);
    SDL_RenderCopy(my_renderer, droidTexture, NULL, &droidRect);
    
    SDL_RenderPresent(my_renderer);
}