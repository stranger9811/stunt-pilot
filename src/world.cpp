#include "global.h"

#define PI 3.14159265

char filename[100];

void initializeWorld(){

	cars_position.clear();	
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
    strcpy(filename,"../data/characters/tractor.obj");
    PARACHUTE = parachute.load(filename);

	if(worldNum == 1){
		strcpy(filename , "fluzeug.obj");
    	PLANE = plane.load(filename);	
	}
	
}

float get_x_coordinate(int x) {
	if(x==0) {
		return -300.0f;
	}
	if(x==1)
		return -100.0f;
	if(x==2)
		return 100.0f;
	if(x==3)
		return 300.0f;

}

float get_angle(int x) {
	if(x==0 || x == 1) {
		return 270.0f;
	}
	else 
		return 90.0f;
}

void moveCars() {
	for(int i=0; i<cars_position.size(); i++) {
		if(pow(pow((get_x_coordinate(cars_position[i].first) - x),2) + 
			pow(cars_position[i].second - z,2),0.5) < 50)
			gameover = 1;

		if(cars_position[i].second > z || cars_position[i].second < z - 5000) {
			cars_position.erase(cars_position.begin()+i);
			printf("remove car at (%d,%d)",cars_position[i].first,cars_position[i].second);
			continue;
		}
		if(cars_position[i].first == 0 || cars_position[i].first == 1) 
			cars_position[i].second += 15.0;
		else
			cars_position[i].second  -= 15.0;
	}
}

void addNewCars() {
	while(cars_position.size() < 20)  {
		int x_coord = rand()%4;
		int  z_coord = z - rand()%5000;
		int flag = 1;
		if(pow( pow(x - x_coord,2) + pow(z_coord - z,2),0.5) < 1500)
			continue;
		for(int i=0; i<cars_position.size(); i++) {
			if( abs(cars_position[i].second - z_coord) < 100)
				flag = 0;

		}
		if(flag == 1) {
			cars_position.push_back(make_pair(x_coord,z_coord));
			printf("New coordinate added (%d,%d)\n",x_coord,z_coord);
		}
	}
}

void moveParachute() {

	for(int i=0; i<parachute_position.size(); i++) {

		if(pow(pow(parachute_position[i].x_coordinate - x,2) + 
			pow(parachute_position[i].z_coordinate - z,2) + pow(parachute_position[i].y_coordinate - y,2) ,0.5) < 100)
			gameover = 1;

		if(parachute_position[i].z_coordinate > z) {
			parachute_position.erase(parachute_position.begin() + i);
			continue;
		}

		if(parachute_position[i].direction == 1){
			parachute_position[i].y_coordinate += 30.0f;
			if(parachute_position[i].y_coordinate > 1000)
				parachute_position[i].direction = 0;
		}
		else {
			parachute_position[i].y_coordinate -= 30.0f;
			if(parachute_position[i].y_coordinate < 400)
				parachute_position[i].direction = 1;
		}


	}
}

void destroyParachute() {
	vector <int> parachuteToBeDestroyed;
	int normdiff,normdiffla,sp,xdiff,ydiff,zdiff,xdiffla,ydiffla,zdiffla; 
	float angle;
	for(int i=0; i<parachute_position.size(); i++) {
		xdiff = parachute_position[i].x_coordinate - x;
		ydiff = parachute_position[i].y_coordinate - y;
		zdiff = parachute_position[i].z_coordinate - z;
		xdiffla = x + (float)sin(rotatePlane*pi/180)*10.0;
		ydiffla = y+100.0f;
		zdiffla = z + (float)cos(rotatePlane*pi/180)*10.0;
		sp = (xdiff*xdiffla) + (ydiff*ydiffla) + (zdiff*zdiffla);
		normdiff = pow(xdiff*xdiff + ydiff*ydiff + zdiff*zdiff, 0.5);
		normdiffla = pow(xdiffla*xdiffla + ydiffla*ydiffla + zdiffla*zdiffla, 0.5);
		sp = sp/(normdiff*normdiffla);
		angle = acos (sp) * 180.0 / PI;
		if(angle<60)
		{
			parachuteToBeDestroyed.push_back(i);
		}
	}
	int min_val=1000000;
	int index;
	for (int i=0;i<parachuteToBeDestroyed.size();i++)
	{
	
		if(parachute_position[i].z_coordinate < min_val)
		{
			index = i;
			min_val = parachute_position[i].z_coordinate;
		}	
	}

	if(parachuteToBeDestroyed.size()!=0)
		parachute_position.erase(parachute_position.begin()+index);
}

void addNewParachute() {
	while(parachute_position.size() < 10)  {
		int x_coord = rand()%1200 - 600;
		int y_coord =  400;
		int  z_coord = z - rand()%5000;
		int flag = 1;
		if(pow( pow(x - x_coord,2) + pow(z_coord - z,2) + pow(y_coord - y,2) ,0.5) < 1500)
			continue;
		for(int i=0; i<parachute_position.size(); i++) {
			if( abs(parachute_position[i].z_coordinate - z_coord) < 100)
				flag = 0;
		}

		if(flag == 1) {
			struct parachute temp;
			temp.x_coordinate = x_coord;
			temp.y_coordinate = y_coord;
			temp.z_coordinate = z_coord;
			temp.life = PARACHUTE_LIFE;
			temp.direction = 1;
			parachute_position.push_back(temp);
			printf("New parachute coordinate added ((%d,%d),%d)\n",x_coord,y_coord,z_coord);
		}
	}
}

void drawWorld(){
	srand (time(NULL));

	moveCars();
	addNewCars();
	moveParachute();
	addNewParachute();																																																																																																						

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
		
		
	
   		//drawRect(-400.0f,0.0f,-1000.0f,800.0f,10000.0f,1,road);
 		for(int i=0; i<cars_position.size(); i++) {
										// CHARACTERS
 				glPushMatrix();	
				glTranslatef(get_x_coordinate(cars_position[i].first),50.0f,float(cars_position[i].second));
				glRotatef(get_angle(cars_position[i].first), 0.0, 1.0, 0.0);
				glScalef(30,30,30);
				glCallList(TRACTOR);
				glPopMatrix();
		}
		for(int i=0; i<parachute_position.size(); i++) {
										// CHARACTERS
 				glPushMatrix();	
				glTranslatef(float(parachute_position[i].x_coordinate),
					float(parachute_position[i].y_coordinate),float(parachute_position[i].z_coordinate));
				glRotatef(270.0, 0.0, 0.0, 0.0);
				glScalef(30,30,30);
				glCallList(PARACHUTE);
				glPopMatrix();
		}
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
          glTexCoord2f(0,0);  glVertex3f(-400.0f,1300.0f,-10000.0f);
          glTexCoord2f(10,0);  glVertex3f(4000.0f,1300.0f,-10000.0f);
          glTexCoord2f(10,10);  glVertex3f(4000.0f,1300.0f,1000.0f);
          glTexCoord2f(0,10);  glVertex3f(-4000.0f,1300.0f,1000.0f);
      glEnd();

   glDisable(GL_TEXTURE_2D);
			
	glEnable(GL_LIGHTING);
	}
	score ++ ;
	renderHUD();
}