// Needs to be cleaned up a bit, but works!

#include <iostream>
using namespace std;

bool isTrue(string a) {
	if (a=="y") { return true; }
	else { return false; }
}

class User {
	int age;
	bool confidence;
	public:
	
	void setAge(int i) { age = i; }
	int getAge() { return age; }	

	void setConfidence(bool i) { confidence = i; }
	bool getConfidence() { return confidence; }

	

	//	What is the user's age?
	//		Get the user's age and store it.
	void askAge() {

		int i;			
		cout << "Please enter your age: ";
		cin >> i;
		setAge(i);
	}

	// CONSTRUCT ME!
	User (int a) { // Defines user with age and assumes confidence.
		setAge(a);
		setConfidence(true);
//		cout << "(creating user with assumed confidence)\n";
	}
	User (int a, bool b) { // Defines user with age and confidence. DOES NOT VERIFY.
		setAge(a);
		setConfidence(b);
//		cout << "(creating a user with age and confidence)\n";
	}
	User () {
//		cout << "(creating a user from scratch...)\n";
		setAge(0);
		setConfidence(false);
		askAge();
		verifyAge();
	}

	//	Lets give the user an opportunity to verify a value.
	//		Ask them if its right, then check if they agreed or not.
	//		If not, call myself recursively until they get it right.
	void verifyAge() {
		
		bool verify = getConfidence();
//		cout << "Confidence: " << verify << "\n";
		
		if(verify) {
			cout << "Thats great!\nAge Confirmed.\n";
		}
		
		
		else {
			cout << "Are you sure you're "<<getAge()<<" years old?\n";
			string res;
			cin >> res;
//			cout << isTrue(res) << "\n";
			setConfidence(isTrue(res));
			// Recursively call me
	//		cout << "Do you want to recurse?";
	//		string recurse;
	//		cin >> recurse;
	//		if(isTrue(recurse)){ verifyAge();} else { cout << "Done." ;}
			//cout << "RECURSING!\n";
			verifyAge();
		}
	}
};


// Define functions



// Define the main function.

int main() {

	User user1 = User();
	User user2 = User(7);
	User user3 = User(6,true);

	cout << "User 1 is "<<user2.getAge()<<"\n";

	return 0;
}

