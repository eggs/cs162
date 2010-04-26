/*
 Tip Calculator App by Jonathan Eggiman
 Class - CS162 Fant
 
 Program Algorithm
 - Prompt user for bill amount
	- display amount for user
 - Prompt user for Sales tax
	- display response
 - Prompt service ratings and give three options
	- allow user to enter 0 tip if wanted
	- display tip amount
	- display the tip and meal total
	- ask the user if they are happy with the result
		- if user selects no, prompt for custom percentage
 - Calculate final tip results and display the entire cost
 - Prompt user and allow the program to run again
 - If user declines end the program
*/ 

#include <iostream>
using namespace std;

float mealCost(float cost);
void continueApp(char ans);

int main () {
	mealCost('cost');
	continueApp('a');
	return 0;
}

float mealCost(float cost){
	float tax;
	char satisfaction;
	float customTip;
	unsigned int tip;
	float mealAndTax;
		
	//Start gathering info for bill
	cout << ">> Please enter the bill amount \n";

	// handler for user input
	cout.setf(ios::fixed,ios::floatfield); cout.precision(2); cout.setf(ios::showpoint);
	cin >> cost;
	cin.ignore(100,'\n');
	
	// while loop protects against char entery entry
	while (cin.fail()) {
		cout << ">> bad data\n";
		cin.clear();
		cout << ">> Please enter the bill amount again \n";
		cin.ignore(100,'\n');
		
		cin >> cost;
		cin.ignore(100,'\n');
	}
		
	cout << ">> The cost of your meal was $" << cost <<endl;
	
	//tax logic
	cout << ">> What is the sales tax in your state? (If in Oregon, enter 0)\n";

	// handler for user input
	cout.setf(ios::fixed,ios::floatfield); cout.precision(2); cout.setf(ios::showpoint);
	cin >> tax; cin.ignore(100,'\n');
	cout << ">> Ok, " <<tax << " percent was your response.\n";
	
	// while loop protects against char entery
	while (cin.fail()) {
		cout << ">> bad data\n";
		cin.clear();
		cout << ">> Please enter the sales tax again \n";
		cin.ignore(100,'\n');
		
		cin >> tax;
		cin.ignore(100,'\n');
	}
	
	if (tax > 0) {
		tax = (tax/100);
		cout << tax*100 << " percent" <<endl;
	}
	
	// Add the meal cost and tax if applied
	mealAndTax = cost + (tax*cost);
	
	cout << ">> Rate your service\n";
	cout << ">> Enter 1 for 15% (not great), 2 for 20%, and 3 for 25% (really good)\n";
	cout << ">> If you do not want to leave no tip, enter '0'"<<endl;
	cin >> tip; cin.ignore(5,'\n');
	// while loop protects against char entery
	while (cin.fail()) {
		cout << ">> bad data\n";
		cin.clear();
		cout << ">> Please enter the bill amount again \n";
		cin.ignore(100,'\n');
		
		cin >> tip;
		cin.ignore(100,'\n');
	}
		
	//calculate the ratings that the user wants to tip
	if ( tip == 1) {
		tip = 15.00;
	} else if (tip == 2) {
		tip = 20.00;
	} else if (tip == 3) {
		tip = 25.00;
	} else {
		tip = 0;
	}
	cout << ">> $"<<  (tip*mealAndTax)/100 << " is the amount you'll be tipping."<<endl; // calculate tip amount
	cout << ">> $"<<mealAndTax + ((tip*mealAndTax)/100)<< " is the cost of your final meal."<<endl;
	cout.precision(2);
	
	
	cout << ">> Are you happy with the tip amount?"<<endl;
	cout << ">> Please enter either 'y' or 'n'"<<endl;
	cin >> satisfaction;
	cin.ignore();
	
	// use conditional to either proceed or calculate a custom tip
	while (!(satisfaction == 'n') && !(satisfaction == 'y')) {
		cout << "Enter either 'y' or 'n"<<endl;
		cin >> satisfaction;
		cin.ignore();
	}
	
	// enter custom tip amount
	if (satisfaction == 'n') {
		cout << ">> The scale is based on 15\% for 1, 20\% for 2, and 25\% for 3.\n"
			 << ">> Since you are not happy with the result, enter the percent you wish to tip and it will be calculated:"<<endl;
		cin >> customTip; cin.ignore();
		cout.setf(ios::fixed,ios::floatfield); cout.precision(2); cout.setf(ios::showpoint);
		
		// while loop protects against char entery
		while (cin.fail()) {
			cout << ">> bad data\n";
			cin.clear();
			cout << ">> Please enter the tip amount again \n";
			cin.ignore(100,'\n');
			
			cin >> customTip;
			cin.ignore(100,'\n');
		}
		
		// custom tip details - percentage math
		cout << ">> ok, we'll tip "<< customTip << " percent, which is " << (customTip*mealAndTax)/100 <<endl;
		
		cout.precision(2);
		cout << ">> The bill will be "<<mealAndTax + ((customTip*mealAndTax)/100) <<endl;
	} 
	return 0;
}

//Function for continuing program if the user wants to calculate more tips
void continueApp(char ans) {
	cout << ">> Do you wish to calculate more tips?(Enter 'y' to continue)" <<endl;
	cin >> ans;
	if (ans == 'y') {
		mealCost('cost');
	} else {
		cout << ">> ok byebye"<<endl;
	}
}