// CS 4160 - starter code written by Victor Zordan

#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#include "engine.h"

SDL_Window* my_window = NULL;
SDL_Renderer* my_renderer = NULL;
SDL_Event input;

void my_SDL_init(){

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

int main() 
{ 
  GameEngine* engine = new GameEngine();
  
  my_SDL_init();
  
  SDL_Texture* my_texture = NULL;
  SDL_Surface* temp = IMG_Load("./UnregisteredHypercam2.png");

  my_texture = SDL_CreateTextureFromSurface(my_renderer, temp);

  SDL_FreeSurface(temp);

  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.w = 150;
  rect.h = 40;

  while(true){
    
    start_time = SDL_GetTicks(); //Milliseconds since start of game
    duration = SDL_GetTicks() - start_time;
    if (duration < frame_duration){
      SDL_Delay();
    }

    SDL_RenderClear(my_renderer);
    SDL_RenderCopy(my_renderer, my_texture, NULL, &rect);
    SDL_RenderPresent(my_renderer);

  }

  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
  
  return 0; 
}
