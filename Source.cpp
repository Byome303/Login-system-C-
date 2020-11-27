#include <iostream>

#include <fstream>

#include <string>



using namespace std;					// x is a variable to count how many times the user failed to log in 
int x = 1;

bool LoggedIn()						//initiation of the function to log in 

{

	string username, password, un, pw;

	cout << "Enter username: ";

	cin >> username;

	cout << "Enter password: ";

	cin >> password;


	ifstream read("Login.txt");

	getline(read, un);

	getline(read, pw);


	if (un == username && pw == password)

	{

		return true;

	}

	else

	{

		return false;

	}


}





int main()

{
	int options;

	cout << "1: Register\n2: Login\nYour choice: ";

	cin >> options;

	if (options == 1)

	{

		string username, password;					//Registering the user


		cout << "select a username: ";

		cin >> username;

		cout << "select a password: ";

		cin >> password;



		ofstream file;

		file.open("Login.txt", ios_base::app);


		file << username << endl << password << endl;

		file.close();

		cout << "Successfully Registered" << endl;

		main();

	}


	else  if (options == 2)

	{

		bool status = LoggedIn();					//Logging in 


		if (!status)
			
		{
			cout << "False Login!" << endl;

			if (x<3)
			{
				x++;
				cout << "x=" << x << endl;
				main();
		
			}
			else
			{
				return 0;
			}
		}

		else

		{
			cout << "Successfully logged in!" << endl;

			system("Pause");

			return 1;

		}

	}
}
