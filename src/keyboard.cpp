#include "global.h"

void processNormalKeys(unsigned char key, int xx, int yy) {   
  if (key == 27 && inGame == 4){
    inGame = 1;
  }
  if (key == 27 && inGame == 2){
    if(!pauseGame)
      inGame = 0;
    else 
      inGame = 1;
  }
  if (key == 27 && inGame == 3){
    if(!pauseGame)
      inGame = 0;
    else 
      inGame = 1;
  }

  if((key==27 && gameover == 1) || (key==27 && gamefinish==1)) 
  {
    initializeSound();
    flagsound = 1;
    fuel = 100;
    collision = 0;
    memset(moveBodyParts,0,sizeof(moveBodyParts));
    deltaTiltPlane = 0;
     inGame = 0; menuNum = 1;
     gameover = 0;
     gamefinish = 0;
     overallTilt = 0;
     angle = 0.0f;                // angle of rotation for the camera direction
      lx = 0.0f; lz = 0.0f;           // actual vector representing the camera's direction
        rx = 0.0f; rz= -1.0f;
      x = 0.0f; z = 0.0f; y = 0.0f;           // xyz position of the car
        X = 0.0f; Z = 0.0f;                 // XZ position of the camera
        rotatePlane = 180.0f;
      deltaRotate = 0.0f;           // the key states. These variables will be zero when no key is being presses
      deltaMove = 0;
      deltaY = 0;
      score = 0;
      gunOn = 0;
      cars_position.clear();
      parachute_position.clear();
  }
  if (key == 13 && inGame < 4){
    mainMenuCall();
  }
  if (key == ' ') {
    deltaY = 15.0f;
  }
  if(key == 'g'){
    //close();
    gunOn = 1;
    
    initializegunSound();
  }
  if(key=='k'){
   
int win_w = 800;
    int win_h = 450;
    BYTE* pixels = new BYTE[ 3 * win_w * win_h];
    glReadPixels(0, 0, win_w, win_h, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    // Convert to FreeImage format & save to file
    FIBITMAP* image = FreeImage_ConvertFromRawBits(pixels, win_w, win_h, 3 * win_w, 24, 0x0000FF, 0xFF0000, 0x00FF00, false);
    FreeImage_Save(FIF_BMP, image, "../test.bmp", 0);

    // Free resources
    FreeImage_Unload(image);
    delete [] pixels;

    
  }
} 

void releaseKeyboardKey(unsigned char key, int x, int y)
{
  if(inGame){
    switch (key) {
      case ' ' : deltaY = -10.0f; break;
      case 'g' : {gunOn = 0;initializeSound();}
    }
  }
}

void pressKey(int key, int xx, int yy) {
  if(inGame < 4){
    switch (key) {
      case GLUT_KEY_UP    : if(menuNum==1){menuNum=1;}else{menuNum--;} break;
      case GLUT_KEY_DOWN  : if(menuNum==3){menuNum=3;}else{menuNum++;} break;
      case GLUT_KEY_LEFT  : if(menuNum==1){menuNum=1;}else{menuNum--;} break;
      case GLUT_KEY_RIGHT : if(menuNum==3){menuNum=3;}else{menuNum++;} break;
    }
  }else{
    switch (key) {
      case GLUT_KEY_UP    : deltaMove = 15.0f; break;
      case GLUT_KEY_DOWN  : deltaMove = -15.0f; break;
      case GLUT_KEY_LEFT  : { deltaTiltPlane = -2.0; deltaRotate = 2.0f; break; }
      case GLUT_KEY_RIGHT : { deltaTiltPlane = 2.0; deltaRotate = -2.0f; break; }
    }
  }
  switch(key)
  {
    case GLUT_KEY_F10   : if( Mix_PausedMusic() == 1 )
                              Mix_ResumeMusic();
                            else
                              Mix_PauseMusic();
                            break;
  }
} 

void releaseKey(int key, int x, int y) {
  if(inGame){
    switch (key) {
      case GLUT_KEY_UP : deltaMove = 0;break;
      case GLUT_KEY_DOWN :  deltaMove = 0;break ;
      case GLUT_KEY_LEFT : 
                        {
                          deltaTiltPlane = 0;
                          deltaRotate = 0;break;
                        }
      case GLUT_KEY_RIGHT :
                      {
                        deltaTiltPlane = 0;
                        deltaRotate = 0;break;
                      }
    }
  }
}