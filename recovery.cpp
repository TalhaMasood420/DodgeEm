//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include<iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
/*
 * Main Canvas drawing function.
 * */
//Board *b;
	float x = 310; 
	float y = 30;
	float x2 = 460; 
	float y2 = 30;
	float fruitx[64]={0};
	float fx=350;
	float fy=47;
	float fwidth=375;
	float fheight=8;
	float* fcolor = colors[WHITE];
	float* colorb = colors[WHITE];
	int gap_turn = 60;
	int sx = 20;
	int sy = -90;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	



	//Drawing gifts
	

	//Gifts in Arena1
	DrawRectangle(fx+fruitx[0], fy, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-95+fruitx[1], fy, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-190+fruitx[2], fy, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-280+fruitx[3], fy, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-280+fruitx[4], fy+60, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-280+fruitx[5], fy+120, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-280+fruitx[6], fy+180, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-280+fruitx[7], fy+380, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-280+fruitx[8], fy+440, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-280+fruitx[9], fy+500, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-280+fruitx[10], fy+570, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-190+fruitx[11], fy+570, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-95+fruitx[12], fy+570, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+fruitx[13], fy+570, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+160+fruitx[14], fy+570, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+255+fruitx[15], fy+570, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+350+fruitx[16], fy+570, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+445+fruitx[17], fy+570, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+445+fruitx[18], fy+500, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+445+fruitx[19], fy+440, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+445+fruitx[20], fy+380, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+445+fruitx[21], fy+180, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+445+fruitx[22], fy+120, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+445+fruitx[23], fy+60, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+445+fruitx[24], fy, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+350+fruitx[25], fy, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+255+fruitx[26], fy, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+160+fruitx[27], fy, fwidth-400, fheight, fcolor);

	//Gifts in Arena 2
	DrawRectangle(fx+fruitx[28], fy+60, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-95+fruitx[29], fy+60, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-190+fruitx[30], fy+60, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-190+fruitx[31], fy+120, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-190+fruitx[32], fy+180, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-190+fruitx[33], fy+380, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-190+fruitx[34], fy+440, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-190+fruitx[35], fy+500, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-95+fruitx[36], fy+500, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+fruitx[37], fy+500, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+160+fruitx[38], fy+500, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+255+fruitx[39], fy+500, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+350+fruitx[40], fy+500, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+350+fruitx[41], fy+440, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+350+fruitx[42], fy+380, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+350+fruitx[43], fy+180, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+350+fruitx[44], fy+120, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+350+fruitx[45], fy+60, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+255+fruitx[46], fy+60, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+160+fruitx[47], fy+60, fwidth-400, fheight, fcolor);

	//Gifts in Arena 3
	DrawRectangle(fx+fruitx[48], fy+120, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-95+fruitx[49], fy+120, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-95+fruitx[50], fy+180, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-95+fruitx[51], fy+380, fwidth-400, fheight, fcolor);
	DrawRectangle(fx-95+fruitx[52], fy+440, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+fruitx[53], fy+440, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+160+fruitx[54], fy+440, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+255+fruitx[55], fy+440, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+255+fruitx[56], fy+380, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+255+fruitx[57], fy+180, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+255+fruitx[58], fy+120, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+160+fruitx[59], fy+120, fwidth-400, fheight, fcolor);
	

	//Gifts in Arena 4
	DrawRectangle(fx+fruitx[60], fy+180, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+fruitx[61], fy+380, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+160+fruitx[62], fy+380, fwidth-400, fheight, fcolor);
	DrawRectangle(fx+160+fruitx[63], fy+180, fwidth-400, fheight, fcolor);

	
	
	//Drawing car 1

	float width = 12; 
	float height = 7;
	float* color = colors[YELLOW]; 
	float radius = 5.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect
	

	//Drawing car 2
	float width2 = 12; 
	float height2 = 7;
	float* color2 = colors[BLUE];
	float radius2 = 5.0;
	DrawRoundRect(x2,y2,width2,height2,color2,radius2); // bottom left tyre
	DrawRoundRect(x2+width2*3,y2,width2,height2,color2,radius2); // bottom right tyre
	DrawRoundRect(x2+width2*3,y2+height2*4,width2,height2,color2,radius2); // top right tyre
	DrawRoundRect(x2,y2+height2*4,width2,height2,color2,radius2); // top left tyre
	DrawRoundRect(x2, y2+height2*2, width2, height2, color2, radius2/2); // body left rect
	DrawRoundRect(x2+width2, y2+height2, width2*2, height2*3, color2, radius2/2); // body center rect
	DrawRoundRect(x2+width2*3, y2+height2*2, width2, height2, color2, radius2/2); // body right rect
	

	//Drawing Arena(1)
	DrawRectangle(20 , 10 , 350 , 10 , scolor);
	DrawRectangle(470 , 10 , 350 , 10 , scolor);
	DrawRectangle(818 , 10 , 20 , 270 , scolor);
	DrawRectangle(820 , 390 , 20 , 280 , scolor);
	DrawRectangle(470 , 660 , 370 , 10 , scolor);
	DrawRectangle(20 , 660 , 350 , 10 , scolor);
	DrawRectangle(2 , 390 , 20 , 280 , scolor);
	DrawRectangle(2 , 10 , 20 , 270 , scolor);
	
	//Drawing Arena(2)
	DrawRectangle(120 , 70 , 250 , 10 , scolor);
	DrawRectangle(102 , 70 , 20 , 210 , scolor);
	DrawRectangle(470 , 590 , 270 , 10, scolor);
	DrawRectangle(720 , 390 , 20 , 210 , scolor);
	DrawRectangle(102 , 390 , 20 , 210 , scolor);
	DrawRectangle(470 , 70 , 260 , 10 , scolor);
	DrawRectangle(720 , 70 , 20 , 210 , scolor);
	DrawRectangle(120 , 590 , 255 , 10 , scolor);
	
	//Drawing Arena(3)
	DrawRectangle(210 , 130 , 160 , 10 , scolor);
	DrawRectangle(195 , 130 , 20 , 150 , scolor);
	DrawRectangle(470 , 530 , 160 , 10 , scolor);
	DrawRectangle(625 , 390 , 20 , 150 , scolor);
	DrawRectangle(195 , 390 , 20 , 150 , scolor);
	DrawRectangle(470 , 130 , 160 , 10 , scolor);
	DrawRectangle(625 , 130 , 20 , 150 , scolor);
	DrawRectangle(210 , 530 , 160 , 10, scolor);

	//Drawing Arena(4)
	DrawRectangle(300 , 200 , 70 , 10 , scolor);
	DrawRectangle(285 , 200 , 20 , 80 , scolor);
	DrawRectangle(472 , 200 , 70 , 10 , scolor);
	DrawRectangle(535 , 200 , 20 , 80 , scolor);
	DrawRectangle(300 , 470 , 70 , 10 , scolor);
	DrawRectangle(285 , 390 , 20 , 90 , scolor);
	DrawRectangle(470 , 470 , 70 , 10 , scolor);
	DrawRectangle(535 , 390 , 20 , 90 , scolor);

	//Drawing Arena(5)
	DrawRectangle(368 , 280 , 50 , 10 , scolor);
	DrawRectangle(415 , 280 , 50 , 10 , scolor);
	DrawRectangle(460 , 280 , 20 , 50 , scolor);
	DrawRectangle(460 , 350 , 20 , 50 , scolor);
	DrawRectangle(415 , 390 , 50 , 10 , scolor);
	DrawRectangle(368 , 390 , 50 , 10 , scolor);
	DrawRectangle(360 , 350 , 20 , 50 , scolor);
	DrawRectangle(360 , 280 , 20 , 50 , scolor);
		
	


	
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT/*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {

	}
	else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B')
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(5.0, Timer, 0);

	//Movement of car 1 in Arena 1
	if (x<311 && x>30 && y==30)
	{
		x-=3;
	}
	if (x<32 && y>29 && y<610)
	{
		y+=3;
	}
	if (x>=31 && x<752 &&  y>605 )
	{
		x+=3;
	}
	if (x==751 && y>29)
	{
		y-=3;
	}
	if (x<753 && x>=310 && y==30)
	{
		x-=3;
	}

	//Movement of car 2 in Arena 1
	if (x2<755 && x2>459  && y2==30)
	{
		x2+=3;
	}
	if (x2>750 && y2<610)
	{
		y2+=3;
	}
	if (x2>33 && y2>605 && y2<610)
	{
		x2-=3;
	}
	if (x2>33 && x2<37 && y2>29)
	{
		y2-=3;
	}
	if (x2<=460 && y2<31)
	{
		x2+=3.1;
	}
	
	glutPostRedisplay();

}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << 840 - y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	
	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow(" DODGE 'EM "); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(5.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */`
