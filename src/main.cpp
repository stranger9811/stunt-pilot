#include "global.h"
#include <stdio.h>
#include <stdlib.h>

float angle;			
float lx,lz, rx, rz;			
float x,y, z, X, Z;				
float rotatePlane;
float deltaRotate;
float deltaMove;
float deltaY;
int worldNum;
bool pauseGame;
int inGame = 0;
int one, two, four;
int level_1, level_2,road,sand,sky, menuNum,gameOver,gameFinish,mainMenu, pauseMenu;
int arrow, settings_game,play_game,exit_game, settingsMenu, world1Snap; 
int world2Snap, powerUp,blank,greenBar,redBar,blankBar, soundOn;
int soundOff, title, downArrow, powerFire, powerAir, footpath,finishline;

int gameover = 0;
int makeitcrash = 0;
int gamefinish = 0;
int number_texture[10];
int gunOn = 0;
int collision = 0;
int score = 0;
int flagsound = 1;
int flagfile = 1;
float fuel = 100;
float gunT = 1;
int hscore;

objloader plane,tree,tractor,car,rock,building,parachute,railing,man;
objloader sideleft,sideright,sideback,sidefront;
objloader shed, base, wall, flooor;
objloader world2;
objloader lower,upper, middleBody, tyre, bullet,barrel;

vector < COORDINATE > cars_position;
vector < struct parachute > parachute_position;
vector < struct gun > gpos;

int MAN,PLANE, TREE, TRACTOR, CAR, ROCK,BUILDING,SOLDIER, PARACHUTE,RAILING;
int SIDELEFT,SIDERIGHT,SIDEBACK,SIDEFRONT;
int MIDDLEBODY,LOWER,UPPER, TYRE, BULLET,BARREL;
int SHED,WALL,BASE,FLOOR;
int WORLD2;

int moveBodyParts[4][3];

float deltaTiltPlane = 0, overallTilt = 0;
int flag = 0;

void renderScene(void){
	if(gameover == 1) 
	{
		renderGameOver();
	}
	else if(gamefinish == 1)
	{
		renderGameFinish();
	}
  	else if(inGame < 4){
    	renderMenu();
  	}

  	else{
  		if(flag==0){
	 		initializeWorld();
	 		flag = 1;
	 	}
    	renderGame();
  	}
  	glutSwapBuffers();
}

void update(int value) {
    y += -5.0;
	if(y<0)
		y = 0.0;
	if(fuel > 0)
		fuel -= 1.0;
	if(gunOn == 1) {
		struct gun temp;
	    temp.gx = (float)sin(rotatePlane*pi/180)*260.0;
	    temp.gy = 0;
	    temp.gz = (float)cos(rotatePlane*pi/180)*260.0;
	    temp.px = x;
	    temp.py = y;
	    temp.pz = z;
	    temp.glife = 0;
	    gpos.push_back(temp);
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed
	
	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(125, update, 0);
}

int main(int argc, char **argv) {

	angle = 0.0f;						    // angle of rotation for the camera direction
	lx = 0.0f; lz = 0.0f;				  	// actual vector representing the camera's direction
  	rx = 0.0f; rz= -1.0f;
	x = 0.0f; z = 0.0f;	y = 0.0f;			    	// xyz position of the car
  	X = 0.0f; Z = 0.0f;           			// XZ position of the camera
  	rotatePlane = 180.0f;
	deltaRotate = 0.0f;						// the key states. These variables will be zero when no key is being presses
	deltaMove = 0;
	deltaY = 0;
	score = 0;
	memset(moveBodyParts,0,sizeof(moveBodyParts));
  
  	inGame = 0; menuNum = 1;
  	FILE *fp;
  	fp = fopen("highscore.txt","r");
  	fscanf(fp,"%d",&hscore);
  	fclose(fp);

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1920,1080);
	glutCreateWindow("Stunt Pilot");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);

	initialize();
	initializeSound();

	glutTimerFunc(125, update, 0); 
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutKeyboardUpFunc(releaseKeyboardKey);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

  // enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
