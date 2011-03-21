/*------------------------------------------------------------------------/
 *																		  /
 *Project: Project 1 Tic Tac Toe										  /
 *File: TicTacToe.cpp													  /
 *																		  /
 *Abstract:																  /
 *	 This file will hold all of the function definations for the program  /
 *																		  /
 *																		  /
 *																		  /
 *																		  /
 *Author:																  /
 *	Matty Jones															  /
 *																		  /
 *List of Initals														  /
 *	mrj		matty jones													  /
 *																		  /
 *when		who		what												  /
 *02-12-09	mrj		started the program									  /
 *02-18-09  mrj		worked on the functions and finished the header file  /
 *02-22-09	mrj		coded basic program with no error checking			  /
 *02-24-09	mrj		added error checking for illegal moves				  /
 *02-28-09	mrj		deleted other player instances, created one instance  /
 *03-01-09	mrj		purged all testing code and added final comments	  /
 *03-02-09	mrj		streamlined functions for eaiser maintainance		  /
 *-----------------------------------------------------------------------*/


#include <iostream>
#include "TicTacToe.h"
#include <cstring>

using namespace std;


/*--------------------------------------/
/ this function let the players	input   /
/ their name and it then sends it to	/
/ Name_Check to make sure it fits in the/
/ array									/
/--------------------------------------*/
void TicTacToe::start_game(int n)
{
	
	cout << "Player " << n << " please enter your name" << endl; // n is the player number

	if (n == 1)
		{
		
			cin >> m_p1_cName;
			name_check(m_p1_cName, n);
		}
	
	if ( n == 2)
		{
		
			cin >> m_p2_cName;
			name_check(m_p2_cName, n);
		}
	
}
	


/*--------------------------------------/
 / this function checks to see if the   /
 / name the player inputed fits in the  /
 / array, if not it recalls the previous/
 / function again						/
 /-------------------------------------*/
void TicTacToe::name_check(char name[9], int n)
{
	int i = 0;																		// this holds the length of the name
	
	i = strlen(name);																// this gets the length of the string
		
	if (i > 8)																		// this checks to see if it will fit in the array
		{
			cout << "please enter only the first 8 letters of your name" << endl;
			start_game(n);															// this calls the function again with the same parameters if it's too long		
		}
	
}


/*--------------------------------------/
/ this function takes the 2D array used /
/ to hold the board and initalizes it   /
/ using a nested loop to all blanks, it /
/ sets the inital GameState to 'c'		/
/--------------------------------------*/
void TicTacToe::clear_board()
{
	for (int i=0; i < 3; i++)			
		for (int j=0; j < 3; j++)
			m_cTicTacToeBoard[i][j] = ' ';
	
	m_cGameState = 'c';		// this sets the inital state of the variable to 'c'
}	


/*--------------------------------------/
/ this function prints the current		/
/ state of the m_cTicTacToeBoard no		/
/ matter where it is in the game		/
/--------------------------------------*/

void TicTacToe::print_board()

{
	
	cout << "   0 " << "  1" << "   " << "2" << endl;																			// header row
	cout << "0  " << m_cTicTacToeBoard[0][0] << " | " << m_cTicTacToeBoard[0][1] << " | " << m_cTicTacToeBoard[0][2] << endl;	// first row of squares
	cout << "  ------------" << endl;																							// row seperator
	cout << "1  " << m_cTicTacToeBoard[1][0] << " | " << m_cTicTacToeBoard[1][1] << " | " << m_cTicTacToeBoard[1][2] << endl;	// second row of squares
	cout << "  ------------" << endl;																							// row seperator
	cout << "2  " << m_cTicTacToeBoard[2][0] << " | " << m_cTicTacToeBoard[2][1] << " | " << m_cTicTacToeBoard[2][2] << endl;	// third row of squares
	
	}


	
/*--------------------------------------/
/ this function gives player a turn and /
/ lets him pick the row and column for  /
/ his next turn, it also does error		/
/ checking against any illegal moves	/
/--------------------------------------*/

