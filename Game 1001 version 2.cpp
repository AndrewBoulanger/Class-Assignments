#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

string getUsername(); //asks player for username, only returns if its valid
char getUsersChoice(); //gets user's move, returns it as a char
char getCompChoice(); //randomly picks a char for the computer's move
char pickWinner(char, char, string); //compares both chars in a switch statement and picks the winner. returns a char to figure out how to assign points

int main()
{
	bool GameIsRunning = true;
	char name[256];
	char user_choice;
	char comp_choice;
	char result;

	string password;
	string input;

	ofstream saveFile;
	ifstream readFile;

	int wins = 0;
	int ties = 0;
	int losses = 0;

	srand(time(0));

	string username = getUsername();

	readFile.open(username + ".txt");

	if (!readFile.is_open())
	{
		saveFile.open(username + ".txt");
		cout << "\nPlease create a password\n";
		cin >> input;
		saveFile << input << endl;
		password = input;
	}
	else
	{
		readFile >> password >> wins >> ties >> losses;
		cout << "\nPlease enter your password: ";
		cin >> input;
	}
	
	while(input != password)
	{
		cout << "\nOops, incorrect password\nPlease try again: ";
		cin >> input;
	} 

	while (GameIsRunning)
	{
		system("cls");
		//user's move
		user_choice = getUsersChoice();

		//computer's move
		comp_choice = getCompChoice();

		// declare a winner
		result = pickWinner(user_choice, comp_choice, username);

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
		
		saveFile.open(username + ".txt");
		
		saveFile << password << endl << wins << endl << ties << endl << losses << endl;

		// suggest  user  play another round. any input besides "y", or "Y" will break out of the loop. 
		cout << endl << "Enter Y to Play Again" << endl;
		cin >> input;

		if (input != "y" && input != "Y")
			GameIsRunning = false;
	}
	readFile.close();
	saveFile.close();
	// main function return
	return 0;

}

//functions
string getUsername()
{
	string userInput;
	const int NAME_MIN_LENGTH = 8;

	cout << "\nPlease enter a username. (must be at least 8 characters long): ";
	cin >> userInput;
	while (userInput.length() < NAME_MIN_LENGTH)
	{
		cout << "\nUsername is too short, please try again" << endl;
		cin >> userInput;
	}
	return userInput;
}

char pickWinner(char user_move, char comp_move, string user)
{
	switch (user_move) {
	case 'r':
		switch (comp_move) {
		case 'r':
			cout << user <<": Rock" << endl;
			cout << "Computer: Rock" << endl << endl;
			cout << "It's a tie!" << endl;
			return 't';
		case 'p':
			cout << user << ": Rock" << endl;
			cout << "Computer: Paper" << endl << endl;
			cout << "Computer Wins! Paper Beats Rock!" << endl;
			return 'l';
		case 's':
			cout << user << ": Rock" << endl;
			cout << "Computer: Scissor" << endl << endl;
			cout << user << " Wins! Rock Beats Scissors!" << endl;
			return 'w';
		}
		break;
	case 'p':
		switch (comp_move) {
		case 'r':
			cout << user << ": Paper" << endl;
			cout << "Computer: Rock" << endl << endl;
			cout << user << " Wins! Paper Beats Rock!" << endl;
			return 'w';
		case 'p':
			cout << user << ": Paper" << endl;
			cout << "Computer: Paper" << endl << endl;
			cout << "It's a tie!" << endl;
			return 't';
		case 's':
			cout << user << ": Paper" << endl;
			cout << "Computer: Scissors" << endl << endl;
			cout << "Computer Wins! Scissors Beats Paper!" << endl;
			return 'l';
		}
		break;
	case 's':
		switch (comp_move) {
		case 'r':
			cout << user << ": Scissors" << endl;
			cout << "Computer: Rock" << endl << endl;
			cout << "Computer Wins! Rock Beats Scissors!" << endl;
			return 'l';
		case 'p':
			cout << user << ": Scissors" << endl;
			cout << "Computer: Paper" << endl << endl;
			cout << user << " Wins! Scissors Beats Paper!" << endl;
			return 'w';
		case 's':
			cout << user << ": Scissors" << endl;
			cout << "Computer: Scissors" << endl << endl;
			cout << "It's a tie!" << endl;
			return 't';
		}
	default:
		cout << "Invalid move. No score" << endl;
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
