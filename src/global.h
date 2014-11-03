#ifndef _GLOBAL_H_
#define _GLOBAL_H_

# include <stdio.h>
# include <stdlib.h>
#include <time.h>
# include <math.h>
# include <string.h>
#include  <vector>
#include <utility>

# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
# include <SDL/SDL.h>
# include "SDL/SDL.h"
# include "SDL/SDL_mixer.h"
# include "SDL/SDL_image.h"

# include "main.h"
# include "game.h"
# include "objLoader.h"
# include "keyboard.h"
# include "world.h"
# include "sound.h"
# include "menu.h"
# include "ortho.h"
# include "hud.h"

using namespace std;

#define PARACHUTE_LIFE 10
#define COORDINATE pair<int,int>
#include <FreeImagePlus.h>

#define pi 3.14159265359

struct parachute {
	int x_coordinate;
	int y_coordinate;
	int z_coordinate;
	int direction;
	int life;
};
extern float angle;				// angle of rotation for the camera direction
extern float lx,lz,rx,rz;				// actual vector representing the camera's direction
extern float x, z, y, X, Z;		// XZ position of the car and camera
extern float rotatePlane;

// the key states. These variables will be zero when no key is being presses
extern float deltaMove;
extern float deltaY;
extern float deltaRotate;

// extern Model_OBJ obj;
extern bool pauseGame;
extern int menuNum;
extern int one, two, four;
extern int road, sky, mainMenu,gameOver,blank, arrow,level_1, level_2, settings_game,play_game,exit_game, pauseMenu, settingsMenu, world1Snap, world2Snap, powerUp, healthBar, soundOn, soundOff, title, downArrow, powerFire, powerAir;
extern int worldNum, inGame;
extern int gameover;
extern int gunOn;
extern int number_texture[10];

extern int score;

extern std::vector < COORDINATE > cars_position;
extern std::vector < struct parachute > parachute_position;

extern objloader plane, tree, parachute,tractor,rock,building;

extern int PLANE, TREE, PARACHUTE, TRACTOR,ROCK,BUILDING,SOLDIER;

#endif