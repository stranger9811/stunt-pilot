#include "global.h"

#define PI 3.14159265

char filename[100];

void initializeWorld(){

	strcpy(filename,"../data/objects/railing/railing.obj");
    RAILING = railing.load(filename);

	if(worldNum == 1){

		strcpy(filename , "../data/objects/plane/plane.obj");
    	PLANE = plane.load(filename);
    	// strcpy(filename , "../data/objects/man/man.obj");
    	// MAN = man.load(filename);
    	strcpy(filename , "../data/objects/planeParts/upper.obj");
    	UPPER = upper.load(filename);
    	strcpy(filename , "../data/objects/planeParts/lower.obj");
    	LOWER = lower.load(filename);
    	strcpy(filename , "../data/objects/planeParts/tyre.obj");
    	TYRE = tyre.load(filename);
    	strcpy(filename , "../data/objects/planeParts/middleBody.obj");
    	MIDDLEBODY = middleBody.load(filename);	
    	strcpy(filename , "../data/objects/planeParts/tyre.obj");
    	BULLET = bullet.load(filename);
    	strcpy(filename , "../data/objects/barrel/barrel.obj");
    	BARREL = barrel.load(filename);
	}

	cars_position.clear();	
    strcpy(filename , "../data/world1/Tree.obj");
    TREE = tree.load(filename);
    strcpy(filename , "../data/objects/rock/rock_02.obj");
    ROCK = rock.load(filename);
    strcpy(filename , "../data/objects/building/building.obj");
    BUILDING = building.load(filename);
    strcpy(filename , "../data/objects/car/car.obj");
    CAR = car.load(filename);
    strcpy(filename,"../data/objects/parachute/parachute.obj");
    PARACHUTE = parachute.load(filename);
    
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
		
		if( ( abs(x -get_x_coordinate(cars_position[i].first)) < 200.0 )  && (y < 100.0) && abs((z - cars_position[i].second) < 150.0 ) )
		{	
			collision = 1;
			deltaMove = 0.0f;
		}	
		if(cars_position[i].second > z || cars_position[i].second < z - 5000) {
			cars_position.erase(cars_position.begin()+i);
			continue;
		}
		if(cars_position[i].first == 0 || cars_position[i].first == 2) 
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
		}
	}
}

void moveParachute() {

	for(int i=0; i<parachute_position.size(); i++) {

		if(parachute_position[i].z_coordinate > z) {
			parachute_position.erase(parachute_position.begin() + i);
			continue;
		}

		parachute_position[i].y_coordinate -= 30.0f;
		if(parachute_position[i].y_coordinate <= 100)
			parachute_position.erase(parachute_position.begin() + i);
	}
}

void checkCollision() {
	if(collision !=0)
		return;
	if(x < -900) {
		collision = 1;
		return;
	}
	for(int i=0; i>=-5000; i -= 800 ) {
		if( ( abs(x - (-700)) < 200.0 )  && (y < 100.0) && abs((z - i) < 150.0 ) )
			collision = 1;
		if( ( abs(x - (700)) < 200.0 )  && (y < 100.0) && abs((z - i) < 150.0 ) )
			collision = 1;
	}

	if(( abs(x - (500)) < 200.0 )  && (y < 100.0))
		collision = 1;
}

void destroyParachute(float x,float y,float z) {

	for (int i=0;i<parachute_position.size();i++)
	{
		if( ( abs(x -parachute_position[i].x_coordinate) < 200.0 )  && (abs(y - parachute_position[i].y_coordinate) < 200.0) && (z - parachute_position[i].z_coordinate < 200.0 ) )
		{
			if(parachute_position[i].isbarrel && fuel<=85)
				fuel += 15;
			else if(parachute_position[i].isbarrel && fuel>85)
				fuel = 100;
			parachute_position.erase(parachute_position.begin()+i);
			score += 50 ;
		}
	}
}

