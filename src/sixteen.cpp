#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "sixteen.h"
using namespace std;

sixteen::sixteen()
{//Iterate through 3x3 array. Initialize to zero.
	for(int row = 0;row<SIZE;row++)
	{
		for(int col = 0;col <SIZE;col++)
		{
			board[row][col] = 0;
		}
	}//Starting positions
	board[0][0] = 2;
	board[2][0] = 2;
	srand(time(NULL));

//Test for Loss. Provided by Professor
/*
board[0][0] = 2;
board[0][1] = 4;
board[0][2] = 2;

board[1][0] = 4;
board[1][1] = 2;
board[1][2] = 4;

board[2][0] = 2;
board[2][1] = 4;
board[2][2] = 2;
*/
}

void sixteen::moveLeft ()
{
	/*
		The following else-if statments check for every possible scenario when moving numbers across the board.
	*/
	for(int row = 0;row <SIZE;row++)
		{//If middle and right column are the same and there is a different number in the left column, 
			//double the middle column and make the right column zero.
			if(board[row][1] == board[row][2] && board[row][1] != board[row][0] && board[row][2] != board[row][0])
			{

				if(board[row][1] == board[row][2] && board[row][0] == 0)
				{//If number in left column is zero, shift everything over.
					board[row][0] = board[row][1] * 2;
					board[row][1] = 0;
					board[row][2] = 0;
				}
				else
				{
				board[row][1] *=2;
				board[row][2] = 0;
				}
			}//If left and middle column are same, double left columm and shift right column to middle column.
			else if(board[row][0] == board[row][1] && board[row][0] != board[row][2] && board[row][1] != board[row][2])
			{
				if(board[row][0] == 0 && board[row][1] == 0 && board[row][2] != 0)
				{//If left and middle column are zero, shift right columm left.
					board[row][0] = board[row][2];
					board[row][1] = 0;
					board[row][2] = 0;
				}
				else
				{
				board[row][0] *= 2;
				board[row][1] = board[row][2];
				board[row][2] = 0;
				}
			}//If no same numbers are touching, board stays same.
			else if(board[row][0] == board[row][2] && board[row][0] != board[row][1] && board[row][2] != board[row][1] && board[row][1] != 0)
			{//If left column is zero, shifts middle and right column to left side.
				if(board[row][0] == 0 && board[row][2] == 0 && board[row][1] != 0)
				{
					board[row][0] = board[row][1];
					board[row][1] = board[row][2];
					board[row][2] = 0;
				}
				else
				{
					board[row][0] = board[row][0];
					board[row][1] = board[row][1];
					board[row][2] = board[row][2];
				}
			}//If middle column is zero and left and right are same, combines them onto left side.
			else if(board[row][0] == board[row][2] && board[row][0] != board[row][1] && board[row][2] != board[row][1] && board[row][1] == 0)
			{
				board[row][0] *= 2;
				board[row][1] = 0;
				board[row][2] = 0;

			}//If all numbers are same, combines left and middle column, shifts right column over to middle column.
			else if(board[row][0] == board[row][1] && board[row][1] == board[row][2])
			{
				board[row][0] *=2;
				board[row][1] = board[row][2];
				board[row][2] = 0;
			}//If numbers in middle and right column are different, and left column is zero, sifts both left.
			else if(board[row][2] != board[row][1] && board[row][1] != board[row][0] && board[row][0] == 0)
			{
				board[row][0] = board[row][1];
				board[row][1] = board[row][2];
				board[row][2] = 0;
			}//If middle column is zero and left column is full, shifts right column over to middle so long as left column is different.
			else if(board[row][2] != board[row][1] && board[row][1] != board[row][0] && board[row][1] == 0)
			{
				board[row][1] = board[row][2];
				board[row][2] = 0;
			}
		}

		//GENERATE RANDOM 2			
		/*
			Generate x,y int variables and assign random number to them.
			Text x,y coordinate, if coordinate is '0', assign '2' there.
		*/	
		bool generated = false;
		do
		{
			int x,y;
			int random =rand()%9;

			y =	random % 3;
			x =	random / 3;

			if(board[x][y] == 0)
			{
				board[x][y] = 2;
				generated = true;
			}

		}while(generated == false);

}

