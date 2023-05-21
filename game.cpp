#ifndef DODGE_CPP_
#define DODGE_CPP_
#include"util.h"
#include<iostream>
#include<string>
#include<cmath>
#include <cstdlib>
using namespace std;

void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}



float x = 300; 				//Opponent car x co-ordinates
float y = 610;				//Opponent car y co-ordinates
int x2 = 490; 			//Player car x co-ordinates
int y2 = 610;				//Player car y co-ordinates
float x3 = 50;				//Opponent car lvl 4 x co-ordinates
float y3 = 100;				//Opponent car lvl 4 y co-ordinates
float x4 = 330; 			//Player car 2 x co-ordinates
float y4 = 610;				//Player car 2 y co-ordinates
float pspeed=0;
float ospeed=0;
float gift[64] = { 0 };			//Array for gift boxes
float bonusgift[3] = { true };
int gap_turn = 60;
int sx = 20;
int sy = -90;
int swidth = 800 / 2 - gap_turn / 2;
int sheight = 10;
float* scolor = colors[BROWN];		//Color for arena
int score;
int score2;
int random = 4;
int level = 1;


bool boost = false;
bool single = false;
bool lane = true;
bool scores = true;
bool start = true;
bool lvl2 = true;
bool lvl3 = true;
bool lvl4 = true;


//X and Y co-ordinates for gift boxes
int gift_x1;
int gift_y1;
int gift_x2;
int gift_y2;
int gift_x3;
int gift_y3;
int gift_x4;
int gift_y4;


int bonusgift_x1;
int bonusgift_y1;
int bonusgift_x2;
int bonusgift_y2;
int bonusgift_x3;
int bonusgift_y3;


void level2()
{
	if (score == 64)
	{		//When user has collected all the gifts than level 2 will be implemented
		level++;
		x = 300; y = 610;
		x2 = 490; y2 = 610;
		lane = true;
	}
}
// This function is used to carry out level 3
void level3()
{
	if (score == 128)
	{		//When user has collected all the gifts than level 3 will be implemented
		level++;
		x = 300; y = 610;
		x2 = 490; y2 = 610;
		lane = true;
	}
}
// This function is used to carry out level 4
void level4()
{
	if (score == 192)
	{		//When user has collected all the gifts than level 4 will be implemented
		level++;
		x = 300; y = 610;
		x2 = 490; y2 = 610;
		lane = true;
	}
}





