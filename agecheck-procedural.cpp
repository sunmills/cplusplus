#include <iostream>
using namespace std;

// Procural approach to asking a user their age.

// Define functions

//	What is the user's age?
//		Get the user's age and return it.
int askAge() {
		
	int i;
	cout << "Please enter your age: ";
	cin >> i;
	return i;
}

//	Lets give the user an opportunity to verify a value.
//		Ask them if its right, then check if they agreed or not.
//		If not, call myself recursively until they get it right.
bool verifyAge(int age) {
	
	
	cout << "Are you sure you're "<<age<<" years old?\n";
	bool verify;
	cin >> verify;

	if(verify) { cout << "Thats great!\n"; }
	else {
		// Recursively call me
		verifyAge(askAge());
	}

	return 0;
		
}


// Define the main function.

int main() {

	verifyAge(askAge());

	return 0;
}

