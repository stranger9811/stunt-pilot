#include "global.h"

void computePos(float deltaMove) {
  if(deltaMove>0){
    rotatePlane += deltaRotate;
  }else{
    rotatePlane -= deltaRotate;
  }
  x += deltaMove * sin(rotatePlane*pi/180);
  z += deltaMove * cos(rotatePlane*pi/180);
  y += deltaY;
  if(y<0)
    y = 0.0f;
  rx += deltaMove * sin(rotatePlane*pi/180);
  rz += deltaMove * cos(rotatePlane*pi/180);
}

void renderGame(void) {
  int i,j;
  if (deltaMove){
    computePos(deltaMove);
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);           // Clear Color and Depth Buffers
  glLoadIdentity();                                             // Reset transformations/*

  gluLookAt(  x - (float)sin(rotatePlane*pi/180)*250.0 , y+100.0f,  z - (float)cos(rotatePlane*pi/180)*250.0,    //Change the camera position
              x + (float)sin(rotatePlane*pi/180)*10.0 , y+100.0f,  z + (float)cos(rotatePlane*pi/180)*10.0,    //Change Lookat vector
             0.0f, 100.0f, 0.0f );                               //Change Up vector*/

  drawWorld();
} 

void renderGameOver(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0,0.0,0.0,1.0);
  orthoSet();
 glEnable(GL_TEXTURE_2D);
 
  glBindTexture(GL_TEXTURE_2D, gameOver);
  glBegin(GL_QUADS);
      glTexCoord2f(0, 0);  glVertex2f(0, 0);
      glTexCoord2f(0, 1);  glVertex2f(0, 450);
      glTexCoord2f(1, 1);  glVertex2f(800, 450);
      glTexCoord2f(1, 0);  glVertex2f(800, 0);
  glEnd();
  glDisable(GL_TEXTURE_2D);
   orthoReset();

}

void renderGameFinish(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0,0.0,0.0,1.0);
  orthoSet();
 glEnable(GL_TEXTURE_2D);
 
  glBindTexture(GL_TEXTURE_2D, gameOver);
  glBegin(GL_QUADS);
      glTexCoord2f(0, 0);  glVertex2f(0, 0);
      glTexCoord2f(0, 1);  glVertex2f(0, 450);
      glTexCoord2f(1, 1);  glVertex2f(800, 450);
      glTexCoord2f(1, 0);  glVertex2f(800, 0);
  glEnd();
  glDisable(GL_TEXTURE_2D);
   orthoReset();
}

void initialize (void){

    glShadeModel( GL_SMOOTH );
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );
    glClearDepth( 1.0f );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );


/// New light

   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);

// end new light

    // GLfloat amb_light[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    // GLfloat diffuse0[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    // GLfloat lightPos0[] = {1000.0f, 1000.0f, 1000.0f, 1.0 };
    // GLfloat specular[] = { 0.7, 0.7, 0.3, 1 };
    // glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb_light);
    // glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
    // glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    // glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    // glEnable(GL_LIGHT0);
    // glEnable(GL_COLOR_MATERIAL);
    // glShadeModel(GL_SMOOTH);
    // glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glDepthFunc(GL_LEQUAL);
    // glEnable(GL_DEPTH_TEST);
    // glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    mainMenu = loadTex("../data/images/mainMenu.bmp");
    pauseMenu = loadTex("../data/images/pauseMenu.bmp");
    powerUp = loadTex("../data/images/powerUp.bmp");
    greenBar = loadTex("../data/images/greenBar.bmp");
    redBar = loadTex("../data/images/redBar.bmp");
    blankBar = loadTex("../data/images/blankBar.bmp");
    soundOff = loadTex("../data/images/Sound_Off.bmp");
    soundOn = loadTex("../data/images/Sound_On.bmp");
    exit_game = loadTex("../data/images/Exit.bmp");
    play_game = loadTex("../data/images/Play.bmp");
    settings_game = loadTex("../data/images/Settings.bmp");
    level_1 = loadTex("../data/images/Level1.bmp");
    level_2 = loadTex("../data/images/Level2.bmp");
    powerAir = loadTex("../data/images/lives.bmp");
    road = loadTex("../data/images/runway.bmp");
    sky = loadTex("../data/images/Sky.bmp");
    gameOver = loadTex("../data/images/gameover.bmp");
    sand = loadTex("../data/images/sandy.bmp");
    footpath = loadTex("../data/images/footpath.bmp");
    finishline = loadTex("../data/images/finishline.bmp");
    number_texture[0] = loadTex("../data/numbers/0.bmp");
    number_texture[1] = loadTex("../data/numbers/1.bmp");
    number_texture[2] = loadTex("../data/numbers/2.bmp");
    number_texture[3] = loadTex("../data/numbers/3.bmp");
    number_texture[4] = loadTex("../data/numbers/4.bmp");
    number_texture[5] = loadTex("../data/numbers/5.bmp");
    number_texture[6] = loadTex("../data/numbers/6.bmp");
    number_texture[7] = loadTex("../data/numbers/7.bmp");
    number_texture[8] = loadTex("../data/numbers/8.bmp");
    number_texture[9] = loadTex("../data/numbers/9.bmp");
}

void changeSize(int w, int h) {
	// Prevent a divide by zero, when window is too short (you cant make a window of zero width).
	if (h == 0)
		h = 1;
    GLfloat aspect = (GLfloat) w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, aspect, 0.1f, 10000.0f);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
}