void sixteen::moveRight ()
{
	for(int row = 0;row <SIZE;row++)
		{/*
				The following else-if statments check for every possible scenario when moving numbers across the board.
			*/
			if(board[row][0] == board[row][1] && board[row][0] != board[row][2] && board[row][1] != board[row][2])
			{//If middle and left column are the same and there is a different number in the right column, 
			//double the middle column and make the left column zero.

				if(board[row][0] == board[row][1] && board[row][2] == 0)
				{//If number in right column is zero, shift everything over.
					board[row][2] = board[row][1] * 2;
					board[row][1] = 0;
					board[row][0] = 0;
				}
				else
				{
				board[row][1] *=2;
				board[row][0] = 0;
				}
			}//If middle and right column are the same and not equal to left column, slide over to right column. Double right column.
			else if(board[row][1] == board[row][2] && board[row][1] != board[row][0] && board[row][2] != board[row][0])
			{//If right and middle column are zero, slide left column over to right column.
				if(board[row][2] == 0 && board[row][1] == 0 && board[row][0] != 0)
				{
					board[row][2] = board[row][0];
					board[row][1] = 0;
					board[row][0] = 0;
				}
				else
				{//Double right column, slide left column over to middle.
				board[row][2] *= 2;
				board[row][1] = board[row][0];
				board[row][0] = 0;
				}
			}//If left and right column are same and middle is not zero, board stays same.
			else if(board[row][0] == board[row][2] && board[row][0] != board[row][1] && board[row][2] != board[row][1] && board[row][1] != 0)
			{//If left and right column equal zero and middle doesn't, slide middle to right.
				if(board[row][0] == 0 && board[row][2] == 0 && board[row][1] != 0)
				{
					board[row][2] = board[row][1];
					board[row][1] = board[row][0];
					//board[row][2] = board[row][1];
					board[row][0] = 0;
				}
				else
				{//Board stays the same.
					board[row][0] = board[row][0];
					board[row][1] = board[row][1];
					board[row][2] = board[row][2];
				}
			}
			//If left and right column are same, and middle is zero, slide to right. (Double right column and left becomes zero.)
			else if(board[row][0] == board[row][2] && board[row][0] != board[row][1] && board[row][2] != board[row][1] && board[row][1] == 0)
			{
				board[row][2] *= 2;
				board[row][1] = 0;
				board[row][0] = 0;

			}//If all columns are same, combine right and middle into right, slide left to middle.
			else if(board[row][0] == board[row][1] && board[row][1] == board[row][2])
			{
				board[row][2] *=2;
				board[row][1] = board[row][0];
				board[row][0] = 0;
			}//If left and middle are different while right is zero, slide middle to right and left to middle column.
			else if(board[row][0] != board[row][1] && board[row][1] != board[row][2] && board[row][2] == 0)
			{
				board[row][2] = board[row][1];
				board[row][1] = board[row][0];
				board[row][0] = 0;
			}//If middle column equals zero while right column has number, shifts left column into middle.
			else if(board[row][2] != board[row][1] && board[row][1] != board[row][0] && board[row][1] == 0)
			{
				board[row][1] = board[row][0];
				board[row][0] = 0;
			}
		}

		//GENERATE RANDOM 2		
		/*
			Generate x,y int variables and assign random number to them.
			Text x,y coordinate, if coordinate is '0', assign '2' there.
		*/			
		bool generated = false;
		do
		{
			int x,y;
			int random =rand()%9;

			y =	random % 3;
			x =	random / 3;

			if(board[x][y] == 0)
			{
				board[x][y] = 2;
				generated = true;
			}

		}while(generated == false);

} 

