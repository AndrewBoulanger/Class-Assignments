#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <fstream>

using namespace std;

char getUsersChoice();
char getCompChoice();
char pickWinner(char, char);

int main()
{
	bool GameIsRunning = true;
	char user_choice;
	char comp_choice;
	char input;
	char result;

	int wins = 0;
	int ties = 0;
	int losses = 0;

	srand(time(0));

	//bool validUsername, validPassword = false;
	//string userInput;
	//const int NAME_MIN_LENGTH = 8;
	//
	//do //get username, check if it exists and ask for password, or make a new user
	//{
	//	do //make sure the username is a valid length
	//	{
	//		cout << "\nPlease enter a username. (must be at least 8 characters long): ";
	//		cin >> userInput;
	//
	//		if (userInput.length() < NAME_MIN_LENGTH) 
	//		{
	//			cout << "\nUsername is too short, please try again" << endl;
	//			validUsername = false;
	//		}
	//		else
	//			validUsername = true;
	//	} while (validUsername == false);

	//	//check if user name doesnt exist
	//		//if so have them create a password, then create a new user and set validPassword = true
	//		//else have them enter a password in a do while loop
	//			//check if the password is correct, loop until it is, or let them return to the earlier menu with a break if they type back

	//} while (validPassword == false);

	//ask the player if they wanna play against a computer or another person

	while (GameIsRunning)
	{
		//user's move
		user_choice = getUsersChoice();

		//computer's move
		comp_choice = getCompChoice();

		// declare a winner
		result = pickWinner(user_choice, comp_choice);

		switch (result)
		{
		case 'w':
			wins++;
			break;
		case 't':
			ties++;
			break;
		case 'l':
			losses++;
			break;
		}
		cout << "\nCurrent score:\n";
		cout << "Wins:    " << wins << endl;
		cout << "Ties:    " << ties << endl;
		cout << "Losses:  " << losses << endl;

		// suggest  user  play another round. any input besides "y", or "Y" will break out of the loop. 
		cout << endl << "Enter Y to Play Again" << endl;
		cin >> input;

		if (toupper(input) != 'Y')
			GameIsRunning = false;

		system("cls");
	}
	// main function return
	return 0;

}

//functions
char pickWinner(char user_move, char comp_move)
{
	switch (user_move) {
	case 'r':
		switch (comp_move) {
		case 'r':
			cout << "User: Rock" << endl;
			cout << "Computer: Rock" << endl;
			cout << endl;
			cout << "It's a tie!" << endl;
			return 't';
		case 'p':
			cout << "User: Rock" << endl;
			cout << "Computer: Paper" << endl;
			cout << endl;
			cout << "Computer Wins! Paper Beats Rock!" << endl;
			return 'l';
		case 's':
			cout << "User: Rock" << endl;
			cout << "Computer: Scissor" << endl;
			cout << endl;
			cout << "User Wins! Rock Beats Scissors!" << endl;
			return 'w';
		}
		break;
	case 'p':
		switch (comp_move) {
		case 'r':
			cout << "User: Paper" << endl;
			cout << "Computer: Rock" << endl;
			cout << endl;
			cout << "User Wins! Paper Beats Rock!" << endl;
			return 'w';
		case 'p':
			cout << "User: Paper" << endl;
			cout << "Computer: Paper" << endl;
			cout << endl;
			cout << "It's a tie!" << endl;
			return 't';
		case 's':
			cout << "User: Paper" << endl;
			cout << "Computer: Scissors" << endl;
			cout << endl;
			cout << "Computer Wins! Scissors Beats Paper!" << endl;
			return 'l';
		}
		break;
	case 's':
		switch (comp_move) {
		case 'r':
			cout << "User: Scissors" << endl;
			cout << "Computer: Rock" << endl;
			cout << endl;
			cout << "Computer Wins! Rock Beats Scissors!" << endl;
			return 'l';
		case 'p':
			cout << "User: Scissors" << endl;
			cout << "Computer: Paper" << endl;
			cout << endl;
			cout << "User Wins! Scissors Beats Paper!" << endl;
			return 'w';
		case 's':
			cout << "User: Scissors" << endl;
			cout << "Computer: Scissors" << endl;
			cout << endl;
			cout << "It's a tie!" << endl;
			return 't';
		}
	default:
		cout << "Invalid move. No score" << endl;
		break;

	}
}

char getCompChoice()
{
	// divide the random intgr by 3 and assign its remainder to a variable.
	int randomNumber = rand() % 3;

	// assign a move to the computer's random number.
	if (randomNumber == 0)
		return 'r';
	else if (randomNumber == 1)
		return 'p';
	else
		return 's';
}

char getUsersChoice()
{
	string choice;
	string temp;

		// get the user's move
		cout << "Enter your move (Rock, Paper, or Scissors (or r,s or p)):" << endl;
		cin >> choice;
		cout << endl;

		//makes the first letter lowercase (but wow that was annoying to figure out annoying)
		choice[0] = tolower(choice[0]);
	

		while( choice.length() > 1 && !(choice == "rock" || choice == "paper" || choice == "scissors") )
		{
			cout << "Please enter a valid move" << endl;
			cin >> choice;
			choice[0] = tolower(choice[0]);
			cout << endl;
		}
		
		return choice[0];
	
}
