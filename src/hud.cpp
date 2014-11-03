#include "global.h"

void renderNumber(int x,int y,int value) 
{
    int len=0;
    int temp = value;
    while(temp!=0) {
      temp = temp/10;
      len++;
    }
    while(value!=0) {
      temp = value%10;
      glBindTexture(GL_TEXTURE_2D, number_texture[temp]);
      glBegin(GL_QUADS);
        glTexCoord2f(0,0);  glVertex2f(x + len*20,y);
        glTexCoord2f(1,0);  glVertex2f(x + len*20 + 20,y);
        glTexCoord2f(1,1);  glVertex2f(x + len*20 + 20,y + 40);
        glTexCoord2f(0,1);  glVertex2f(x + len*20, y+40);
      glEnd();
      len--;
      value = value/10;
    }
}
 
void renderHUD()
{
    
  orthoSet();
    renderNumber(695,5,score);
    
    // glBindTexture(GL_TEXTURE_2D, blank);
    // glBegin(GL_QUADS);
    //   glTexCoord2f(0,0);  glVertex2f(750,0);
    //   glTexCoord2f(1,0);  glVertex2f(800,0);
    //   glTexCoord2f(1,1);  glVertex2f(800,50);
    //   glTexCoord2f(0,1);  glVertex2f(750,50);
    // glEnd();

    glBindTexture(GL_TEXTURE_2D, healthBar);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(10,300);
      glTexCoord2f(1,0);  glVertex2f(30,300);
      glTexCoord2f(1,1);  glVertex2f(30,435);
      glTexCoord2f(0,1);  glVertex2f(10,435);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, powerAir);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(740,305);
      glTexCoord2f(1,0);  glVertex2f(780,305);
      glTexCoord2f(1,1);  glVertex2f(780,335);
      glTexCoord2f(0,1);  glVertex2f(740,335);
    glEnd();

  orthoReset();
}