void ArtInt()
{
	//Applying Artificial Intelligence Logic for opponent car
	if (level == 1)
	{
		//Going from Arena 1 to 2


		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550)) //Location of player
		{
			if (x > 45 && x < 755) //Location of opponent
			{
				if (x == 400 && y == 30) // Moving Down
				{
					y += 60;
				}
				if (x == 400 && y == 610) // Moving up
				{
					y -= 60;
				}
			}
		}

		//Going from Arena 2 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480))
		{
			if (x > 135 && x < 675)
			{
				if (x == 400 && y == 90)
				{
					y += 60;
				}
				if (x == 400 && y == 550)
				{
					y -= 70;
				}
			}
		}

		//Going from Arena 3 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (x > 215 && x < 575)
			{
				if (x == 400 && y == 150)
				{
					y += 70;
				}
				if (x == 400 && y == 480)
				{
					y -= 60;
				}
			}
		}

		//Going from Arena 4 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480))
		{
			if (x > 305 && x < 495)
			{
				if (x == 400 && y == 220)
				{
					y -= 70;
				}
				if (x == 400 && y == 420)
				{
					y += 60;
				}
			}
		}

		//Going from Arena 3 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550))
		{
			if (x > 215 && x < 575)
			{
				if (x == 400 && y == 150)
				{
					y -= 60;
				}
				if (x == 400 && y == 480)
				{
					y += 70;
				}
			}
		}

		//Going from Arena 2 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (x > 135 && x < 675)
			{
				if (x == 400 && y == 90)
				{
					y -= 60;
				}
				if (x == 400 && y == 550)
				{
					y += 60;
				}
			}
		}

		//Going from Arena 1 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480)) //Location of player
		{
			if (x > 45 && x < 755) //Location of opponent
			{
				if (x == 400 && y == 30) // Moving Down
				{
					y += 60;
				}
				if (x == 400 && y == 610) // Moving up
				{
					y -= 60;
				}
			}
		}

		//Going from Arena 1 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (x > 45 && x < 755) //Location of opponent
			{
				if (x == 400 && y == 30) // Moving Down
				{
					y += 60;
				}
				if (x == 400 && y == 610) // Moving up
				{
					y -= 60;
				}
			}
		}

		//Going from Arena 3 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (x > 215 && x < 575)
			{
				if (x == 400 && y == 150)
				{
					y -= 60;
				}
				if (x == 400 && y == 480)
				{
					y += 70;
				}
			}
		}

		//Going from Arena 2 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (x > 135 && x < 675)
			{
				if (x == 400 && y == 90)
				{
					y += 60;
				}
				if (x == 400 && y == 550)
				{
					y -= 70;
				}
			}
		}

		//Going from Arena 4 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550))
		{
			if (x > 305 && x < 495)
			{
				if (x == 400 && y == 220)
				{
					y -= 70;
				}
				if (x == 400 && y == 420)
				{
					y += 60;
				}
			}
		}

		//Going from Arena 4 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (x > 305 && x < 495)
			{
				if (x == 400 && y == 220)
				{
					y -= 70;
				}
				if (x == 400 && y == 420)
				{
					y += 60;
				}
			}
		}
	}


	if (level == 2 || level == 3)
	{



		//Going from Arena 1 to 2


		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550)) //Location of player
		{
			if (x > 45 && x < 755) //Location of opponent
			{
				if (x == 400 && y == 30) // Moving Down
				{
					y += 60;
				}
				if (x == 400 && y == 610) // Moving up
				{
					y -= 60;
				}
			}
		}

		//Going from Arena 2 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480))
		{
			if (x > 135 && x < 675)
			{
				if (x == 400 && y == 90)
				{
					y += 60;
				}
				if (x == 400 && y == 550)
				{
					y -= 70;
				}
			}
		}

		//Going from Arena 3 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (x > 215 && x < 575)
			{
				if (x == 400 && y == 150)
				{
					y += 70;
				}
				if (x == 400 && y == 480)
				{
					y -= 60;
				}
			}
		}

		//Going from Arena 4 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480))
		{
			if (x > 305 && x < 495)
			{
				if (x == 400 && y == 220)
				{
					y -= 70;
				}
				if (x == 400 && y == 420)
				{
					y += 60;
				}
			}
		}

		//Going from Arena 3 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550))
		{
			if (x > 215 && x < 575)
			{
				if (x == 400 && y == 150)
				{
					y -= 60;
				}
				if (x == 400 && y == 480)
				{
					y += 70;
				}
			}
		}

		//Going from Arena 2 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (x > 135 && x < 675)
			{
				if (x == 400 && y == 90)
				{
					y -= 60;
				}
				if (x == 400 && y == 550)
				{
					y += 60;
				}
			}
		}

		//Going from Arena 1 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480)) //Location of player
		{
			if (x > 45 && x < 755) //Location of opponent
			{
				if (x == 400 && y == 30) // Moving Down
				{
					y += 60;
				}
				if (x == 400 && y == 610) // Moving up
				{
					y -= 60;
				}
			}
		}

		//Going from Arena 1 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (x > 45 && x < 755) //Location of opponent
			{
				if (x == 400 && y == 30) // Moving Down
				{
					y += 60;
				}
				if (x == 400 && y == 610) // Moving up
				{
					y -= 60;
				}
			}
		}

		//Going from Arena 3 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (x > 215 && x < 575)
			{
				if (x == 400 && y == 150)
				{
					y -= 60;
				}
				if (x == 400 && y == 480)
				{
					y += 70;
				}
			}
		}

		//Going from Arena 2 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (x > 135 && x < 675)
			{
				if (x == 400 && y == 90)
				{
					y += 60;
				}
				if (x == 400 && y == 550)
				{
					y -= 70;
				}
			}
		}

		//Going from Arena 4 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550))
		{
			if (x > 305 && x < 495)
			{
				if (x == 400 && y == 220)
				{
					y -= 70;
				}
				if (x == 400 && y == 420)
				{
					y += 60;
				}
			}
		}

		//Going from Arena 4 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (x > 305 && x < 495)
			{
				if (x == 400 && y == 220)
				{
					y -= 70;
				}
				if (x == 400 && y == 420)
				{
					y += 60;
				}
			}
		}

		//For Level 2

		//Moving from Arena 1 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550)) //Location of player
		{
			if (y > 25 && y < 615)
			{
				if (x == 50 && y == 320)
				{
					x += 90;
				}
				if (x == 750 && y == 320)
				{
					x -= 80;
				}
			}
		}


		//Moving from Arena 2 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480))
		{
			if (y > 85 && y < 555)
			{
				if (x == 140 && y == 320)
				{
					x += 80;
				}
				if (x == 670 && y == 320)
				{
					x -= 100;
				}
			}
		}

		//Moving from Arena 3 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (y > 145 && y < 485)
			{
				if (x == 220 && y == 320)
				{
					x += 90;
				}
				if (x == 570 && y == 320)
				{
					x -= 80;
				}
			}
		}

		//Moving from Arena 4 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480))
		{
			if (y > 215 && y < 425)
			{
				if (x == 310 && y == 320)
				{
					x -= 90;
				}
				if (x == 490 && y == 320)
				{
					x += 80;
				}
			}
		}

		//Moving from Arena 3 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550))
		{
			if (y > 145 && y < 485)
			{
				if (x == 220 && y == 320)
				{
					x -= 80;
				}
				if (x == 570 && y == 320)
				{
					x += 100;
				}
			}
		}


		//Moving from Arena 2 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (y > 85 && y < 555)
			{
				if (x == 140 && y == 320)
				{
					x -= 90;
				}
				if (x == 670 && y == 320)
				{
					x += 80;
				}
			}
		}

		//Moving from Arena 1 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480)) //Location of player
		{
			if (y > 25 && y < 615)
			{
				if (x == 50 && y == 320)
				{
					x += 90;
				}
				if (x == 750 && y == 320)
				{
					x -= 80;
				}
			}
		}

		//Going from Arena 1 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (y > 25 && y < 615)
			{
				if (x == 50 && y == 320)
				{
					x += 90;
				}
				if (x == 750 && y == 320)
				{
					x -= 80;
				}
			}
		}

		//Going from Arena 3 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (y > 145 && y < 485)
			{
				if (x == 220 && y == 320)
				{
					x -= 80;
				}
				if (x == 570 && y == 320)
				{
					x += 100;
				}
			}
		}

		//Going from Arena 2 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (y > 85 && y < 555)
			{
				if (x == 140 && y == 320)
				{
					x += 80;
				}
				if (x == 670 && y == 320)
				{
					x -= 100;
				}
			}
		}

		//Going from Arena 4 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550))
		{
			if (y > 215 && y < 425)
			{
				if (x == 310 && y == 320)
				{
					x -= 90;
				}
				if (x == 490 && y == 320)
				{
					x += 60;
				}
			}
		}

		//Going from Arena 4 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (y > 215 && y < 425)
			{
				if (x == 310 && y == 320)
				{
					x -= 90;
				}
				if (x == 490 && y == 320)
				{
					x += 80;
				}
			}
		}
	}






	if (level == 4)
	{
		//Going from Arena 1 to 2


		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550)) //Location of player
		{
			if (x > 45 && x < 755) //Location of opponent
			{
				if (x == 400 && y == 30) // Moving Down
				{
					y += 60;
				}
				if (x == 400 && y == 610) // Moving up
				{
					y -= 60;
				}
			}
			if (x3 > 45 && x3 < 755) //Location of opponent
			{
				if (x3 == 400 && y3 == 30) // Moving Down
				{
					y += 60;
				}
				if (x3 == 400 && y3 == 610) // Moving up
				{
					y3 -= 60;
				}
			}
		}

		//Going from Arena 2 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480))
		{
			if (x > 135 && x < 675)
			{
				if (x == 400 && y == 90)
				{
					y += 60;
				}
				if (x == 400 && y == 550)
				{
					y -= 70;
				}
			}
			if (x3 > 135 && x3 < 675)
			{
				if (x3 == 400 && y3 == 90)
				{
					y += 60;
				}
				if (x3 == 400 && y3 == 550)
				{
					y -= 70;
				}
			}
		}

		//Going from Arena 3 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (x > 215 && x < 575)
			{
				if (x == 400 && y == 150)
				{
					y += 70;
				}
				if (x == 400 && y == 480)
				{
					y -= 60;
				}
			}
			if (x3 > 215 && x3 < 575)
			{
				if (x3 == 400 && y3 == 150)
				{
					y3 += 70;
				}
				if (x3 == 400 && y3 == 480)
				{
					y3 -= 60;
				}
			}
		}

		//Going from Arena 4 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480))
		{
			if (x > 305 && x < 495)
			{
				if (x == 400 && y == 220)
				{
					y -= 70;
				}
				if (x == 400 && y == 420)
				{
					y += 60;
				}
			}
			if (x3 > 305 && x3 < 495)
			{
				if (x3 == 400 && y3 == 220)
				{
					y3 -= 70;
				}
				if (x3 == 400 && y3 == 420)
				{
					y3 += 60;
				}
			}
		}

		//Going from Arena 3 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550))
		{
			if (x > 215 && x < 575)
			{
				if (x == 400 && y == 150)
				{
					y -= 60;
				}
				if (x == 400 && y == 480)
				{
					y += 70;
				}
			}
			if (x3 > 215 && x3 < 575)
			{
				if (x3 == 400 && y3 == 150)
				{
					y3 -= 60;
				}
				if (x3 == 400 && y3 == 480)
				{
					y3 += 70;
				}
			}
		}

		//Going from Arena 2 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (x > 135 && x < 675)
			{
				if (x == 400 && y == 90)
				{
					y -= 60;
				}
				if (x == 400 && y == 550)
				{
					y += 60;
				}
			}
			if (x3 > 135 && x3 < 675)
			{
				if (x3 == 400 && y3 == 90)
				{
					y3 -= 60;
				}
				if (x3 == 400 && y3 == 550)
				{
					y3 += 60;
				}
			}
		}


		//Going from Arena 1 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480)) //Location of player
		{
			if (x > 45 && x < 755) //Location of opponent
			{
				if (x == 400 && y == 30) // Moving Down
				{
					y += 60;
				}
				if (x == 400 && y == 610) // Moving up
				{
					y -= 60;
				}
			}
			if (x3 > 45 && x3 < 755) //Location of opponent
			{
				if (x3 == 400 && y3 == 30) // Moving Down
				{
					y3 += 60;
				}
				if (x3 == 400 && y3 == 610) // Moving up
				{
					y3 -= 60;
				}
			}
		}

		//Going from Arena 1 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (x > 45 && x < 755) //Location of opponent
			{
				if (x == 400 && y == 30) // Moving Down
				{
					y += 60;
				}
				if (x == 400 && y == 610) // Moving up
				{
					y -= 60;
				}
			}
			if (x3 > 45 && x3 < 755) //Location of opponent
			{
				if (x3 == 400 && y3 == 30) // Moving Down
				{
					y3 += 60;
				}
				if (x3 == 400 && y3 == 610) // Moving up
				{
					y3 -= 60;
				}
			}
		}

		//Going from Arena 3 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (x > 215 && x < 575)
			{
				if (x == 400 && y == 150)
				{
					y -= 60;
				}
				if (x == 400 && y == 480)
				{
					y += 70;
				}
			}
			if (x3 > 215 && x3 < 575)
			{
				if (x3 == 400 && y3 == 150)
				{
					y3 -= 60;
				}
				if (x3 == 400 && y3 == 480)
				{
					y3 += 70;
				}
			}
		}

		//Going from Arena 2 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (x > 135 && x < 675)
			{
				if (x == 400 && y == 90)
				{
					y += 60;
				}
				if (x == 400 && y == 550)
				{
					y -= 70;
				}
			}
			if (x3 > 135 && x3 < 675)
			{
				if (x3 == 400 && y3 == 90)
				{
					y += 60;
				}
				if (x3 == 400 && y3 == 550)
				{
					y -= 70;
				}
			}
		}

		//Going from Arena 4 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550))
		{
			if (x > 305 && x < 495)
			{
				if (x == 400 && y == 220)
				{
					y -= 70;
				}
				if (x == 400 && y == 420)
				{
					y += 60;
				}
			}
			if (x3 > 305 && x3 < 495)
			{
				if (x3 == 400 && y3 == 220)
				{
					y3 -= 70;
				}
				if (x3 == 400 && y3 == 420)
				{
					y3 += 60;
				}
			}
		}

		//Going from Arena 4 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (x > 305 && x < 495)
			{
				if (x == 400 && y == 220)
				{
					y -= 70;
				}
				if (x == 400 && y == 420)
				{
					y += 60;
				}
			}
			if (x3 > 305 && x3 < 495)
			{
				if (x3 == 400 && y3 == 220)
				{
					y3 -= 70;
				}
				if (x3 == 400 && y3 == 420)
				{
					y3 += 60;
				}
			}
		}

		//For side ways changing lane

		//Moving from Arena 1 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550)) //Location of player
		{
			if (y > 25 && y < 615)
			{
				if (x == 50 && y == 320)
				{
					x += 90;
				}
				if (x == 750 && y == 320)
				{
					x -= 80;
				}
			}
			if (y3 > 25 && y3 < 615)
			{
				if (x3 == 50 && y3 == 320)
				{
					x3 += 90;
				}
				if (x3 == 750 && y3 == 320)
				{
					x3 -= 80;
				}
			}
		}


		//Moving from Arena 2 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480))
		{
			if (y > 85 && y < 555)
			{
				if (x == 140 && y == 320)
				{
					x += 80;
				}
				if (x == 670 && y == 320)
				{
					x -= 100;
				}
			}
			if (y > 85 && y < 555)
			{
				if (x3 == 140 && y3 == 320)
				{
					x3 += 80;
				}
				if (x3 == 670 && y3 == 320)
				{
					x3 -= 100;
				}
			}
		}

		//Moving from Arena 3 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (y > 145 && y < 485)
			{
				if (x == 220 && y == 320)
				{
					x += 90;
				}
				if (x == 570 && y == 320)
				{
					x -= 80;
				}
			}
			if (y3 > 145 && y3 < 485)
			{
				if (x3 == 220 && y3 == 320)
				{
					x3 += 90;
				}
				if (x3 == 570 && y3 == 320)
				{
					x3 -= 80;
				}
			}
		}

		//Moving from Arena 4 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480))
		{
			if (y > 215 && y < 425)
			{
				if (x == 310 && y == 320)
				{
					x -= 90;
				}
				if (x == 490 && y == 320)
				{
					x += 80;
				}
			}
			if (y3 > 215 && y3 < 425)
			{
				if (x3 == 310 && y3 == 320)
				{
					x3 -= 90;
				}
				if (x3 == 490 && y3 == 320)
				{
					x3 += 80;
				}
			}
		}

		//Moving from Arena 3 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550))
		{
			if (y > 145 && y < 485)
			{
				if (x == 220 && y == 320)
				{
					x -= 80;
				}
				if (x == 570 && y == 320)
				{
					x += 100;
				}
			}
			if (y3 > 145 && y3 < 485)
			{
				if (x3 == 220 && y3 == 320)
				{
					x3 -= 80;
				}
				if (x3 == 570 && y3 == 320)
				{
					x3 += 100;
				}
			}
		}


		//Moving from Arena 2 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (y > 85 && y < 555)
			{
				if (x == 140 && y == 320)
				{
					x -= 90;
				}
				if (x == 670 && y == 320)
				{
					x += 80;
				}
			}
			if (y3 > 85 && y3 < 555)
			{
				if (x3 == 140 && y3 == 320)
				{
					x -= 90;
				}
				if (x3 == 670 && y3 == 320)
				{
					x3 += 80;
				}
			}
		}

		//Moving from Arena 1 to 3
		if ((x2 == 570 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 150) || (x2 == 220 && y2 > 145 && y2 < 485) || (x2 > 215 && x2 < 575 && y2 == 480)) //Location of player
		{
			if (y > 25 && y < 615)
			{
				if (x == 50 && y == 320)
				{
					x += 90;
				}
				if (x == 750 && y == 320)
				{
					x -= 80;
				}
			}
			if (y3 > 25 && y3 < 615)
			{
				if (x3 == 50 && y3 == 320)
				{
					x3 += 90;
				}
				if (x3 == 750 && y3 == 320)
				{
					x3 -= 80;
				}
			}
		}

		//Going from Arena 1 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (y > 25 && y < 615)
			{
				if (x == 50 && y == 320)
				{
					x += 90;
				}
				if (x == 750 && y == 320)
				{
					x -= 80;
				}
			}
			if (y3 > 25 && y3 < 615)
			{
				if (x3 == 50 && y3 == 320)
				{
					x3 += 90;
				}
				if (x3 == 750 && y3 == 320)
				{
					x3 -= 80;
				}
			}
		}

		//Going from Arena 3 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (y > 145 && y < 485)
			{
				if (x == 220 && y == 320)
				{
					x -= 80;
				}
				if (x == 570 && y == 320)
				{
					x += 100;
				}
			}
			if (y3 > 145 && y3 < 485)
			{
				if (x3 == 220 && y3 == 320)
				{
					x3 -= 80;
				}
				if (x3 == 570 && y3 == 320)
				{
					x3 += 100;
				}
			}
		}

		//Going from Arena 2 to 4
		if ((x2 == 490 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 220) || (x2 == 310 && y2 > 215 && y2 < 425) || (x2 > 305 && x2 < 495 && y2 == 420))
		{
			if (y > 85 && y < 555)
			{
				if (x == 140 && y == 320)
				{
					x += 80;
				}
				if (x == 670 && y == 320)
				{
					x -= 100;
				}
			}
			if (y3 > 85 && y3 < 555)
			{
				if (x3 == 140 && y3 == 320)
				{
					x3 += 80;
				}
				if (x3 == 670 && y3 == 320)
				{
					x3 -= 100;
				}
			}
		}

		//Going from Arena 4 to 2
		if ((x2 == 670 && y2 > 85 && y2 < 555) || (x2 > 135 && x2 < 675 && y2 == 90) || (x2 == 140 && y2 < 555 && y2 > 85) || (x2 < 675 && x2 > 135 && y2 == 550))
		{
			if (y > 215 && y < 425)
			{
				if (x == 310 && y == 320)
				{
					x -= 90;
				}
				if (x == 490 && y == 320)
				{
					x += 60;
				}
			}
			if (y3 > 215 && y3 < 425)
			{
				if (x3 == 310 && y3 == 320)
				{
					x3 -= 90;
				}
				if (x3 == 490 && y3 == 320)
				{
					x3 += 60;
				}
			}
		}

		//Going from Arena 4 to 1
		if ((x2 < 755 && x2 > 45 && y2 == 610) || (x2 == 750 && y2 > 25 && y2 < 615) || (x2 > 45 && x2 < 755 && y2 == 30) || (x2 == 50 && y2 < 615 && y2 > 25))
		{
			if (y > 215 && y < 425)
			{
				if (x == 310 && y == 320)
				{
					x -= 90;
				}
				if (x == 490 && y == 320)
				{
					x += 80;
				}
			}
			if (y3 > 215 && y3 < 425)
			{
				if (x3 == 310 && y3 == 320)
				{
					x3 -= 90;
				}
				if (x3 == 490 && y3 == 320)
				{
					x3 += 80;
				}
			}
		}
	}
}


