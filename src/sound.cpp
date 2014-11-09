#include "global.h"

Mix_Music *gMusic = NULL;
Mix_Music *gunMusic = NULL;
Mix_Music *explosionMusic = NULL;

bool init(){
  //Initialization flag
  bool success = true;

  //Initialize SDL
  if( SDL_Init(SDL_INIT_VIDEO |SDL_INIT_AUDIO) < 0 ){
    printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    success = false;
  }
  if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ){
    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    success = false;
  }
  return success;
}

bool loadMedia(){
  //Loading success flag
  bool success = true;
  gMusic = Mix_LoadMUS( "../data/sound/sound1.wav" );
  if( gMusic == NULL ){
    printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
    success = false;
  }
  return success;
}

void close(){
  Mix_FreeMusic( gMusic );
  gMusic = NULL;
  Mix_Quit();
  SDL_Quit();
}

void initializeSound(){
  if( !init() ){
    printf( "Failed to initialize!\n" );
  }
  else{
    if( !loadMedia() ){
      printf( "Failed to load media!\n" );
    }
    else{ 
      Mix_PlayMusic( gMusic, -1 );
    }
  }
}


bool loadGunMedia(){
  //Loading success flag
  bool success = true;
  gunMusic = Mix_LoadMUS( "../data/sound/gunsound.wav" );
  if( gunMusic == NULL ){
    printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
    success = false;
  }
  return success;
}

bool loadCrashMedia(){
  //Loading success flag
  bool success = true;
  explosionMusic = Mix_LoadMUS( "../data/sound/explosion.wav" );
  if( explosionMusic == NULL ){
    printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
    success = false;
  }
  return success;
}

void closegunSound(){
  Mix_FreeMusic( gunMusic );
  gunMusic = NULL;
  Mix_Quit();
  SDL_Quit();
}


void closeexplosionSound(){
  Mix_FreeMusic( explosionMusic );
  explosionMusic = NULL;
  Mix_Quit();
  SDL_Quit();  
}

void initializegunSound(){
  if( !init() ){
    printf( "Failed to initialize!\n" );
  }
  else{
    if( !loadGunMedia() ){
      printf( "Failed to load media!\n" );
    }
    else{ 
      Mix_PlayMusic( gunMusic, -1 );
    }
  }
}

void initializecrashSound(){
  if( !init() ){
    printf( "Failed to initialize!\n" );
  }
  else{
    if( !loadCrashMedia() ){
      printf( "Failed to load media!\n" );
    }
    else{ 
      Mix_PlayMusic( explosionMusic, -1 );
    }
  }
}

