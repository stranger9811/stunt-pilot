#include "global.h"

char filename[100];

void initializeWorld(){

	
    strcpy(filename , "../data/world1/Tree.obj");
    TREE = tree.load(filename);
    strcpy(filename , "rock_02.obj");
    ROCK = rock.load(filename);
    strcpy(filename , "building.obj");
    BUILDING = building.load(filename);
    strcpy(filename , "beautiful_girl.obj");
    SOLDIER = building.load(filename);
    strcpy(filename , "../data/characters/tractor.obj");
    TRACTOR = tractor.load(filename);


	if(worldNum == 1){
		strcpy(filename , "fluzeug.obj");
    	PLANE = plane.load(filename);	
	}
	
}

void drawWorld(){
	if(worldNum == 1){
		glPushMatrix();								// CHARACTERS
			glTranslatef(x,y,z);
			glRotatef(90, 0.0, 1.0, 0.0);
			glRotatef(rotatePlane+deltaRotate, 0.0, 1.0, 0.0);
			glScalef(40,47,40);
			glCallList(PLANE);
		glPopMatrix();

		glPushMatrix();								// CHARACTERS
			glTranslatef(-1500.0f,0.0f,-2000.0f);
			glRotatef(270.0, 0.0, 0.0, 0.0);
			glScalef(20,20,20);
			glCallList(SOLDIER);
		glPopMatrix();


		glPushMatrix();								// CHARACTERS
			glTranslatef(-900.0f,0.0f,-2000.0f);
			glRotatef(250.0, 0.0, 1.0, 0.0);
			glScalef(20,20,20);
			glCallList(SOLDIER);
		glPopMatrix();


		glPushMatrix();								// CHARACTERS
			glTranslatef(-200.0f,0.0f,-3000.0f);
			glRotatef(210.0, 0.0, 1.0, 0.0);
			glScalef(5,5,5);
			glCallList(ROCK);
		glPopMatrix();
		 
		glPushMatrix();								// CHARACTERS
			glTranslatef(-1500.0f,0.0f,-3000.0f);
			glRotatef(270.0, 1.0, 0.0, 0.0);
			glRotatef(-90.0, 0.0, 0.0, 1.0);
			glScalef(5,5,5);
			glCallList(BUILDING);
		glPopMatrix();
		
		glBindTexture(GL_TEXTURE_2D, road);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
    	glBegin(GL_QUADS);
      		glTexCoord2f(0,0);  glVertex3f(-400.0f,0.0f,-10000.0f);
      		glTexCoord2f(1,0);  glVertex3f(400.0f,0.0f,-10000.0f);
      		glTexCoord2f(1,1);  glVertex3f(400.0f,0.0f,1000.0f);
      		glTexCoord2f(0,1);  glVertex3f(-400.0f,0.0f,1000.0f);
    	glEnd();
   
 
		glPushMatrix();								// CHARACTERS
			glTranslatef(0.0f,50.0f,-800.0f);
			glRotatef(210.0, 0.0, 1.0, 0.0);
			glScalef(30,30,30);
			glCallList(TRACTOR);
		glPopMatrix();	
	}
	
	renderHUD();
}