#include "global.h"

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
int level_1, level_2,road, sky, menuNum,gameOver,mainMenu, pauseMenu, arrow, settings_game,play_game,exit_game, settingsMenu, world1Snap, world2Snap, powerUp,blank,healthBar, soundOn, soundOff, title, downArrow, powerFire, powerAir;

int gameover = 0;
int number_texture[10];
int gunOn = 0;
int score;

objloader plane, tree, tractor,rock,building,parachute;
objloader sideleft,sideright,sideback,sidefront;
objloader shed, base, wall, flooor;
objloader world2;

vector < COORDINATE > cars_position;
vector < struct parachute > parachute_position;

int PLANE, TREE, TRACTOR,ROCK,BUILDING,SOLDIER, PARACHUTE;
int SIDELEFT,SIDERIGHT,SIDEBACK,SIDEFRONT;
int SHED,WALL,BASE,FLOOR;
int WORLD2;
int flag = 0;

void renderScene(void){
	if(gameover == 1) 
	{
		renderGameOver();
	}
  	else if(inGame < 4){
  	glDisable(GL_LIGHTING);
    	renderMenu();
    glEnable(GL_LIGHTING);
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
    y += -3.0;
	if(y<0)
		y = 0.0;
	
	if(gunOn == 1) {
		destroyParachute();
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

  
  inGame = 0; menuNum = 1;

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
	//XXXX initializeSound();

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