void TicTacToe::player_turn(int n)
{
	
	if ( n == 1)																					// this is the player number
		{
				cout << m_p1_cName << " please enter the row of your next move" << endl;			// the row 
				cin >> m_x_location;
			
				//------------------this blocks checks for errors with input of the x value---------//
			
					while ((m_x_location != 0) && (m_x_location != 1) && (m_x_location != 2))		// it will loop until the input is 0, 1, or 2
						{
								cout << "Please enter a valid location between 0 and 2" << endl;
								cin >> m_x_location;
				
						}
				//----------------------------------------------------------------------------------//
			
						
				cout << "Please enter the column of your next move" << endl;						// the column
				cin >> m_y_location;
			
				//------------------this blocks checks for errors with input of the y value---------//
			
					while ((m_y_location != 0) && (m_y_location != 1) && (m_y_location != 2))		// it will loop until the input is 0, 1, or 2
						{
								cout << "Please enter a valid location between 0 and 2" << endl;
								cin >> m_y_location;
						}
				//----------------------------------------------------------------------------------//
			
			
				//--------------this blocks checks for errors with the location of the move---------//
			
					if (m_cTicTacToeBoard[m_x_location][m_y_location] != ' ')						// this checks to make sure there is an open space
						{
				
							cout << "that space is taken, please choose another" << endl;
							player_turn(1);															// this calls the function again and lets the player choose another space
						}
			
				//----------------------------------------------------------------------------------//
					
				m_cTicTacToeBoard[m_x_location][m_y_location] = 'x';								// this will place an x at the specificied location
		}		
	
	if ( n == 2)																					// this is the player number
	{
				cout << m_p2_cName << " please enter the row of your next move" << endl;			// the row 
				cin >> m_x_location;
		
				//------------------this blocks checks for errors with input of the x value---------//
		
					while ((m_x_location != 0) && (m_x_location != 1) && (m_x_location != 2))		// it will loop until the input is 0, 1, or 2
						{
			
							cout << "Please enter a valid location between 0 and 2" << endl;
							cin >> m_x_location;
			
						}
				//----------------------------------------------------------------------------------//
		
		
				cout << "Please enter the column of your next move" << endl;						// the column
				cin >> m_y_location;
		
				//------------------this blocks checks for errors with input of the y value---------//
		
					while ((m_y_location != 0) && (m_y_location != 1) && (m_y_location != 2))		// it will loop until the input is 0, 1, or 2
						{
			
							cout << "Please enter a valid location between 0 and 2" << endl;
							cin >> m_y_location;
						}
				//----------------------------------------------------------------------------------//
		
		
				//--------------this blocks checks for errors with the location of the move---------//
		
				if (m_cTicTacToeBoard[m_x_location][m_y_location] != ' ')							// this checks to make sure there is an open space
					{
			
						cout << "that space is taken, please choose another" << endl;
						player_turn(2);																// this calls the function again and lets the player choose another space
					}
		
				//----------------------------------------------------------------------------------//
		
				m_cTicTacToeBoard[m_x_location][m_y_location] = 'y';								// this will place an x at the specificied location
	}		
	
}



/*--------------------------------------/
/ this function controls the wining of	/ 
/ the game and also contains a counter	/
/ for deciding a draw state				/
/--------------------------------------*/

