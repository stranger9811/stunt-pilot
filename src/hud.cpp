#include "global.h"
 
void renderHUD()
{
  orthoSet();
    glBindTexture(GL_TEXTURE_2D, healthBar);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(10,300);
      glTexCoord2f(1,0);  glVertex2f(30,300);
      glTexCoord2f(1,1);  glVertex2f(30,435);
      glTexCoord2f(0,1);  glVertex2f(10,435);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, powerFire);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(730,355);
      glTexCoord2f(1,0);  glVertex2f(780,355);
      glTexCoord2f(1,1);  glVertex2f(780,385);
      glTexCoord2f(0,1);  glVertex2f(730,385);
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

