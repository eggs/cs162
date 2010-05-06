/*
 
 - prompt user to enter three to four categories (max)
 - get expense information from user
	- prompt for purchase cost
	- prompt for description of purchase
	- prompt to make sure amount is correct
	- display expense total per category
 - allow user to find expense
	- search for product title under the category
	- diplsay results
 - keep program running untill user quits
 
*/

#include <iostream>
#include "string.h"
using namespace std;

/**************************************************> Product Struct <*/

struct product {
	float	amount;
	string description;
	string category;
};

/**************************************************> prototypes <*/
char getCommand();
void addNewProduct(product * products, int & counter);
void listProducts(const product * products, const int counter);
bool checkInput(const product & prod);
void displayProduct(const product & product);
void displayByCategory(const product * products, int count);

/**************************************************> main <*/
int main () {
	bool running = true;
	product products[100]; //user is allowed to enter a maximum of 100 hundred products.
	int prodCounter = 0;
	while(running)
	{
		char command = getCommand();
		switch(command)
		{
			case 'q':
				running = false;
				break;
			case 'n':
				addNewProduct(products, prodCounter);
				break;
			case 'l':
				listProducts(products, prodCounter);
				break;
			case 'd':
				displayByCategory(products, prodCounter);
				break;
			default:
				__asm int 3
				running = false;
		}
	}
}

/**************************************************> getCommand <*/
char getCommand() {
	char command;
	cout	<< "Enter command (q=quit, n=new, l=list, d=display by category):  " << endl;
	cin		>> command;
	cin.clear();
	return command;
}

void displayByCategory(const product * products, int count)
{
	string category;
	cout << "Enter the category of products to view" << endl;
	cin >> category;
	for(int i = 0; i < count; ++i)
	{
		if(products[i].category.compare(category) == 0)
			displayProduct(products[i]);
	}
}


void addNewProduct(product * products, int & counter)
{
	bool inputting = true;
	string description;
	string category;
	float amount;
	product prod;
	while(inputting)
	{
		cout << "Enter the description of the purchase." << endl;
		getline(cin, description);
		cout << "Enter the price of the purchase." << endl;
		cin >> amount;
		cout << "Enter the category this purchase belongs to." << endl;
		getline(cin, category);
		
		prod.description = description;
		prod.amount = amount;
		prod.category = category;
		
		inputting = checkInput(prod);
	}
	
	products[counter] = prod;
	counter++;
}

bool checkInput(const product & prod)
{
	char correct;
	cout << "The product entered has the following information:  " << endl;
	displayProduct(prod);
	cout << "Is this correct (y / n)?" << endl;
	cin >> correct;
	cin.clear();
	return correct == 'n';
}

void displayProduct(const product & product)
{
	cout << "Description:  " << product.description << std::endl;
	cout << "Amount:  " << product.amount << endl;
	cout << "Category:  " << product.category << endl;
}

void listProducts(const product * products, const int counter)
{
	for(int i = 0; i < counter; ++i)
	{
		displayProduct(products[i]);
		cout << "-----------------------------" << endl;
	}
}

/**************************************************> handler <*/

//void handler(char command) {
//	product item[100];
//	char *pCommand = &command;
//	int counter = 0;
//	float &amount		= item.amount;
//	char  &descript		= item.descript[101];
//	char  &cat			= item.cat[26];
//	
//	if (*pCommand == 'n') {
//		cout << "Enter the purchase of your purchase\n";
//		cout.setf(ios::fixed,ios::floatfield); cout.precision(2); cout.setf(ios::showpoint);
//		cin		<< item[counter].amount<<endl;
//		//cin		>> amount; cin.ignore(100,'\n');
//		cout	<< "You enetered: " << amount <<endl;
//		
//		cout	<< "Enter the description\n";
//		cin.get(&descript, 101, '\n'); cin.ignore(101,'\n');
//		cout	<< "You enetered: " << &descript <<endl;
//		
//		cout	<< "Enter the category\n";
//		cin.get(&cat, 26, '\n'); cin.ignore(101,'\n');
//		cout	<< "You enetered: " << &cat <<endl;
//		
//		
//		getCommand();
//	} 
//	
//	else if (*pCommand == 'l') {
//		listProd();
//	}
//
//	
//	
//	
//}
//
///*******************************************> AddToList <*/
//
//void addToList(float a, char b, char c) {
//
//
//}
//
///*******************************************> listProd <*/
//
//void listProd() {
//
//}