void TicTacToe::win_draw()
{

		
	m_iCounter = m_iCounter ++;		// this is the counter for the game, everytime it checks for a win it increments by 1
	
	if(((m_cTicTacToeBoard[0][0]!= ' ') && (m_cTicTacToeBoard[0][0] == m_cTicTacToeBoard[1][1]) && (m_cTicTacToeBoard[0][0] == m_cTicTacToeBoard[2][2])) ||
	   ((m_cTicTacToeBoard[2][0]!= ' ') && (m_cTicTacToeBoard[2][0] == m_cTicTacToeBoard[1][1]) && (m_cTicTacToeBoard[2][0] == m_cTicTacToeBoard[0][2])) ||
	   ((m_cTicTacToeBoard[0][0]!= ' ') && (m_cTicTacToeBoard[0][0] == m_cTicTacToeBoard[0][1]) && (m_cTicTacToeBoard[0][0] == m_cTicTacToeBoard[0][2])) ||
	   ((m_cTicTacToeBoard[2][0]!= ' ') && (m_cTicTacToeBoard[2][0] == m_cTicTacToeBoard[2][1]) && (m_cTicTacToeBoard[2][0] == m_cTicTacToeBoard[2][2])) ||
	   ((m_cTicTacToeBoard[0][0]!= ' ') && (m_cTicTacToeBoard[0][0] == m_cTicTacToeBoard[1][0]) && (m_cTicTacToeBoard[0][0] == m_cTicTacToeBoard[2][0])) ||
	   ((m_cTicTacToeBoard[0][1]!= ' ') && (m_cTicTacToeBoard[0][1] == m_cTicTacToeBoard[1][1]) && (m_cTicTacToeBoard[0][1] == m_cTicTacToeBoard[2][1])) ||
	   ((m_cTicTacToeBoard[0][2]!= ' ') && (m_cTicTacToeBoard[0][2] == m_cTicTacToeBoard[1][2]) && (m_cTicTacToeBoard[0][2] == m_cTicTacToeBoard[2][2])))
		
		{		
			m_cGameState = 'w';			// this is for a win condition
			
		}
	
	else if ( m_iCounter == 9)			// the max number of moves that can occue in the game
		{
			m_cGameState = 'd';			// this is for a draw state
						
		}
	
	else
		{ 
			m_cGameState = 'c';			// this just means to continue in the game
				
		}
	
}



/*--------------------------------------/
/ this function controls winning and if /
/ the player would like to play again	/
/--------------------------------------*/

void TicTacToe::win_game(char name[9])
{
	char a;																		// this win hold the answer for playing again
	
		cout << "You win " << name << "." << endl;
		cout << "would you like to play again?" << endl;
		cout << "(y)es or (n)o" << endl; 
		cin >> a;
	
		if (a == 'y')
			{
				play_again();													// this function is called if they would like to play again
			}

		else 
			{
				while ((a != 'y') && (a != 'n'))								// this will continue to loop until the answer with a y or a n
					{
						cout << "Please enter y for yes and n for no" << endl;
						cin >> a;
					}
			}
}




/*--------------------------------------/
 / this function controls a draw state  /
 / the player would like to play again	/
 /--------------------------------------*/


void TicTacToe::draw_game()
	{
			cout << "the game is a draw, please try again" << endl;
		
			char a;
		
		
		cout << "would you like to play again?" << endl;
		cout << "(y)es or (n)o" << endl; 
		cin >> a;
		
		if (a == 'y')
			{
				play_again();
			}
		
		else 
			{
				while ((a != 'y') && (a != 'n'))
					{
						cout << "Please enter y for yes and n for no" << endl;
						cin >> a;
					}
			}
		
}




/*--------------------------------------/
/ this is the control function for the  /
/ the actual game.  It calls all the    /	
/ the other functaions as conditions    /
/ are dictated							/
/--------------------------------------*/

void TicTacToe::play_game()
{
	m_iCounter = 0;											// this is the counter for declaring a draw state
	
	while (m_cGameState == 'c')								// as long as this stays a 'c' the game will continue
			{
				print_board();								// this prints the current state of the board
				player_turn(1);								// this calls the players turn and the number passed it the player
				win_draw();									// this checks for a win or draw and increments the counter by one
		
				if (m_cGameState == 'w')					// this executes if there is a win condition
						{
							win_game(m_p1_cName);			// this sends the player's name to the win finction
						}
		
		
				else if (m_cGameState == 'd')				// this executes if there is a draw condition
						{
							draw_game();
						}
				else										// if player 1 didn't win or draw then player 2 goes and repeats the same process
						{
				 
							print_board();
							player_turn(2);
							win_draw();
		
							if (m_cGameState == 'w')
								{
									win_game(m_p2_cName);
								}
			 
			 
							if (m_cGameState == 'd')
								{
									draw_game();
								}
			 
						}
			}
}




/*--------------------------------------/
/ this function executes if the			/
/ player would like to play again		/
/--------------------------------------*/


void TicTacToe::play_again()
{
	cout << "Welcome to Tic Tac Toe" << endl;
	
	start_game(1);
	
	start_game(2);
	
	clear_board();
	
	play_game();
}