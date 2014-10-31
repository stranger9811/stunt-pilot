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
  if (key == 13 && inGame < 4){
    mainMenuCall();
  }
  if (key == ' ') {
    deltaY = 15.0f;
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
      case ' ' : deltaY = -15.0f; break;
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
      case GLUT_KEY_LEFT  : deltaRotate = 2.0f; break;
      case GLUT_KEY_RIGHT : deltaRotate = -2.0f; break;
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
      case GLUT_KEY_DOWN : deltaMove = 0;break;
      case GLUT_KEY_LEFT : deltaRotate = 0;break;
      case GLUT_KEY_RIGHT : deltaRotate = 0;break;
    }
  }
}