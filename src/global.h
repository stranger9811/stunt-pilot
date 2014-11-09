#ifndef _GLOBAL_H_
#define _GLOBAL_H_

# include <stdio.h>
# include <stdlib.h>
#include <time.h>
# include <cmath>
# include <string.h>
#include  <vector>
#include <utility>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
# include "SDL.h"
#include <GLUT/glut.h>
#else
# include <GL/gl.h>
# include "SDL/SDL.h"
# include <GL/glu.h>
# include <GL/glut.h>
#endif



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

struct gun {
	float gx;
	float gy;
	float gz;
	float px;
	float py;
	float pz;
	int glife;
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
extern int road, sky,sand, mainMenu,gameOver,gameFinish,blank,footpath,finishline;
extern int arrow,level_1, level_2, settings_game,play_game,exit_game;
extern int pauseMenu, settingsMenu, world1Snap, world2Snap, powerUp;
extern int greenBar,redBar,blankBar, soundOn, soundOff, title, downArrow, powerFire, powerAir;
extern int worldNum, inGame;
extern int gameover,gamefinish;
extern int gunOn, collision;
extern float fuel;
extern int number_texture[10];

extern float deltaTiltPlane, overallTilt;

extern int moveBodyParts[4][3];

extern int score;
extern int flagsound;

extern std::vector < COORDINATE > cars_position;
extern std::vector < struct parachute > parachute_position;
extern std::vector < struct gun > gpos;

extern objloader plane,tree,parachute,tractor,car,rock,building,railing;
extern objloader lower,upper, middleBody, tyre, bullet;

extern int PLANE, TREE, PARACHUTE, TRACTOR, CAR, ROCK,BUILDING,SOLDIER,RAILING;
extern int MIDDLEBODY,LOWER,UPPER, TYRE, BULLET;
#endif