void speeds()
{
	if (level == 1 || level == 2 || level == 3 || level == 4 && start == false)
	{
		ospeed = 5;

		if (boost == true)
		{
			pspeed = 10;
		}
		else
		{
			pspeed = 5;
		}
	}
	if (start == true)
	{
		pspeed = 0;
		ospeed = 0;
	}
	if (score + score2 == 64)
	{
		pspeed = 0;
		ospeed = 0;
	}
}


void Movement_of_opponent_cars()
{
	//Movement of opponent car in Arena 1
	if (x < 755 && x > 45 && y == 610)
	{
		x -= ospeed;
	}
	if (x == 750 && y > 25 && y < 615)
	{
		y += ospeed;
	}
	if (x > 45 && x < 755 && y == 30)
	{
		x += ospeed;
	}
	if (x == 50 && y < 615 && y > 25)
	{
		y -= ospeed;
	}
	//Movement of opponent car in Arena 2
	if (x == 670 && y > 85 && y < 555)
	{
		y += ospeed;
	}
	if (x > 135 && x < 675 && y == 90)
	{
		x += ospeed;
	}
	if (x == 140 && y < 555 && y > 85)
	{
		y -= ospeed;
	}
	if (x < 675 && x > 135 && y == 550)
	{
		x -= ospeed;
	}

	//Movement of opponent car in Arena 3
	if (x == 570 && y > 145 && y < 485)
	{
		y += ospeed;
	}
	if (x > 215 && x < 575 && y == 150)
	{
		x += ospeed;
	}
	if (x == 220 && y > 145 && y < 485)
	{
		y -= ospeed;
	}
	if (x > 215 && x < 575 && y == 480)
	{
		x -= ospeed;
	}

	//Movement of opponent car in Arena 4
	if (x == 490 && y > 215 && y < 425)
	{
		y += ospeed;
	}
	if (x > 305 && x < 495 && y == 220)
	{
		x += ospeed;
	}
	if (x == 310 && y > 215 && y < 425)
	{
		y -= ospeed;
	}
	if (x > 305 && x < 495 && y == 420)
	{
		x -= ospeed;
	}


	if (level == 4)
	{
		//Movement of opponent 2 car in Arena 1
		if (x3 < 755 && x3 > 45 && y3 == 610)
		{
			x3 -= ospeed;
		}
		if (x3 == 750 && y3 > 25 && y3 < 615)
		{
			y3 += ospeed;
		}
		if (x3 > 45 && x3 < 755 && y3 == 30)
		{
			x3 += ospeed;
		}
		if (x3 == 50 && y3 < 615 && y3 > 25)
		{
			y3 -= ospeed;
		}
		//Movement of opponent 2 car in Arena 2
		if (x3 == 670 && y3 > 85 && y3 < 555)
		{
			y3 += ospeed;
		}
		if (x3 > 135 && x3 < 675 && y3 == 90)
		{
			x3 += ospeed;
		}
		if (x3 == 140 && y3 < 555 && y3 > 85)
		{
			y3 -= ospeed;
		}
		if (x3 < 675 && x3 > 135 && y3 == 550)
		{
			x3 -= ospeed;
		}

		//Movement of opponent car in Arena 3
		if (x3 == 570 && y3 > 145 && y3 < 485)
		{
			y3 += ospeed;
		}
		if (x3 > 215 && x3 < 575 && y3 == 150)
		{
			x3 += ospeed;
		}
		if (x3 == 220 && y3 > 145 && y3 < 485)
		{
			y3 -= ospeed;
		}
		if (x3 > 215 && x3 < 575 && y3 == 480)
		{
			x3 -= ospeed;
		}

		//Movement of opponent 2 car in Arena 4
		if (x3 == 490 && y3 > 215 && y3 < 425)
		{
			y3 += ospeed;
		}
		if (x3 > 305 && x3 < 495 && y3 == 220)
		{
			x3 += ospeed;
		}
		if (x3 == 310 && y3 > 215 && y3 < 425)
		{
			y3 -= ospeed;
		}
		if (x3 > 305 && x3 < 495 && y3 == 420)
		{
			x3 -= ospeed;
		}
	}
}



