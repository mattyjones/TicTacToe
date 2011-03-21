/*------------------------------------------------------------------------/
 *																		  /
 *Project: Project 1 Tic Tac Toe										  /
 *File: TicTacToeMain.cpp												  /
 *																		  /
 *Abstract:																  /
 *	 This is the main file for the program								  /
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

int main()

{
		
			TicTacToe program;								// this is the instance I created for this program
			
			cout << "Welcome to Tic Tac Toe" << endl;		// this greets the player
		
			program.start_game(1);							// this will take the name of player one
			
			program.start_game(2);							// this will take the name of player two
	
			program.clear_board();							// this will clear the board and initalize it to ' ' and set the inital GameState condition to 'c'
	
			program.play_game();							// the is the control function and calls other functions depending on the various game conditions

		
	
	return 0;
}