void sixteen::moveUp ()
{
		for(int col = 0;col <SIZE;col++)
		{/*
				The following else-if statments check for every possible scenario when moving numbers across the board.
			*/
			if(board[2][col] == board[1][col] && board[2][col] != board[0][col] && board[1][col] != board[0][col])
			{//If middle and bottom rows are the same and there is a different number in the top row, 
			//double the middle row and make the bottom column zero.

				if(board[2][col] == board[1][col] && board[0][col] == 0)
				{//If number in top row is zero, shift everything over.
					board[0][col] = board[1][col] * 2;
					board[1][col] = 0;
					board[2][col] = 0;
				}
				else
				{
				board[1][col] *=2;
				board[2][col] = 0;
				}
			}//If top and middle rows are the same and not equal to bottom row, slide up into top.
			else if(board[0][col] == board[1][col] && board[0][col] != board[2][col] && board[1][col] != board[2][col]/* && board[2][col] != 0*/)
			{//If top and middle row are equal to zero and bottom isn't, slide bottom to top.
				if(board[0][col] == 0 && board[1][col] == 0 && board[2][col] != 0)
				{
					board[0][col] = board[2][col];
					board[1][col] = 0;
					board[2][col] = 0;
				}
				else
				{//Slide up into top.
				board[0][col] *= 2;
				board[1][col] = board[2][col];
				board[2][col] = 0;
				}
			}//If top and bottom rows are the same and middle isn't, everything stays the same.
			else if(board[0][col] == board[2][col] && board[0][col] != board[1][col] && board[2][col] != board[1][col] && board[1][col] != 0)
			{//If top and bottom rows are zero and middle isn't, slide middle row up.
				if(board[0][col] == 0 && board[2][col] == 0 && board[1][col] != 0)
				{
					board[0][col] = board[1][col];
					board[1][col] = board[2][col];
					board[2][col] = 0;
				}
				else
				{//Everything stays the same.
					board[0][col] = board[0][col];
					board[1][col] = board[1][col];
					board[2][col] = board[2][col];
				}
			}
			//If bottom and top rows are same and middle is zero, slides bottom and top to top.
			else if(board[0][col] == board[2][col] && board[0][col] != board[1][col] && board[2][col] != board[1][col] && board[1][col] == 0)
			{
				board[0][col] *= 2;
				board[1][col] = 0;
				board[2][col] = 0;

			}//If all rows are the same, slide up combining top and middle. Middle becomes bottom and bottom is zero.
			else if(board[0][col] == board[1][col] && board[1][col] == board[2][col])
			{
				board[0][col] *=2;
				board[1][col] = board[2][col];
				board[2][col] = 0;
			}//If top row is zero, slide middle and bottom up without combining.
			else if(board[0][col] != board[1][col] && board[1][col] != board[2][col] && board[0][col] == 0)
			{
				board[0][col] = board[1][col];
				board[1][col] = board[2][col];
				board[2][col] = 0;
			}//If middle row is zero and the top and bottom are different, slide bottom row up to middle.
			else if(board[0][col] != board[1][col] && board[1][col] != board[2][col] && board[1][col] == 0)
			{
				board[1][col] = board[2][col];
				board[2][col] = 0;
			}
		}

		//GENERATE RANDOM 2			
		/*
			Generate x,y int variables and assign random number to them.
			Text x,y coordinate, if coordinate is '0', assign '2' there.
		*/		
		bool generated = false;
		do
		{
			int x,y;
			int random =rand()%9;

			y =	random % 3;
			x =	random / 3;

			if(board[x][y] == 0)
			{
				board[x][y] = 2;
				generated = true;
			}

		}while(generated == false);
}