void Movement_of_player_cars()
{
	//Movement of player car in Arena 1
	if (x2 < 755 && x2 > 45 && y2 == 610)
	{
		x2 += pspeed;
		if (boost == true && x2 % 10 != 0)
		{
			x2 += 5;
		}
	}
	if (x2 == 750 && y2 > 25 && y2 < 615)
	{
		y2 -= pspeed;
		if (boost == true && y2 % 10 != 0)
		{
			y2 -= 5;
		}
	}
	if (x2 > 45 && x2 < 755 && y2 == 30)
	{
		x2 -= pspeed;
		if (boost == true && x2 % 10 != 0)
		{
			x2 -= 5;
		}
	}
	if (x2 == 50 && y2 < 615 && y2 > 25)
	{
		y2 += pspeed;
		if (boost == true && y2 % 10 != 0)
		{
			y2 += 5;
		}
	}

	//Movement of player car in Arena 2
	if (x2 == 670 && y2 > 85 && y2 < 555)
	{
		y2 -= pspeed;
		if (boost == true && y2 % 10 != 0)
		{
			y2 -= 5;
		}
	}
	if (x2 > 135 && x2 < 675 && y2 == 90)
	{
		x2 -= pspeed;
		if (boost == true && x2 % 10 != 0)
		{
			x2 -= 5;
		}
	}
	if (x2 == 140 && y2 < 555 && y2 > 85)
	{
		y2 += pspeed;
		if (boost == true && y2 % 10 != 0)
		{
			y2 += 5;
		}
	}
	if (x2 < 675 && x2 > 135 && y2 == 550)
	{
		x2 += pspeed;
		if (boost == true && x2 % 10 != 0)
		{
			x2 += 5;
		}
	}

	//Movement of player car in Arena 3
	if (x2 == 570 && y2 > 145 && y2 < 485)
	{
		y2 -= pspeed;
		if (boost == true && y2 % 10 != 0)
		{
			y2 -= 5;
		}
	}
	if (x2 > 215 && x2 < 575 && y2 == 150)
	{
		x2 -= pspeed;
		if (boost == true && x2 % 10 != 0)
		{
			x2 -= 5;
		}
	}
	if (x2 == 220 && y2 > 145 && y2 < 485)
	{
		y2 += pspeed;
		if (boost == true && y2 % 10 != 0)
		{
			y2 += 5;
		}
	}
	if (x2 > 215 && x2 < 575 && y2 == 480)
	{
		x2 += pspeed;
		if (boost == true && x2 % 10 != 0)
		{
			x2 += 5;
		}
	}

	//Movement of player car in Arena 4
	if (x2 == 490 && y2 > 215 && y2 < 425)
	{
		y2 -= pspeed;
		if (boost == true && y2 % 10 != 0)
		{
			y2 -= 5;
		}
	}
	if (x2 > 305 && x2 < 495 && y2 == 220)
	{
		x2 -= pspeed;
		if (boost == true && x2 % 10 != 0)
		{
			x2 -= 5;
		}
	}
	if (x2 == 310 && y2 > 215 && y2 < 425)
	{
		y2 += pspeed;
		if (boost == true && y2 % 10 != 0)
		{
			y2 += 5;
		}
	}
	if (x2 > 305 && x2 < 495 && y2 == 420)
	{
		x2 += pspeed;
		if (boost == true && x2 % 10 != 0)
		{
			x2 += 5;
		}
	}
	if (single == true)
	{
		//Movement of player car 2 in Arena 1
		if (x4 < 755 && x4 > 45 && y4 == 610)
		{
			x4 -= pspeed;
		}
		if (x4 == 750 && y4 > 25 && y4 < 615)
		{
			y4 += pspeed;
		}
		if (x4 > 45 && x4 < 755 && y4 == 30)
		{
			x4 += pspeed;
		}
		if (x4 == 50 && y4 < 615 && y4 > 25)
		{
			y4 -= pspeed;
		}

		//Movement of player car 2 in Arena 2
		if (x4 == 670 && y4 > 85 && y4 < 555)
		{
			y4 += pspeed;
		}
		if (x4 > 135 && x4 < 675 && y4 == 90)
		{
			x4 += pspeed;
		}
		if (x4 == 140 && y4 < 555 && y4 > 85)
		{
			y4 -= pspeed;
		}
		if (x4 < 675 && x4 > 135 && y4 == 550)
		{
			x4 -= pspeed;
		}

		//Movement of player car 2 in Arena 3
		if (x4 == 570 && y4 > 145 && y4 < 485)
		{
			y4 += pspeed;
		}
		if (x4 > 215 && x4 < 575 && y4 == 150)
		{
			x4 += pspeed;
		}
		if (x4 == 220 && y4 > 145 && y4 < 485)
		{
			y4 -= pspeed;
		}
		if (x4 > 215 && x4 < 575 && y4 == 480)
		{
			x4 -= pspeed;
		}

		//Movement of player car 2 in Arena 4
		if (x4 == 490 && y4 > 215 && y4 < 425)
		{
			y4 += pspeed;
		}
		if (x4 > 305 && x4 < 495 && y4 == 220)
		{
			x4 += pspeed;
		}
		if (x4 == 310 && y4 > 215 && y4 < 425)
		{
			y4 -= pspeed;
		}
		if (x4 > 305 && x4 < 495 && y4 == 420)
		{
			x4 -= pspeed;
		}


	}
}

