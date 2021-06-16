//============================================================================
// Name        : Program From Assembly.cpp
// Author      : Zane Brown
// Description : Project
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int bobOption = 1;
int sarahOption = 2;
int amyOption = 1;
int johnnyOption = 1;
int carolOption = 2;


void CheckUserPermissionAccess()
{
	// Add the following username variables to check for to increase security for the program
	// Also need to add passwords for each user.

	// string user1 = "Bob Jones";
	// string user2 = "Sarah Davis";
	// string user3 = "Amy Friendly";
	// string user4 = "Johnny Smith";
	// string user5 = "Carol Spears";

	int userPassInput;
	string usernameInput;
	int Pass = 123;
	// more passwords needed to improve security

	cout << "Enter your username: " << endl;
	cin >> usernameInput;
	cout << "Enter your password: " << endl;
	cin >> userPassInput;

	// The following cin inputs and if statements do not check for usernames. This means any user can easily access the program.
	// Only one password is being used for this program. This is highly dangerous and will need to be changed to increase security.
	// Both solutions can be done by adding a series of IF/ELSE statements to check both username and passwords
	// Both names are not taken for user's full name. Will need to add functionality to include both names

	if (userPassInput != Pass)                                           // Need to update the IF statement to take username/password conditions and ELSE to take while loop.
	{                                                                    // While loop can accidentally cause an infinite loop when inputing correct name SECOND time after first mistake.
		while (userPassInput != Pass) {
			cout << "Invalid Password. Please try again" << endl;
			cout << "Enter your username: " << endl;
			cin >> usernameInput;
			cout << "Enter your password: " << endl;
			cin >> userPassInput;
		}

	}
	else
	{
		cout << "password accepted" << endl;  // **This is used for testing purposes only. Not included in the Assembly code.**
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

	if (clientNumber == 1)  // Needs an IF/ELSE statement encasing the following IF/ELSE statements in order to check for selection of 1 or 2.
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
    // Needs an extra end line to improve readability
	return;

}


int main() {

	int userSelection; // Can cause an integer overflow if user enters integer above C++ max int causing an infinite display menu bug.
                       // This is also caused if a float is entered.
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
                                                             // Filter needed to check for values 1,2,3 or 4. Else error message needs to be displayed.
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

	return 0;
}