void sixteen::moveDown ()
{
		for(int col = 0;col <SIZE;col++)
		{//If top and middle row are the same and bottom isn't zero, combine into middle, top is now zero.
		if(board[1][col] == board[0][col] && board[1][col] != board[2][col] && board[0][col] != board[2][col])
			{
				//If top and middle are same and bottom is middle. Combine, slide down to bottom.
				if(board[1][col] == board[0][col] && board[2][col] == 0)
				{
					board[2][col] = board[1][col] * 2;
					board[0][col] = 0;
					board[1][col] = 0;
				}
				else
				{//Combine into middle, top is now zero.
					board[1][col] *=2;
					board[0][col] = 0;
				}
			}
			//If middle and bottom row are same, slide down.
			else if(board[1][col] == board[2][col] && board[1][col] != board[0][col] && board[2][col] != board[0][col])
			{//If middle row and bottom are both zero, slide top down.
				if(board[1][col] == 0 && board[2][col] == 0 && board[0][col] != 0)
				{
					board[2][col] = board[0][col];
					board[0][col] = 0;
					board[1][col] = 0;
					//board[2][col] = board[0][col];
				}//If middle and bottom are same, combine.
				else if(board[1][col] == board[2][col] && board[0][col] != 0 && board[0][col] != board[1][col])
				{
					board[2][col] *=2;
					board[1][col] = board[0][col];
					board[0][col] = 0;
				}
				else
				{
				board[0][col] = 0;
				board[1][col] = board[0][col];
				board[2][col] *= 2;
				}
			}//If top and bottom are same and middle is different, everything stays the same.
			else if(board[0][col] == board[2][col] && board[0][col] != board[1][col] && board[2][col] != board[1][col] && board[1][col] != 0)
			{//If middle is not zero and other rows are, slide down.
				if(board[0][col] == 0 && board[2][col] == 0 && board[1][col] != 0)
				{
					board[0][col] = 0;
					board[2][col] = board[1][col];
					board[1][col] = board[0][col];
				}
				else
				{//Nothing changes.
					board[0][col] = board[0][col];
					board[1][col] = board[1][col];
					board[2][col] = board[2][col];
				}
			}
			//If top and bottom are same and middle is zero, slide down.
			else if(board[0][col] == board[2][col] && board[0][col] != board[1][col] && board[2][col] != board[1][col] && board[1][col] == 0)
			{
				board[0][col] = 0;
				board[1][col] = 0;
				board[2][col] *= 2;

			}//If all rows are same, combine middle with bottom, and slide top down.
			else if(board[0][col] == board[1][col] && board[1][col] == board[2][col])
			{
				board[1][col] = board[0][col];
				board[0][col] =0;
				board[2][col] *= 2;
			}
			else if(board[0][col] != board[1][col] && board[1][col] != board[2][col] && board[2][col] == 0)
			{//If bottom is zero, slide top and middle down, top now zero.
				board[2][col] = board[1][col];
				board[1][col] = board[0][col];
				board[0][col] = 0;
			}
			else if(board[0][col] != board[1][col] && board[1][col] != board[2][col] && board[1][col] == 0)
			{//Slide top to middle if middle is zero.
				board[1][col] = board[0][col];
				board[0][col] = 0; 
			}
		}

	//GENERATE RANDOM 2		
	/*
		Generate x,y int variables and assign random number to them.
		Text x,y coordinate, if coordinate is '0', assign '2' there.
	*/			
		bool generated = false;
		do
		{
			int x,y;
			int random =rand()%9;

			y =	random % 3;
			x =	random / 3;

			if(board[x][y] == 0)
			{
				board[x][y] = 2;
				generated = true;
			}

		}while(generated == false);

}

int sixteen::over() const
{
	//Traverse array to find 16. Meaning WIN!
	for (int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			if(board[i][j] == WIN)
			{
				return 1;
			}
		}
	}
	//Traverse array to find no possible moves
	//Return -1.
	int count=0;
	for (int row = 0; row < SIZE; row++)
	{//Essentially if everything is taken up and nothing can move.
		if(board[row][0] != 0 && board[row][1] != 0 && board[row][2] != 0)
		{
			if(board[row][0] != board[row][1] && board[row][1] != board[row][2])
			{
				if(board[0][row] != 0 && board[1][row] != 0 && board[2][row] != 0)
				{
					if(board[0][row] != board[1][row] && board[1][row] != board[2][row])
					{
						count++;
					}
				}
			}
		}
	}
	if(count == 3)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}



//Output board neatly formatted.
void sixteen::output() const
{	
	for(int row = 0;row<SIZE;row++)
	{
		for(int col = 0;col<SIZE;col++)
		{
			if(board[row][col] == 0)
			{
				cout << right << setw(2) << " - ";
			}
			else
			{
			cout << right << setw(2) << board[row][col] << " ";	
			}
		}

		cout << endl;
	}
}
