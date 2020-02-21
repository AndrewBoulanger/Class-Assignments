//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//int main()
//{
//	string name;
//
//	ofstream saveData;
//	saveData.open("Names.txt");
//
//	if (saveData.is_open()) //checks to make sure the file opened successfully
//	{
//		for (int i = 1; i <= 6; i++)
//		{
//			cout << "\nPlease enter name " << i << endl;
//			cin >> name;
//			saveData << name << endl;
//
//		}
//		cout << "Your names were saved\n";
//	}
//
//	else //if the file failed to open print an error statement
//		cout << "error opening file\n";
//
//	saveData.close();
//
//	system("pause");
//	return 0;
//}


//saveData.open("C:\\Temp\\Items.txt");
//if you dont specify a path it'll create the file in the same place as the source code
//dont specify a path for the assignment


//create a separate file for each user, named after the username
//just have savedata.open(username) or maybe (username.txt?) (find a way to add .txt maybe?)