void addNewParachute() {
	while(parachute_position.size() < 5)  {
		int x_coord =  -500  + rand()%700 ;
		int y_coord =  rand()%1000 + 500;
		int  z_coord = (z - 1000) - rand()%1500;
		int flag = 1;
		
		for(int i=0; i<parachute_position.size(); i++) {
			if( abs(parachute_position[i].z_coordinate - z_coord) < 200)
				flag = 0;
		}

		if(flag == 1) {
			struct parachute temp;
			temp.x_coordinate = x_coord;
			temp.y_coordinate = y_coord;
			temp.z_coordinate = z_coord;
			temp.isbarrel = (0==rand()%5);
			parachute_position.push_back(temp);
		}
	}
}

void drawWorld(){
	srand (time(NULL));

	checkCollision();
	moveCars();
	addNewCars();
	moveParachute();
	addNewParachute();	
																																																																																																					

	if(worldNum == 1){
		if(makeitcrash == 1)
		{
			deltaMove = 50.0f;
			y += -20;
			if(y<=0)
			{
				collision = 1;
				makeitcrash = 0;
				deltaMove = 0.0f;
			}

		}

		if(gunOn == 1)
		{
			glEnable(GL_TEXTURE_2D);
			for(int i=0; i<gpos.size(); i++) {
				gpos[i].glife += 1;
				if(gpos[i].glife>50)
				{
					gpos.erase(gpos.begin()+i);
					continue;
				}

				glPushMatrix();								// CHARACTERS
				glTranslatef(gpos[i].px+gpos[i].gx * gpos[i].glife  ,gpos[i].py+gpos[i].gy * gpos[i].glife,gpos[i].pz+gpos[i].gz * gpos[i].glife);
				glRotatef(270.0, 0.0, 0.0, 0.0);
				glScalef(40,47,40);
				glCallList(BULLET);
				glPopMatrix();
				destroyParachute(gpos[i].px+gpos[i].gx * gpos[i].glife  ,gpos[i].py+gpos[i].gy * gpos[i].glife,gpos[i].pz+gpos[i].gz * gpos[i].glife);
			}
			
		}
		
		if(collision == 0) {
			glPushMatrix();								// CHARACTERS
				glTranslatef(x,y,z);
				glRotatef(90, 0.0, 1.0, 0.0);
				
				overallTilt += deltaTiltPlane;
				if(overallTilt < 0)
					overallTilt += 1.0;
				else if(overallTilt > 0)
					overallTilt -= 1.0;

				glRotatef(overallTilt,1.0,0.0,0.0);

				glRotatef(rotatePlane+deltaRotate, 0.0, 1.0, 0.0);
				glScalef(40,47,40);
				glCallList(PLANE);
			glPopMatrix();
			for(int i=0; i<4; i++)
			{
				moveBodyParts[i][0] = x;
				moveBodyParts[i][1] = y;
				moveBodyParts[i][2] = z;		
			}
		}
		else {
			if(flagsound==1)
			{
				initializecrashSound();
				flagsound++;
			}

			collision++;
			moveBodyParts[2][1] -= 8.0;
			if(moveBodyParts[2][1] <0)
				moveBodyParts[2][1] = 0;
			moveBodyParts[2][2] -= 6.0;

			moveBodyParts[0][1] += 4.0;
			moveBodyParts[1][1] -= 4.0;


			moveBodyParts[3][1] -= 4.0;
			moveBodyParts[3][2] -= 4.0;

			for(int i=0; i<4; i++) {
				if(i==2)
					continue;
				if(moveBodyParts[i][1] < 0)
					moveBodyParts[i][1] = 0;
			}

			glPushMatrix();								// CHARACTERS
				glTranslatef(moveBodyParts[0][0],moveBodyParts[0][1],moveBodyParts[0][2]);
				glRotatef(90, 0.0, 1.0, 0.0);
				
				overallTilt += deltaTiltPlane;
				if(overallTilt < 0)
					overallTilt += 1.0;
				else if(overallTilt > 0)
					overallTilt -= 1.0;

				glRotatef(overallTilt,1.0,0.0,0.0);

				glRotatef(rotatePlane+deltaRotate, 0.0, 1.0, 0.0);
				glScalef(40,47,40);
				glCallList(UPPER);
			glPopMatrix();


			glPushMatrix();								// CHARACTERS
				glTranslatef(moveBodyParts[1][0],moveBodyParts[1][1],moveBodyParts[1][2]);
				glRotatef(90, 0.0, 1.0, 0.0);
				
				overallTilt += deltaTiltPlane;
				if(overallTilt < 0)
					overallTilt += 1.0;
				else if(overallTilt > 0)
					overallTilt -= 1.0;

				glRotatef(overallTilt,1.0,0.0,0.0);

				glRotatef(rotatePlane+deltaRotate, 0.0, 1.0, 0.0);
				glScalef(40,47,40);
				glCallList(LOWER);
			glPopMatrix();

			glPushMatrix();								// CHARACTERS
				glTranslatef(moveBodyParts[2][0],moveBodyParts[2][1],moveBodyParts[2][2]);
				glRotatef(90, 0.0, 1.0, 0.0);
				
				overallTilt += deltaTiltPlane;
				if(overallTilt < 0)
					overallTilt += 1.0;
				else if(overallTilt > 0)
					overallTilt -= 1.0;

				glRotatef(overallTilt,1.0,0.0,0.0);

				glRotatef(rotatePlane+deltaRotate, 0.0, 1.0, 0.0);
				glScalef(40,47,40);
				glCallList(MIDDLEBODY);
			glPopMatrix();


			glPushMatrix();								// CHARACTERS
				glTranslatef(moveBodyParts[3][0],moveBodyParts[3][1],moveBodyParts[3][2]);
				glRotatef(90, 0.0, 1.0, 0.0);
				
				overallTilt += deltaTiltPlane;
				if(overallTilt < 0)
					overallTilt += 1.0;
				else if(overallTilt > 0)
					overallTilt -= 1.0;

				glRotatef(overallTilt,1.0,0.0,0.0);

				glRotatef(rotatePlane+deltaRotate, 0.0, 1.0, 0.0);
				glScalef(40,47,40);
				glCallList(TYRE);
			glPopMatrix();
		}

		glPushMatrix();								// CHARACTERS
				glTranslatef(100.0f,0.0f,-7000);
				glRotatef(0.0, 0.0, 1.0, 0.0);
				glScalef(1,1,1);
				glCallList(RAILING);
		glPopMatrix();
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, finishline);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
      glBegin(GL_QUADS);
          glTexCoord2f(0,0);  glVertex3f(-800.0f,400.0f,-6800.0f);
          glTexCoord2f(1,0);  glVertex3f(800.0f,400.0f,-6800.0f);
          glTexCoord2f(1,1);  glVertex3f(800.0f,0.0f,-6800.0f);
          glTexCoord2f(0,1);  glVertex3f(-800.0f,0.0f,-6800.0f);
      glEnd();

   glDisable(GL_TEXTURE_2D);

		// glPushMatrix();								// CHARACTERS
		// 	glTranslatef(-500.0f,10.0f,-2000.0f);
		// 	glRotatef(270.0, 0.0, 0.0, 0.0);
		// 	glScalef(20,20,20);
		// 	glCallList(MAN);
		// glPopMatrix();


		// glPushMatrix();								// CHARACTERS
		// 	glTranslatef(-500.0f,10.0f,-1000.0f);
		// 	glRotatef(250.0, 0.0, 1.0, 0.0);
		// 	glScalef(20,20,20);
		// 	glCallList(MAN);
		// glPopMatrix();

		
		for(int i=5000; i>=-5000; i-=800) {
			glPushMatrix();								// CHARACTERS
				glTranslatef(390.0f,0.0f,float(i));
				glRotatef(90.0, 0.0, 1.0, 0.0);
				glScalef(1,1,1);
				glCallList(RAILING);
			glPopMatrix();
		}

		for(int i = 0; i>= -5000; i -= 800) {
			glPushMatrix();								// CHARACTERS
			glTranslatef(-700.0f,0.0f,(float)i);
			glScalef(3,3,3);
			glCallList(TREE);
			glPopMatrix();
			glPushMatrix();								// CHARACTERS
			glTranslatef(700.0f,0.0f,(float)i);
			glScalef(3,3,3);
			glCallList(TREE);
			glPopMatrix();
		}
		
		 
		glPushMatrix();								// CHARACTERS
			glTranslatef(-1600.0f,0.0f,-3000.0f);
			glRotatef(270.0, 1.0, 0.0, 0.0);
			glRotatef(-90.0, 0.0, 0.0, 1.0);
			glScalef(1,1,1);
			glCallList(BUILDING);
		glPopMatrix();
		
		
	
   		//drawRect(-400.0f,0.0f,-1000.0f,800.0f,10000.0f,1,road);
 		for(int i=0; i<cars_position.size(); i++) {
										// CHARACTERS
 				glPushMatrix();	
				glTranslatef(get_x_coordinate(cars_position[i].first),0.0f,float(cars_position[i].second));
				glRotatef(get_angle(cars_position[i].first), 0.0, 1.0, 0.0);
				glScalef(200,200,200);
				glCallList(CAR);
				glPopMatrix();
		}
		for(int i=0; i<parachute_position.size(); i++) {
										// CHARACTERS
 				glPushMatrix();	
				glTranslatef(float(parachute_position[i].x_coordinate),
					float(parachute_position[i].y_coordinate),float(parachute_position[i].z_coordinate));
				glRotatef(270.0, 0.0, 0.0, 0.0);
				glScalef(150,150,150);
				glCallList(PARACHUTE);
				glPopMatrix();

				if(parachute_position[i].isbarrel)
				{
					glPushMatrix();	
					glTranslatef(float(parachute_position[i].x_coordinate),
					float(parachute_position[i].y_coordinate)-225,float(parachute_position[i].z_coordinate));
					glRotatef(270.0, 0.0, 0.0, 0.0);
					glScalef(50,50,50);
					glCallList(BARREL);
					glPopMatrix();	
				}
				
		}

		
		// //glEnable(GL_LIGHTING);
		// 		/* radius */
		// double r=500.0;
		// double height=1000.0;
		// /* number of side faces */
		// int faces=360;
		// /* Choose neutral color (white)*/
		// //glColor3d(1,1,1);
		// /* Enable 2D Texture*/
		// glEnable(GL_TEXTURE_2D);
		// /* set current working texture */
		// glBindTexture(GL_TEXTURE_2D, sky);

		//  Disabling these is not necessary in this example,
		// * BUT if you have previously enabled GL_TEXTURE_GEN_
		// * for other textures,then you need these lines
		
		// glDisable(GL_TEXTURE_GEN_S);
		// glDisable(GL_TEXTURE_GEN_T);

		// glBegin(GL_QUAD_STRIP);
		// double x, y, z;
		// y=height;
		// for (int i =0; i <= faces; i++) {
		// 	 double u = i/ (double) faces;
		// 	 x = r*cos(2*M_PI*u);
		// 	 z = r*sin(2*M_PI*u);
		// 	 /* Bottom vertex*/
		// 	 glTexCoord2f(u, 1.0); glVertex3d( x, 0, z );
		// 	 /* Top vertex*/
		// 	 glTexCoord2f(u, 0.0); glVertex3d( x, y, z );
		// }
		// glEnd();

			
	
	}
	if(fuel > 0 && z<=-6800)
		gamefinish = 1;

	if(fuel <= 0 && y > 10) {
		makeitcrash = 1;	
	}
	else if(fuel <=0 && collision==0)
		gameover = 1;
	
	if(collision >= 20)
		gameover = 1;
	renderHUD();
}
