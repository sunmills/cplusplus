// Works more or less. 
// Need to learn how to verify types in C++


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string input = " ";

class User {
	int age;
	bool confidence;


	bool isTrue(string a) {
		if (a=="y") { return true; }
		else { return false; }
	}

	bool isInt(){		

	}
	public:
	
	void setAge(int i) { age = i; }
	int getAge() { return age; }	

	void setConfidence(bool i) { confidence = i; }
	void setConfidence(string i) { confidence = isTrue(i); }
	bool getConfidence() { return confidence; }

	

	//	What is the user's age?
	//		Get the user's age and store it.
	void askAge() {

		int i;			
		cout << "Please enter your age: ";
		getline(cin,input);
		stringstream myStream(input);
		if(myStream >> i)
			setAge(i);
		else {
			cout << "Not a good answer. Try again.\n";
			askAge();
		}
	}

	// CONSTRUCT ME!
	User (int a) { // Defines user with age and assumes confidence.
		setAge(a);
		setConfidence(true);
	}
	User (int a, bool b) { // Defines user with age and confidence. DOES NOT VERIFY.
		setAge(a);
		setConfidence(b);
	}
	User () {
		setAge(0);
		setConfidence(false);
		askAge();
		verifyAge();
	}

	//	Lets give the user an opportunity to verify a value.
	//		Ask them if its right, then check if they agreed or not.
	//		If not, call myself recursively until they get it right,
	//			while asking them for a new value..
	void verifyAge() {
		
		bool verify = getConfidence();
		
		if(verify) {
			cout << "Thats great!\nAge Confirmed.\n";
		}
		
		
		else {
			cout << "Are you sure you're "<<getAge()<<" years old?\n";
			string res;
			getline(cin,res);
			setConfidence(res);
			if(!getConfidence()) { askAge(); } // If they're still unsure, ask age.
			verifyAge();
		}
	}
};




// Define the main function.

int main() {

	User user1 = User();
	cout << "#################################";
	User user2 = User(7);
	cout << "#################################";
	User user3 = User(6,true);


	cout << "User 1 is "<<user1.getAge()<<"\n";
	cout << "User 2 is "<<user2.getAge()<<"\n";
	cout << "User 3 is "<<user3.getAge()<<"\n";
	
	return 0;
}

