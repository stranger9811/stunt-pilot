#include "global.h"

void menu(int n){
	int mName;
	if (n==1) mName = mainMenu;
	else if (n==2) mName = pauseMenu;
    else if (n==3) mName = soundOff;
    else if (n==4) mName = soundOn;
     glEnable(GL_TEXTURE_2D);

    if(n==1 || n==2){
        glBindTexture(GL_TEXTURE_2D, mName);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(350, 200);
            glTexCoord2f(0, 1);  glVertex2f(350, 300);
            glTexCoord2f(1, 1);  glVertex2f(450, 300);
            glTexCoord2f(1, 0);  glVertex2f(450, 200);
        glEnd();
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, mName);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(0, 0);
            glTexCoord2f(0, 1);  glVertex2f(0, 450);
            glTexCoord2f(1, 1);  glVertex2f(800, 450);
            glTexCoord2f(1, 0);  glVertex2f(800, 0 );
        glEnd();
    }

     glDisable(GL_TEXTURE_2D);
}

void arrowMenu(){
     glEnable(GL_TEXTURE_2D);
    if(menuNum == 1)
    {
        glBindTexture(GL_TEXTURE_2D, play_game);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(0, 0);
            glTexCoord2f(0, 1);  glVertex2f(0, 450);
            glTexCoord2f(1, 1);  glVertex2f(800, 450);
            glTexCoord2f(1, 0);  glVertex2f(800, 0 );
        glEnd();
    }
    else if(menuNum == 2)
    {
        glBindTexture(GL_TEXTURE_2D, settings_game);
        glBegin(GL_QUADS);
           glTexCoord2f(0, 0);  glVertex2f(0, 0);
            glTexCoord2f(0, 1);  glVertex2f(0, 450);
            glTexCoord2f(1, 1);  glVertex2f(800, 450);
            glTexCoord2f(1, 0);  glVertex2f(800, 0 );
        glEnd();
    }
    else if(menuNum == 3)
    {
        glBindTexture(GL_TEXTURE_2D, exit_game);
        glBegin(GL_QUADS);
           glTexCoord2f(0, 0);  glVertex2f(0, 0);
            glTexCoord2f(0, 1);  glVertex2f(0, 450);
            glTexCoord2f(1, 1);  glVertex2f(800, 450);
            glTexCoord2f(1, 0);  glVertex2f(800, 0 );
        glEnd();
    }
     glDisable(GL_TEXTURE_2D);
}

void mainMenuCall(void){
	if(inGame == 0)
    {
    	if(menuNum == 1){
            inGame = 2;
            menuNum = 1;
    	}else if(menuNum == 2){
            inGame = 3;
            menuNum = 1;
    	}else if(menuNum == 3){
    		exit(0);
    	}
    }
    else if(inGame == 1)
    {
        if(menuNum == 1){
            inGame = 4;
            menuNum = 1;
        }else if(menuNum == 2){
            inGame = 3;
            menuNum = 1;
        }else if(menuNum == 3){
            exit(0);
        }
    }
    else if(inGame == 2)
    {
        if(menuNum == 1 || menuNum == 3)
        {
            inGame = 4;
            worldNum = 1;
        }
        else
        {
            inGame = 4;
            worldNum = 2;
        }
        pauseGame = true;
    }
    else if(inGame == 3)
    {
        if(menuNum == 1)
        {
            //XXXX if( Mix_PausedMusic() == 1 )
            //     Mix_ResumeMusic();
            // else
            //     Mix_PauseMusic();
        }
        else
        {
            if(!pauseGame)
                inGame = 0;
            else
                inGame = 1;
        }
    }
}

void renderGameMenu(void){
	orthoSet();
	menu(1);
	arrowMenu();
	orthoReset();
}

void renderPauseMenu(void){
	orthoSet();
	menu(2);
    arrowMenu();
	orthoReset();	
}

void renderSettingsMenu(void){
    orthoSet();
   //XXXX if( Mix_PausedMusic() == 1 )
            if(1)
                menu(3);
            else
                menu(4);
    orthoReset();
}

void renderWorldMenu(void){
    orthoSet();
    glEnable(GL_TEXTURE_2D);
    if(menuNum == 1 || menuNum == 3)
    {
        glBindTexture(GL_TEXTURE_2D, level_1);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(0, 0);
            glTexCoord2f(0, 1);  glVertex2f(0, 450);
            glTexCoord2f(1, 1);  glVertex2f(800, 450);
            glTexCoord2f(1, 0);  glVertex2f(800, 0 );
        glEnd();    
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, level_2);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(0, 0);
            glTexCoord2f(0, 1);  glVertex2f(0, 450);
            glTexCoord2f(1, 1);  glVertex2f(800, 450);
            glTexCoord2f(1, 0);  glVertex2f(800, 0 );
        glEnd();    
    }
    glDisable(GL_TEXTURE_2D);
    orthoReset();
}

void renderMenu(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);
	if (inGame == 0){
		renderGameMenu();
	}
	else if (inGame == 1){
		renderPauseMenu();
	}
    else if (inGame == 2){
        renderWorldMenu();
    }
    else if (inGame == 3){
        renderSettingsMenu();
    }
}