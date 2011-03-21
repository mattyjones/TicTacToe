/*------------------------------------------------------------------------/
 *																		  /
 *Project: Project 1 Tic Tac Toe										  /
 *File: TicTacToe.h														  /
 *																		  /
 *Abstract:																  /
 *	 This is the header file for the Tic Tac Toe program				  /
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

#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_

#include <cstring>
#include <iostream>

class TicTacToe
{

	public:

		//TicTacToe();											// default constructor
		//~TictTacToe();										// default destructor
		
		void win_draw();										// this function checks for a win condition and also controls the counter for a draw condition
		void clear_board();										// this function with initalize the board to all empty spaces and sets up m_cGameSate
		void start_game(int);									// this will let the players input their names
		void print_board();										// this function will print the board wherever it stands in the game
		void player_turn(int);									// this function is player's turn 
		void play_again();										// this function will call the program again to allow the players to play again after game completion
		void win_game(char[9]);									// this functions handles a win condition
		void draw_game();										// this functions handles a draw condition
		void play_game();										// this functions controls the pace of the game and calls other functions to handle different conditions
		void name_check(char[9], int);							// this functions checks to see if the player entered a name larger then the array set for it
			
	private:

		char m_cTicTacToeBoard[3][3];							// this is the array that will hold the board
		char m_p1_cName[9];										// this is player one's name
		char m_p2_cName[9];										// this is player two's name
		char m_cGameState;										// this will hold the currrent state of the game, either (w)in, (d)raw, or (c)ontinue

		int m_x_location;										// this holds the x location
		int m_y_location;										// this holds the y location
		int m_iCounter;											// this will hold the counter for a draw condition
			
};

#endif
	