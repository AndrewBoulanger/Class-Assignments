#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	ifstream inputFile;
	ofstream outputFile;

	string name;
	string lastName;

	//open the input file
	inputFile.open("Names.txt");
	outputFile.open("Surnames.txt");

	if (inputFile.is_open() && outputFile.is_open())
	{
		for (int i = 1; i <= 6; i++)
		{
			//reads a word from the existing input file
			inputFile >> name;

			cout << "\nPlease enter " << name << "'s last name\n";
			cin >> lastName;
			//saves the word into the new output file
			outputFile << lastName << endl;
		}
	}
	else
		cout << "one of the files failed to open\n";


	inputFile.close();
	outputFile.close();

	system("pause");
	return 0;
}