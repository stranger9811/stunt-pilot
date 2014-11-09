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

    glColor3f(1.0, 1.0, 1.0);
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, road);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
      glBegin(GL_QUADS);
          glTexCoord2f(0,0);  glVertex3f(-400.0f,0.0f,-10000.0f);
          glTexCoord2f(1,0);  glVertex3f(400.0f,0.0f,-10000.0f);
          glTexCoord2f(1,1);  glVertex3f(400.0f,0.0f,1000.0f);
          glTexCoord2f(0,1);  glVertex3f(-400.0f,0.0f,1000.0f);
      glEnd();

   glDisable(GL_TEXTURE_2D);

      glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, sky);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
      glBegin(GL_QUADS);
          glTexCoord2f(0,0);  glVertex3f(-40000.0f,3000.0f,-10000.0f);
          glTexCoord2f(1,0);  glVertex3f(40000.0f,3000.0f,-10000.0f);
          glTexCoord2f(1,1);  glVertex3f(40000.0f,3000.0f,10000.0f);
          glTexCoord2f(0,1);  glVertex3f(-40000.0f,3000.0f,10000.0f);
      glEnd();

   glDisable(GL_TEXTURE_2D);
   glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, sky);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      // float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
      // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
        glBegin(GL_QUADS);
            glTexCoord2f(0,0);  glVertex3f(-40000.0f,-10.0f,-10000.0f);
            glTexCoord2f(1,0);  glVertex3f(40000.0f,-10.0f,-10000.0f);
            glTexCoord2f(1,1);  glVertex3f(40000.0f,-10.0f,10000.0f);
            glTexCoord2f(0,1);  glVertex3f(-40000.0f,-10.0f,10000.0f);
        glEnd();
      glDisable(GL_TEXTURE_2D);

   glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, sky);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
      glBegin(GL_QUADS);
          glTexCoord2f(0,0);  glVertex3f(-40000.0f,3500.0f,-8000.0f);
          glTexCoord2f(1,0);  glVertex3f(40000.0f,3500.0f,-8000.0f);
          glTexCoord2f(1,1);  glVertex3f(40000.0f,0.0f,-8000.0f);
          glTexCoord2f(0,1);  glVertex3f(-40000.0f,0.0f,-8000.0f);
      glEnd();

   glDisable(GL_TEXTURE_2D);
   
    glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, sand);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      // float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
      // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
        glBegin(GL_QUADS);
            glTexCoord2f(0,0);  glVertex3f(300.0f,-5.0f,-10000.0f);
            glTexCoord2f(100,0);  glVertex3f(1800.0f,-5.0f,-10000.0f);
            glTexCoord2f(100,100);  glVertex3f(1800.0f,-5.0f,10000.0f);
            glTexCoord2f(0,100);  glVertex3f(300.0f,-5.0f,10000.0f);
        glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, footpath);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      // float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
      // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
        glBegin(GL_QUADS);
            glTexCoord2f(0,0);  glVertex3f(-2000.0f,5.0f,10000.0f);
            glTexCoord2f(30,0);  glVertex3f(-2000.0f,5.0f,-10000.0f);
            glTexCoord2f(30,30);  glVertex3f(-350.0f,5.0f,10000.0f);
            glTexCoord2f(0,30);  glVertex3f(-350.0f,5.0f,-10000.0f);
        glEnd();
    glDisable(GL_TEXTURE_2D);

   glEnable(GL_TEXTURE_2D);

   // right sky
    glBindTexture(GL_TEXTURE_2D, sky);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
      glBegin(GL_QUADS);
          glTexCoord2f(0,0);  glVertex3f(5000.0f,0.0f,-12000.0f);
          glTexCoord2f(1,0);  glVertex3f(5000.0f,0.0f,10000.0f);
          glTexCoord2f(1,1);  glVertex3f(5000.0f,3500.0f,10000.0f);
          glTexCoord2f(0,1);  glVertex3f(5000.0f,3500.0f,-12000.0f);
      glEnd();

   glDisable(GL_TEXTURE_2D);

    
  orthoSet();
  glEnable(GL_TEXTURE_2D);
    renderNumber(695,5,score);
    
    // glBindTexture(GL_TEXTURE_2D, blank);
    // glBegin(GL_QUADS);
    //   glTexCoord2f(0,0);  glVertex2f(750,0);
    //   glTexCoord2f(1,0);  glVertex2f(800,0);
    //   glTexCoord2f(1,1);  glVertex2f(800,50);
    //   glTexCoord2f(0,1);  glVertex2f(750,50);
    // glEnd();

    // glBindTexture(GL_TEXTURE_2D, healthBar);
    // glBegin(GL_QUADS);
    //   glTexCoord2f(0,0);  glVertex2f(300,5 );
    //   glTexCoord2f(1,0);  glVertex2f(435-(100-fuel)*1.35,5 );
    //   glTexCoord2f(1,1);  glVertex2f(435-(100-fuel)*1.35,20);
    //   glTexCoord2f(0,1);  glVertex2f(300,20);
    // glEnd();
    glBindTexture(GL_TEXTURE_2D, blankBar);
      glBegin(GL_QUADS);
        glTexCoord2f(0,0);  glVertex2f(20,30);
        glTexCoord2f(1,0);  glVertex2f(170,30);
        glTexCoord2f(1,1);  glVertex2f(170,10);
        glTexCoord2f(0,1);  glVertex2f(20,10);
      glEnd();
    if(fuel > 50)
    {
      glBindTexture(GL_TEXTURE_2D, greenBar);
      glBegin(GL_QUADS);
        glTexCoord2f(0,0);  glVertex2f(20, 30 );
        glTexCoord2f(1,0);  glVertex2f(170- (100 - fuel)*1.5,30  );
        glTexCoord2f(1,1);  glVertex2f(170- (100 - fuel)*1.5,10);
        glTexCoord2f(0,1);  glVertex2f(20,10);
      glEnd();
    }
    else if(fuel<=50)
    {
      glBindTexture(GL_TEXTURE_2D, redBar);
      glBegin(GL_QUADS);
        glTexCoord2f(0,0);  glVertex2f(20, 30);
        glTexCoord2f(1,0);  glVertex2f(170 - (100 - fuel)*1.5, 30);
        glTexCoord2f(1,1);  glVertex2f(170 - (100 - fuel)*1.5, 10);
        glTexCoord2f(0,1);  glVertex2f(20,10);
      glEnd(); 
    }
    // glBindTexture(GL_TEXTURE_2D, blankBar);
    //   glBegin(GL_QUADS);
    //     glTexCoord2f(0,0);  glVertex2f(10,300);
    //     glTexCoord2f(1,0);  glVertex2f(30,300);
    //     glTexCoord2f(1,1);  glVertex2f(30,435);
    //     glTexCoord2f(0,1);  glVertex2f(10,435);
    //   glEnd();
    // if(fuel > 50)
    // {
    //   glBindTexture(GL_TEXTURE_2D, greenBar);
    //   glBegin(GL_QUADS);
    //     glTexCoord2f(0,0);  glVertex2f(10,300 + (100 - fuel)*1.35 );
    //     glTexCoord2f(1,0);  glVertex2f(30,300 + (100 - fuel)*1.35 );
    //     glTexCoord2f(1,1);  glVertex2f(30,435);
    //     glTexCoord2f(0,1);  glVertex2f(10,435);
    //   glEnd();
    // }
    // else if(fuel<=50)
    // {
    //   glBindTexture(GL_TEXTURE_2D, redBar);
    //   glBegin(GL_QUADS);
    //     glTexCoord2f(0,0);  glVertex2f(10,300 + (100 - fuel)*1.35 );
    //     glTexCoord2f(1,0);  glVertex2f(30,300 + (100 - fuel)*1.35 );
    //     glTexCoord2f(1,1);  glVertex2f(30,435);
    //     glTexCoord2f(0,1);  glVertex2f(10,435);
    //   glEnd(); 
    // }
    
glDisable(GL_TEXTURE_2D);
  orthoReset();
}

