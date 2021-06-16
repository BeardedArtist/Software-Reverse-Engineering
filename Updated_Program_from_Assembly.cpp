//============================================================================
// Name        : Updated Program.cpp
// Author      : Zane Brown
// Description : Project
//============================================================================

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int bobOption = 1;
int sarahOption = 2;
int amyOption = 1;
int johnnyOption = 1;
int carolOption = 2;


void CheckUserPermissionAccess()
{

	int userPassInput;
	string usernameInput;
	bool CorrectPassword = false;


	// Add username variables to check for to increase security for the program
	// Also need to add passwords for each user.
	// (**FIXED -- Added usernames for each user as well as passwords for the respective user. This will increase this function's security.**)

	string user1 = "Bob Jones";
	string user2 = "Sarah Davis";
	string user3 = "Amy Friendly";
	string user4 = "Johnny Smith";
	string user5 = "Carol Spears";

	int BobPass = 9874;
	int SarahPass = 3478;
	int AmyPass = 2991;
	int JohnnyPass = 5503;
	int CarolPass = 2814;

	cout << "Enter your username: " << endl;
	getline(cin, usernameInput); // (**FIXED -- Added getline() to take in user's full name instead of only one word.**)
	cout << "Enter your password: " << endl;
	cin >> userPassInput;

	// The following cin inputs and if statements do not check for usernames. This means any user can easily access the program.
	// Only one password is being used for this program. This is highly dangerous and will need to be changed to increase security.
	// Both solutions can be done by adding a series of IF/ELSE statements to check both username and passwords

	while (CorrectPassword == false) //(**FIXED -- Added while loop to entire if/else block to manage if password matches TRUE. Else to continue loop if false.**)
	{
		if (usernameInput == user1 && userPassInput == BobPass)
			{
				cout << "password accepted" << endl;
				cout << endl;
				CorrectPassword = true;
			}
			else if (usernameInput == user2 && userPassInput == SarahPass)
			{
				cout << "password accepted" << endl;
				cout << endl;
				CorrectPassword = true;
			}
			else if (usernameInput == user3 && userPassInput == AmyPass)
			{
				cout << "password accepted" << endl;
				cout << endl;
				CorrectPassword = true;
			}
			else if (usernameInput == user4 && userPassInput == JohnnyPass)
			{
				cout << "password accepted" << endl;
				cout << endl;
				CorrectPassword = true;
			}
			else if (usernameInput == user5 && userPassInput == CarolPass)
			{
				cout << "password accepted" << endl;
				cout << endl;
				CorrectPassword = true;
			}
			else //(**FIXED -- While loop removed in ELSE due to infinite loop errors being caused when taking in multiple username and passwords.**)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Line 66 and 67 are used to clear the character input. If not done, an infinite loop of the below output happens.
				cout << "Invalid Username or Password. Please try again" << endl;
				cout << "Enter your username: " << endl;
				getline(cin, usernameInput);
				cout << "Enter your password: " << endl;
				cin >> userPassInput;
			}
	}
	return;
}

// If this program is only accessed by employees, then the ChangeCustomerChoice() function is fine.
// Else if this program is also used by customers, this is very dangerous to allow them to change any customer's choice.

void ChangeCustomerChoice()
{
	int clientNumber;
	int clientNewService;

	cout << "You chose 2" << endl;
	cout << "Enter the number of the client that you wish to change" << endl;
	cin >> clientNumber;
	cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
	cin >> clientNewService; // Can enter a number more than 1 or 2. This will cause the customer choice to change to any number.
                             //(**FIXED -- encased the IF/ELSE statements for changing service within another IF/ELSE statement checking if only 1 or 2 was chosen.**)
	cout << endl;            //(**FIXED -- added endline to improve readability**)

	if (clientNewService == 1 || clientNewService == 2) // This will check if user only enters 1 or 2. Else it will output error message.
	{
		if (clientNumber == 1)
			{
				bobOption = clientNewService;
			}
			else if (clientNumber == 2)
			{
				sarahOption = clientNewService;
			}
			else if (clientNumber == 3)
			{
				amyOption = clientNewService;
			}
			else if (clientNumber == 4)
			{
				johnnyOption = clientNewService;
			}
			else if (clientNumber == 5)
			{
				carolOption = clientNewService;
			}
	}
	else
	{
		cout << "**Invalid service choice. Please choose 1 or 2.**" << endl; //Error message if service choice does not match 1 or 2.
		cout << endl;
	}

	return;
}


void DisplayInfo()
{
	cout << "You chose 1" << endl;

	cout << "   Client's Name   Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
	cout << "1. Bob Jones selected option " << bobOption << endl;
	cout << "2. Sarah Davis selected option " << sarahOption << endl;
	cout << "3. Amy Friendly selected option " << amyOption << endl;
	cout << "4. Johnny Smith selected option " << johnnyOption << endl;
	cout << "5. Carol Spears selected option " << carolOption << endl;
	cout << endl; //(**FIXED-- added endline to improve readability.**)

	return;

}


int main() {

	float userSelection; // Can cause an integer overflow if user enters integer above C++ max int causing an infinite display menu bug.
                         // This is also caused if a float is entered.
	                     //(**FIXED -- IF/ELSE now checking for specifically 1,2,3 or 4.**)
	                     //(**Changed to Float to stop infinite display loop if float input.**)

	cout << "Hello! Welcome to our Investment Company" << endl;

	CheckUserPermissionAccess();

	while (userSelection != 3)
	{
		cout << "What would you like to do?" << endl;
		cout << "DISPLAY the client list (enter 1)" << endl;
		cout << "CHANGE a client's choice (enter 2)" << endl;
		cout << "Print Creators Name (enter 4)" << endl;
		cout << "Exit the program.. (enter 3)" << endl;
		cin >> userSelection;

		if (userSelection == 1 || userSelection == 2 || userSelection == 3 || userSelection == 4) //(**FIXED -- Program now checks for only 1,2,3 or 4. Else error is output.**)
		{
			if (userSelection == 1)
			{
				DisplayInfo();
			}
			else if (userSelection == 2)
			{
				ChangeCustomerChoice();
			}
			else if (userSelection == 4)
			{
				cout << "Zane Brown whom belongs to the Slytherin house made this." << endl;
			}
		}
		else
		{
			cout << "User entered invalid choice. Please choose 1, 2, 3 or 4." << endl;
			break; //(**FIXED -- added break to stop infinite display loop.**)
		}

	}

	return 0;
}
