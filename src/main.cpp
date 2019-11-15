/************************************************************************
*The following C++ program utilizes class and is a smaller version of   *
*the game 2048. It is a 3x3 grid with two '2'. The user is asked which  *
*direction to move in. If two same numbers touch, they combine. After   *
*every move a random '2' is generated. Once the number 16 is reached the*
*player is victorious and it terminates. If all the tiles fill up and 16*
*isn't reached, and nothing can be combined, the player loses.					*
*																																				*
*************************************************************************/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sixteen.h"
using namespace std;

int main(int argc, char const *argv[])
{
//Initiate Class	
sixteen board; 

//Variables for entering direction.
char direction;

//Do-While loop cotrol. 
//If false, loop. If true, terminate.
int over = 0;

//Output Starting Board
board.output();

do{
//Prompt to enter move direction.
cout << "Which direction do you wish to move? [u,d,l,r]: " << endl;
cin >> direction;

direction = tolower(direction); //lowercase it

	//Error Check, reprompt.
	while(direction != 'u' && direction != 'd' && direction != 'l' && direction != 'r')
	{
		cin.clear();
		cin.ignore(100,'\n');

		cout << "Which direction do you wish to move? [u,d,l,r]: " << endl;
		cin >> direction;

		direction = tolower(direction);
	}

//Based on input. Move up,down,left,right.
if(direction == 'u')
{
	board.moveUp();
	board.output();
}
else if(direction == 'd')
{
	board.moveDown();
	board.output();
}
else if(direction == 'l')
{
	board.moveLeft();
	board.output();
}
else if(direction == 'r')
{
	board.moveRight();
	board.output();
}

//Update 'over' value. Either still 0, or 1, or -1.
over = board.over();

if(over == 1)
{
	cout << "You won!" << endl;
}
else if(over == -1)
{
	cout << "No possible moves, you lose!" << endl;
}

}while(over == 0);

	return 0;
}

/*
SAMPLE RESULT

 2  -  - 
 -  -  - 
 2  -  - 
Which direction do you wish to move? [u,d,l,r]: 
u
 4  -  - 
 -  -  - 
 -  2  - 
Which direction do you wish to move? [u,d,l,r]: 
d
 -  2  - 
 -  -  - 
 4  2  - 
Which direction do you wish to move? [u,d,l,r]: 
d
 -  -  - 
 -  -  2 
 4  4  - 
Which direction do you wish to move? [u,d,l,r]: 
l
 -  -  - 
 2  2  - 
 8  -  - 
Which direction do you wish to move? [u,d,l,r]: 
l
 -  2  - 
 4  -  - 
 8  -  - 
Which direction do you wish to move? [u,d,l,r]: 
l
 2  -  2 
 4  -  - 
 8  -  - 
Which direction do you wish to move? [u,d,l,r]: 
l
 4  -  - 
 4  -  2 
 8  -  - 
Which direction do you wish to move? [u,d,l,r]: 
d
 -  -  - 
 8  -  - 
 8  2  2 
Which direction do you wish to move? [u,d,l,r]: 
d
 -  2  - 
 -  -  - 
16  2  2 
You won!

*/