void GameDisplay() {
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors


	if (start == true)
	{
		glClearColor(0.2/*Red Component*/, 0.3,	/*148.0/255Green Component*/ 0.1/*Blue Component*/, 0 /*Alpha component*/);
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors

		// Drawing D
		DrawRectangle(5, 180, 120, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Up D
		DrawRectangle(15, 180, sheight * 2, 140, colors[STEEL_BLUE]);   //Vertical Left D
		DrawRectangle(5, 300, 120, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Down D 
		DrawRectangle(115, 180, sheight * 2, 140, colors[STEEL_BLUE]);		//Vertical Right D



		//Drawing O
		DrawRectangle(140, 180, 120, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Up O
		DrawRectangle(140, 180, sheight * 2, 140, colors[STEEL_BLUE]);		//Vertical Left O
		DrawRectangle(140, 300, 120, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Down O
		DrawRectangle(240, 180, sheight * 2, 140, colors[STEEL_BLUE]);		//Vertical Right O


		//Drawing D
		DrawRectangle(265, 180, 120, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Up D
		DrawRectangle(275, 180, sheight * 2, 140, colors[STEEL_BLUE]);		//Vertical Left D
		DrawRectangle(265, 300, 120, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Down D 
		DrawRectangle(375, 180, sheight * 2, 140, colors[STEEL_BLUE]);		//Vertical Right D




		//Drawing G
		DrawRectangle(400, 180, 120, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Up G
		DrawRectangle(400, 180, sheight * 2, 140, colors[STEEL_BLUE]);		//Vertical Left G
		DrawRectangle(400, 300, 120, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Down G
		DrawRectangle(500, 180, sheight * 2, 70, colors[STEEL_BLUE]);		//Vertical Right G
		DrawRectangle(450, 240, 70, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Middle G




		//Drawing E
		DrawRectangle(525, 180, sheight * 2, 140, colors[STEEL_BLUE]);		//Vertical Left E
		DrawRectangle(525, 300, 80, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Down E
		DrawRectangle(525, 180, 80, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Up E
		DrawRectangle(525, 240, 70, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Middle E





		DrawRectangle(608, 300, sheight, 35, colors[STEEL_BLUE]);		//Comma




		//Drawing E
		DrawRectangle(620, 180, sheight * 2, 140, colors[STEEL_BLUE]);		//Vertical Left E
		DrawRectangle(620, 300, 80, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Down E
		DrawRectangle(620, 180, 80, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Up E
		DrawRectangle(620, 240, 70, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Middle E




		//Drawing M
		DrawRectangle(710, 300, 100, sheight * 2, colors[STEEL_BLUE]);		//Horizontal Up M
		DrawRectangle(805, 180, sheight * 2, 140, colors[STEEL_BLUE]);		//Vertical Left M
		DrawRectangle(710, 180, sheight * 2, 140, colors[STEEL_BLUE]);		//Vertical Right M
		DrawRectangle(757, 230, sheight * 2, 90, colors[STEEL_BLUE]);		//Vertical Middle M

		DrawString(350, 600, "SINGLE  PLAYER", colors[RED]);
		DrawString(350, 550, "MULTI    PLAYER", colors[RED]);
		DrawString(400, 500, "HELP", colors[RED]);
		DrawString(400, 450, "EXIT", colors[RED]);

	}


	if (start == false)
	{

		if (single == false)
		{
			if (boost == true)
			{
				DrawString(20, 720, "TURBO MODE: ON", colors[LAVENDER_BLUSH]);
			}
			else
			{
				DrawString(20, 720, "TURBO MODE: OFF", colors[LAVENDER_BLUSH]);
			}
			if (level == 1)
			{
				DrawString(340, 700, "L  E  V  E  L     1", colors[RED]);
				DrawString(600, 700, "S C O R E  =  ", colors[RED]);
				DrawString(740, 700, to_string(score), colors[RED]);

			}

			if (level == 2)
			{
				DrawString(340, 700, "L  E  V  E  L     2", colors[RED]);
				DrawString(600, 700, "S C O R E  =  ", colors[RED]);
				DrawString(740, 700, to_string(score), colors[RED]);
			}



			if (level == 3)
			{
				DrawString(340, 700, "L  E  V  E  L     3", colors[RED]);
				DrawString(600, 700, "S C O R E  =  ", colors[RED]);
				DrawString(740, 700, to_string(score), colors[RED]);
			}


			if (level == 4)
			{
				DrawString(340, 700, "L  E  V  E  L     4", colors[RED]);
				DrawString(600, 700, "S C O R E  =  ", colors[RED]);
				DrawString(740, 700, to_string(score), colors[RED]);
			}


				
			}






		if (single == false)
		{
			//Opponent car 1
			float width = 12;
			float height = 7;
			float* color = colors[RED];
			float radius = 5.0;
			DrawRoundRect(x, y, width, height, color, radius); // bottom left tyre
			DrawRoundRect(x + width * 3, y, width, height, color, radius); // bottom right tyre
			DrawRoundRect(x + width * 3, y + height * 4, width, height, color, radius); // top right tyre
			DrawRoundRect(x, y + height * 4, width, height, color, radius); // top left tyre
			DrawRoundRect(x, y + height * 2, width, height, color, radius / 2); // body left rect
			DrawRoundRect(x + width, y + height, width * 2, height * 3, color, radius / 2); // body center rect
			DrawRoundRect(x + width * 3, y + height * 2, width, height, color, radius / 2); // body right rect





			if (level == 4)
			{
				float width3 = 12;
				float height3 = 7;
				float* color3 = colors[RED];
				float radius3 = 5.0;
				DrawRoundRect(x3, y3, width3, height3, color3, radius3); // bottom left tyre
				DrawRoundRect(x3 + width3 * 3, y3, width3, height3, color3, radius3); // bottom right tyre
				DrawRoundRect(x3 + width3 * 3, y3 + height3 * 4, width3, height3, color3, radius3); // top right tyre
				DrawRoundRect(x3, y3 + height3 * 4, width3, height3, color3, radius3); // top left tyre
				DrawRoundRect(x3, y3 + height3 * 2, width3, height3, color3, radius3 / 2); // body left rect
				DrawRoundRect(x3 + width3, y3 + height3, width3 * 2, height3 * 3, color3, radius3 / 2); // body center rect
				DrawRoundRect(x3 + width3 * 3, y3 + height3 * 2, width3, height3, color3, radius3 / 2); // body right rect
			}

		}


		//Player car
		float width2 = 12;
		float height2 = 7;
		float* color2 = colors[NAVY];
		float radius2 = 5.0;
		DrawRoundRect(x2, y2, width2, height2, color2, radius2); // bottom left tyre
		DrawRoundRect(x2 + width2 * 3, y2, width2, height2, color2, radius2); // bottom right tyre
		DrawRoundRect(x2 + width2 * 3, y2 + height2 * 4, width2, height2, color2, radius2); // top right tyre
		DrawRoundRect(x2, y2 + height2 * 4, width2, height2, color2, radius2); // top left tyre
		DrawRoundRect(x2, y2 + height2 * 2, width2, height2, color2, radius2 / 2); // body left rect
		DrawRoundRect(x2 + width2, y2 + height2, width2 * 2, height2 * 3, color2, radius2 / 2); // body center rect
		DrawRoundRect(x2 + width2 * 3, y2 + height2 * 2, width2, height2, color2, radius2 / 2); // body right rect





		if (single == true)
		{

			//Player car 2
			float width4 = 12;
			float height4 = 7;
			float* color4 = colors[ORANGE];
			float radius4 = 5.0;
			DrawRoundRect(x4, y4, width4, height4, color4, radius4); // bottom left tyre
			DrawRoundRect(x4 + width4 * 3, y4, width4, height4, color4, radius4); // bottom right tyre
			DrawRoundRect(x4 + width4 * 3, y4 + height4 * 4, width4, height4, color4, radius4); // top right tyre
			DrawRoundRect(x4, y4 + height4 * 4, width4, height4, color4, radius4); // top left tyre
			DrawRoundRect(x4, y4 + height4 * 2, width4, height4, color4, radius4 / 2); // body left rect
			DrawRoundRect(x4 + width4, y4 + height4, width4 * 2, height4 * 3, color4, radius4 / 2); // body center rect
			DrawRoundRect(x4 + width4 * 3, y4 + height4 * 2, width4, height4, color4, radius4 / 2); // body right rect





			DrawString(540, 700, "S C O R E  P2  =  ", colors[RED]);
			DrawString(720, 700, to_string(score), colors[RED]);

			DrawString(100, 700, "S C O R E  P1  =  ", colors[RED]);
			DrawString(280, 700, to_string(score2), colors[RED]);


		}

		if (score + score2 == 64)
		{
			x2 = 490;
			y2 = 610;
			x4 = 300;
			y4 = 610;
			if (score > score2)
			{
				DrawString(267, 800, "P  L  A  Y  E  R     2     W  O  N", colors[RED]);
			}
			else if (score2 > score)
			{
				DrawString(267, 800, "P  L  A  Y  E  R     1     W  O  N", colors[RED]);
			}
			else if (score == score2)
			{
				DrawString(280, 800, "M  A  T  C  H     D  R  A  W", colors[RED]);
			}

		}


		//Drawing Arena(1)
		DrawRectangle(sx, sy + 100, swidth - 20, sheight, scolor); // bottom left	
		DrawRectangle(sx + swidth + gap_turn + 20, sy + 100, swidth - 20, sheight, scolor); // bottom right	
		DrawRectangle(sx - 2 + swidth * 2 + gap_turn, sy + 90 + sheight, sheight * 2, swidth - 100, scolor); // right down	
		DrawRectangle(sx + swidth * 2 + gap_turn, sy + 40 + sheight + swidth + gap_turn, sheight * 2, swidth - 90, scolor); // right up 
		DrawRectangle(sx + swidth + gap_turn + 20, sy + 750, swidth, sheight, scolor); // top right	
		DrawRectangle(sx, sy + 750, swidth - 20, sheight, scolor); // top left	
		DrawRectangle(sx + 2 - sheight * 2, sy + 40 + sheight + swidth + gap_turn, sheight * 2, swidth - 90, scolor); // left up	
		DrawRectangle(sx + 2 - sheight * 2, sy + 90 + sheight, sheight * 2, swidth - 100, scolor); // left down

																								   //Drawing Arena(2)
		DrawRectangle(sx + 100, sy + 160, swidth - 120, sheight, scolor); // bottom left
		DrawRectangle(sx + 102 - sheight * 2, sy + 150 + sheight, sheight * 2, swidth - 160, scolor); // left down
		DrawRectangle(sx + swidth + gap_turn + 20, sy + 680, swidth - 100, sheight, scolor); // top right
		DrawRectangle(sx - 95 + swidth * 2 + gap_turn, sy + 100 + sheight + swidth - 60 + gap_turn, sheight * 2, swidth - 160, scolor); // right up
		DrawRectangle(sx + 102 - sheight * 2, sy + 40 + sheight + swidth - 60 + gap_turn + 60, sheight * 2, swidth - 160, scolor); // left up
		DrawRectangle(sx + 10 + swidth - 90 + gap_turn + 100, sy + 160, swidth - 110, sheight, scolor); // bottom right
		DrawRectangle(sx - 95 + swidth * 2 + gap_turn, sy + 150 + sheight, sheight * 2, swidth - 160, scolor); // right down
		DrawRectangle(sx + 100, sy + 680, swidth - 120, sheight, scolor); // top left

																		  //Drawing Arena(3)
		DrawRectangle(sx + 190, sy + 220, swidth - 210, sheight, scolor); // bottom left
		DrawRectangle(sx + 195 - sheight * 2, sy + 210 + sheight, sheight * 2, swidth - 220, scolor); // left down
		DrawRectangle(sx + swidth + gap_turn + 20, sy + 620, swidth - 200, sheight, scolor); // top right
		DrawRectangle(sx - 185 + swidth * 2 + gap_turn, sy + 130 + sheight + swidth - 90 + gap_turn, sheight * 2, swidth - 220, scolor); // right up
		DrawRectangle(sx + 195 - sheight * 2, sy + 120 + sheight + swidth - 140 + gap_turn + 60, sheight * 2, swidth - 220, scolor); // left up
		DrawRectangle(sx + swidth - 150 + gap_turn + 170, sy + 220, swidth - 200, sheight, scolor); // bottom right
		DrawRectangle(sx - 185 + swidth * 2 + gap_turn, sy + 210 + sheight, sheight * 2, swidth - 220, scolor); // right down
		DrawRectangle(sx + 190, sy + 620, swidth - 210, sheight, scolor); // top left

																		  //Drawing Arena(4)
		DrawRectangle(sx + 275, sy + 290, swidth - 295, sheight, scolor); // bottom left
		DrawRectangle(sx + 280 - sheight * 2, sy + 280 + sheight, sheight * 2, swidth - 290, scolor); // left down
		DrawRectangle(sx + 2 + swidth - 180 + gap_turn + 200, sy + 290, swidth - 290, sheight, scolor); // bottom right
		DrawRectangle(sx - 275 + swidth * 2 + gap_turn, sy + 280 + sheight, sheight * 2, swidth - 290, scolor); // right down
		DrawRectangle(sx + 275, sy + 560, swidth - 295, sheight, scolor); // top left	
		DrawRectangle(sx + 280 - sheight * 2, sy + 160 + sheight + swidth - 180 + gap_turn + 60, sheight * 2, swidth - 280, scolor); // left up
		DrawRectangle(sx + swidth + gap_turn + 20, sy + 560, swidth - 290, sheight, scolor); // top right
		DrawRectangle(sx - 275 + swidth * 2 + gap_turn, sy + 180 + sheight + swidth - 140 + gap_turn, sheight * 2, swidth - 280, scolor); // right up

																																		  //Drawing Arena(5)
		DrawRectangle(sx + 355, sy + 370, swidth - 325, sheight, scolor); // bottom left	
		DrawRectangle(sx - 50 + swidth + gap_turn + 15, sy + 370, swidth - 320, sheight, scolor); // bottom right	
		DrawRectangle(sx - 360 + swidth * 2 + gap_turn, sy + 360 + sheight, sheight * 2, swidth - 320, scolor); // right down	
		DrawRectangle(sx - 360 + swidth * 2 + gap_turn, sy + 200 + sheight + swidth - 200 + gap_turn, sheight * 2, swidth - 320, scolor); // right up 
		DrawRectangle(sx - 50 + swidth + gap_turn + 15, sy + 480, swidth - 320, sheight, scolor); // top right	
		DrawRectangle(sx + 355, sy + 480, swidth - 325, sheight, scolor); // top left	
		DrawRectangle(sx + 370 - sheight * 2, sy + 250 + sheight + swidth - 250 + gap_turn, sheight * 2, swidth - 320, scolor); // left up	
		DrawRectangle(sx + 370 - sheight * 2, sy + 360 + sheight, sheight * 2, swidth - 320, scolor); // left down




		if (lane == true)
		{
			for (int i = 0;i < 64;i++)
			{
				gift[i] = true;
			}
			lane = false;
		}


		if (score == 256)
		{
			DrawRectangle(250, 310, 20, 60, colors[GOLDEN_ROD]);
			DrawRectangle(250, 310, 60, 20, colors[GOLDEN_ROD]);
			DrawRectangle(290, 250, 20, 120, colors[GOLDEN_ROD]);
			DrawRectangle(250, 250, 60, 20, colors[GOLDEN_ROD]);
			DrawRectangle(250, 250, 20, 30, colors[GOLDEN_ROD]);
			DrawRectangle(320, 310, 10, 40, colors[GOLDEN_ROD]);
			DrawRectangle(320, 310, 35, 10, colors[GOLDEN_ROD]);
			DrawRectangle(320, 340, 35, 10, colors[GOLDEN_ROD]);
			DrawRectangle(345, 310, 10, 40, colors[GOLDEN_ROD]);
			DrawRectangle(365, 310, 10, 40, colors[GOLDEN_ROD]);
			DrawRectangle(365, 310, 35, 10, colors[GOLDEN_ROD]);
			DrawRectangle(390, 310, 10, 40, colors[GOLDEN_ROD]);
			DrawRectangle(430, 310, 80, 20, colors[GOLDEN_ROD]);
			DrawRectangle(430, 310, 20, 60, colors[GOLDEN_ROD]);
			DrawRectangle(465, 310, 10, 50, colors[GOLDEN_ROD]);
			DrawRectangle(490, 310, 20, 60, colors[GOLDEN_ROD]);
			DrawRectangle(520, 310, 10, 40, colors[GOLDEN_ROD]);
			DrawSquare(520, 360, 10, colors[GOLDEN_ROD]);
			DrawRectangle(540, 310, 10, 50, colors[GOLDEN_ROD]);
			DrawRectangle(540, 340, 35, 10, colors[GOLDEN_ROD]);
			DrawRectangle(565, 310, 10, 32, colors[GOLDEN_ROD]);
			DrawSquare(585, 310, 10, colors[GOLDEN_ROD]);
			DrawRectangle(585, 330, 10, 50, colors[GOLDEN_ROD]);
			level = 1;
			pspeed = 0;
			ospeed = 0;
			x = 300; y = 610;
			x2 = 490; y2 = 610;
		}



		if (single == false)
		{
			//Drawing gifts
			//Gifts in left bottom area
			int i = 0;
			for (gift_x1 = 70; gift_x1 <= 340; gift_x1 += 90)
			{
				for (gift_y1 = 45; gift_y1 <= 225; gift_y1 += 60)
				{
					if (gift[i] == true)
					{
						if ((gift_x1 + 30) >= x2 && (gift_x1 - 30) <= x2)
						{
							if ((gift_y1 + 30) >= y2 && (gift_y1 - 30) <= y2)
							{
								gift[i] = false;
								score += 1;
							}
						}
					}
					if (gift[i] == true)
					{
						DrawCircle(gift_x1, gift_y1, 5, colors[ORANGE]);
					}
					i++;
				}
			}


			//Gifts in right bottom area
			for (gift_x2 = 500; gift_x2 <= 770; gift_x2 += 90)
			{
				for (gift_y2 = 45; gift_y2 <= 225; gift_y2 += 60)
				{
					if (gift[i] == true)
					{
						if ((gift_x2 + 30) >= x2 && (gift_x2 - 30) <= x2)
						{
							if ((gift_y2 + 25) >= y2 && (gift_y2 - 25) <= y2)
							{
								gift[i] = false;
								score += 1;
							}
						}
					}
					if (gift[i] == true)
					{
						DrawCircle(gift_x2, gift_y2, 5, colors[ORANGE]);
					}
					i++;
				}
			}


			//Gifts in left top area
			for (gift_x3 = 70; gift_x3 <= 340; gift_x3 += 90)
			{
				for (gift_y3 = 440; gift_y3 <= 640; gift_y3 += 60)
				{
					if (gift[i] == true)
					{
						if ((gift_x3 + 32) >= x2 && (gift_x3 - 32) <= x2)
						{
							if ((gift_y3 + 30) >= y2 && (gift_y3 - 30) <= y2)
							{
								gift[i] = false;
								score += 1;
							}
						}
					}
					if (gift[i] == true)
					{
						DrawCircle(gift_x3, gift_y3, 5, colors[ORANGE]);
					}
					i++;
				}
			}


			//Gifts in right top area
			for (gift_x4 = 500; gift_x4 <= 770; gift_x4 += 90)
			{
				for (gift_y4 = 440; gift_y4 <= 620; gift_y4 += 60)
				{
					if (gift[i] == true)
					{
						if ((gift_x4 + 35) >= x2 && (gift_x4 - 35) <= x2)
						{
							if ((gift_y4 + 30) >= y2 && (gift_y4 - 30) <= y2)
							{
								gift[i] = false;
								score += 1;
							}
						}
					}
					if (gift[i] == true)
					{
						DrawCircle(gift_x4, gift_y4, 5, colors[ORANGE]);
					}
					i++;
				}
			}
		}



		if (single == true)
		{
			//Drawing gifts
			//Gifts in left bottom area
			int i = 0;
			for (gift_x1 = 70; gift_x1 <= 340; gift_x1 += 90)
			{
				for (gift_y1 = 45; gift_y1 <= 225; gift_y1 += 60)
				{
					if (gift[i] == true)
					{
						if ((gift_x1 + 30) >= x2 && (gift_x1 - 30) <= x2)
						{
							if ((gift_y1 + 30) >= y2 && (gift_y1 - 30) <= y2)
							{
								gift[i] = false;
								score += 1;
							}
						}
						if ((gift_x1 + 30) >= x4 && (gift_x1 - 30) <= x4)
						{
							if ((gift_y1 + 30) >= y4 && (gift_y1 - 30) <= y4)
							{
								gift[i] = false;
								score2 += 1;
							}
						}
					}
					if (gift[i] == true)
					{
						DrawCircle(gift_x1, gift_y1, 5, colors[ORANGE]);
					}
					i++;
				}
			}


			//Gifts in right bottom area
			for (gift_x2 = 500; gift_x2 <= 770; gift_x2 += 90)
			{
				for (gift_y2 = 45; gift_y2 <= 225; gift_y2 += 60)
				{
					if (gift[i] == true)
					{
						if ((gift_x2 + 30) >= x2 && (gift_x2 - 30) <= x2)
						{
							if ((gift_y2 + 25) >= y2 && (gift_y2 - 25) <= y2)
							{
								gift[i] = false;
								score += 1;
							}
						}
						if ((gift_x2 + 30) >= x4 && (gift_x2 - 30) <= x4)
						{
							if ((gift_y2 + 25) >= y4 && (gift_y2 - 25) <= y4)
							{
								gift[i] = false;
								score2 += 1;
							}
						}
					}
					if (gift[i] == true)
					{
						DrawCircle(gift_x2, gift_y2, 5, colors[ORANGE]);
					}
					i++;
				}
			}


			//Gifts in left top area
			for (gift_x3 = 70; gift_x3 <= 340; gift_x3 += 90)
			{
				for (gift_y3 = 440; gift_y3 <= 640; gift_y3 += 60)
				{
					if (gift[i] == true)
					{
						if ((gift_x3 + 32) >= x2 && (gift_x3 - 32) <= x2)
						{
							if ((gift_y3 + 30) >= y2 && (gift_y3 - 30) <= y2)
							{
								gift[i] = false;
								score += 1;
							}
						}
						if ((gift_x3 + 32) >= x4 && (gift_x3 - 32) <= x4)
						{
							if ((gift_y3 + 30) >= y4 && (gift_y3 - 30) <= y4)
							{
								gift[i] = false;
								score2 += 1;
							}
						}
					}
					if (gift[i] == true)
					{
						DrawCircle(gift_x3, gift_y3, 5, colors[ORANGE]);
					}
					i++;
				}
			}


			//Gifts in right top area
			for (gift_x4 = 500; gift_x4 <= 770; gift_x4 += 90)
			{
				for (gift_y4 = 440; gift_y4 <= 620; gift_y4 += 60)
				{
					if (gift[i] == true)
					{
						if ((gift_x4 + 35) >= x2 && (gift_x4 - 35) <= x2)
						{
							if ((gift_y4 + 30) >= y2 && (gift_y4 - 30) <= y2)
							{
								gift[i] = false;
								score += 1;
							}
						}
						if ((gift_x4 + 35) >= x4 && (gift_x4 - 35) <= x4)
						{
							if ((gift_y4 + 30) >= y4 && (gift_y4 - 30) <= y4)
							{
								gift[i] = false;
								score2 += 1;
							}
						}
					}
					if (gift[i] == true)
					{
						DrawCircle(gift_x4, gift_y4, 5, colors[ORANGE]);
					}
					i++;
				}
			}
		}
	}

	glutSwapBuffers();
}

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT)
	{
		if (x2 == 750 && y2 > 275 && y2 < 365)
		{
			x2 -= 80;
		}
		else if (x2 == 670 && y2 > 275 && y2 < 365)
		{
			x2 -= 100;
		}
		else if (x2 == 570 && y2 > 275 && y2 < 365)
		{
			x2 -= 80;
		}
		else if (x2 == 310 && y2 > 275 && y2 < 365)
		{
			x2 -= 90;
		}
		else if (x2 == 220 && y2 > 275 && y2 < 365)
		{
			x2 -= 80;
		}
		else if (x2 == 140 && y2 > 275 && y2 < 365)
		{
			x2 -= 90;
		}
	}
	else if (key == GLUT_KEY_RIGHT)
	{

		if (x2 == 50 && y2 > 275 && y2 < 365)
		{
			x2 += 90;
		}
		else if (x2 == 140 && y2 > 275 && y2 < 365)
		{
			x2 += 80;
		}
		else if (x2 == 220 && y2 > 275 && y2 < 365)
		{
			x2 += 90;
		}
		else if (x2 == 490 && y2 > 275 && y2 < 365)
		{
			x2 += 80;
		}
		else if (x2 == 570 && y2 > 275 && y2 < 365)
		{
			x2 += 100;
		}
		else if (x2 == 670 && y2 > 275 && y2 < 365)
		{
			x2 += 80;
		}
	}
	else if (key == GLUT_KEY_UP)
	{
		if (y2 == 30 && x2 > 365 && x2 < 485)
		{
			y2 += 60;
		}
		else if (y2 == 90 && x2 > 365 && x2 < 485)
		{
			y2 += 60;
		}
		else if (y2 == 150 && x2 > 365 && x2 < 485)
		{
			y2 += 70;
		}
		else if (y2 == 420 && x2 > 365 && x2 < 485)
		{
			y2 += 60;
		}
		else if (y2 == 480 && x2 > 365 && x2 < 485)
		{
			y2 += 70;
		}
		else if (y2 == 550 && x2 > 365 && x2 < 485)
		{
			y2 += 60;
		}
	}

	else if (key == GLUT_KEY_DOWN)
	{
		if (y2 == 610 && x2 > 365 && x2 < 485)
		{
			y2 -= 60;
		}
		else if (y2 == 550 && x2 > 365 && x2 < 485)
		{
			y2 -= 70;
		}
		else if (y2 == 480 && x2 > 365 && x2 < 485)
		{
			y2 -= 60;
		}
		else if (y2 == 220 && x2 > 365 && x2 < 485)
		{
			y2 -= 70;
		}
		else if (y2 == 150 && x2 > 365 && x2 < 485)
		{
			y2 -= 60;
		}
		else if (y2 == 90 && x2 > 365 && x2 < 485)
		{
			y2 -= 60;
		}

	}

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
* is pressed from the keyboard
* This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
* program coordinates of mouse pointer when key was pressed.
* */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27)
	{
		exit(1);
	}
	if (key == 32)
	{
		if (single == false)
		{

			if (boost == false)
			{
				boost = true;
			}
			else if (boost == true)
			{
				boost = false;
			}
		}
	}
	if (key == 'p' || key == 'P')
	{
		exit(1);
	}
	if (single == true)
	{
		if (key == 'a')
		{
			if (x4 == 750 && y4 > 275 && y4 < 365)
			{
				x4 -= 80;
			}
			else if (x4 == 670 && y4 > 275 && y4 < 365)
			{
				x4 -= 100;
			}
			else if (x4 == 570 && y4 > 275 && y4 < 365)
			{
				x4 -= 80;
			}
			else if (x4 == 310 && y4 > 275 && y4 < 365)
			{
				x4 -= 90;
			}
			else if (x4 == 220 && y4 > 275 && y4 < 365)
			{
				x4 -= 80;
			}
			else if (x4 == 140 && y4 > 275 && y4 < 365)
			{
				x4 -= 90;
			}
		}

		else if (key == 'd')
		{
			if (x4 == 50 && y4 > 275 && y4 < 365)
			{
				x4 += 90;
			}
			else if (x4 == 140 && y4 > 275 && y4 < 365)
			{
				x4 += 80;
			}
			else if (x4 == 220 && y4 > 275 && y4 < 365)
			{
				x4 += 90;
			}
			else if (x4 == 490 && y4 > 275 && y4 < 365)
			{
				x4 += 80;
			}
			else if (x4 == 570 && y4 > 275 && y4 < 365)
			{
				x4 += 100;
			}
			else if (x4 == 670 && y4 > 275 && y4 < 365)
			{
				x4 += 80;
			}
		}

		else if (key == 'w')
		{
			if (y4 == 30 && x4 > 365 && x4 < 485)
			{
				y4 += 60;
			}
			else if (y4 == 90 && x4 > 365 && x4 < 485)
			{
				y4 += 60;
			}
			else if (y4 == 150 && x4 > 365 && x4 < 485)
			{
				y4 += 70;
			}
			else if (y4 == 420 && x4 > 365 && x4 < 485)
			{
				y4 += 60;
			}
			else if (y4 == 480 && x4 > 365 && x4 < 485)
			{
				y4 += 70;
			}
			else if (y4 == 550 && x4 > 365 && x4 < 485)
			{
				y4 += 60;
			}
		}

		else if (key == 's')
		{
			if (y4 == 610 && x4 > 365 && x4 < 485)
			{
				y4 -= 60;
			}
			else if (y4 == 550 && x4 > 365 && x4 < 485)
			{
				y4 -= 70;
			}
			else if (y4 == 480 && x4 > 365 && x4 < 485)
			{
				y4 -= 60;
			}
			else if (y4 == 220 && x4 > 365 && x4 < 485)
			{
				y4 -= 70;
			}
			else if (y4 == 150 && x4 > 365 && x4 < 485)
			{
				y4 -= 60;
			}
			else if (y4 == 90 && x4 > 365 && x4 < 485)
			{
				y4 -= 60;
			}
		}
	}
	glutPostRedisplay();
}

void Timer(int m) {

	glutTimerFunc(13.0, Timer, 0);

		speeds();
		Movement_of_player_cars();

	if (single == false)
	{
		Movement_of_opponent_cars();
		ArtInt();
		level2();
		level3();
		level4();
	}

	glutPostRedisplay();
}


void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	cout << "Gamedisplay :" << x << " " << 840 - y << endl;
	cout << "\n\n";
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {


}


void MouseClicked(int button, int state, int x, int y) {


	if (button == GLUT_LEFT_BUTTON)
	{
		if (x > 350 && x < 545 && y > 220 && y < 240)
		{
			start = false;
		}
		if (x > 350 && x < 545 && y > 270 && y < 290)
		{
			start = false;
			single = true;
		}
	}
	else if (button == GLUT_RIGHT_BUTTON)
	{

	}
	glutPostRedisplay();
}

int main(int argc, char*argv[]) {

	int width = 840, height = 840; // i have set my window size to be 840 x 840
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