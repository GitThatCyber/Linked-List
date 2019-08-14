/*******************************
*  Week 2 lesson:              *
*   a simple LinkedList class  *
*******************************/

#include <iostream>
#include "Bag.h"

using namespace std;

int main()
{
	Bag myList;
	int count = 0;
	char x;

	cout << "Enter five characters: " << endl;

	while(count < 5)
	{
		cin >> x;
		cout << "You entered: " << x << endl;
		myList.addToLast(x);
		count++;
	}

	cout << endl;

	cout << "1 - Is it empty?" << endl;
	cout << "2 - Print list" << endl;
	cout << "3 - Get list size" << endl;
	cout << "4 - Clear list" << endl;
	cout << "5 - Add item to bag" << endl;
	cout << "6 - Remove item from bag" << endl;
	cout << "7 - Count items" << endl;
	cout << "8 - Exit" << endl;
	

	int option;

	//Loop to test the LinkedList class methods
	do 
	{
		cout << endl << "Enter your choice: ";
		cin >> option;

		switch(option)
		{
		case 1:
			if (myList.isEmpty()) cout << "Bag is empty"<< endl;
			else cout << "Bag is not empty" << endl;
			break;

		case 2:
			cout << "Elements in bag: ";
			myList.printFwd();
			break;

		case 3:
			cout << "Bag size: ";
			cout << myList.getSize();
			cout << " items" << endl;
			break;

		case 4:
			cout << "Bag emptied!" << endl;
			myList.clear();
			break;
		
		case 5:
			cout << "Enter a character to be added: ";
			cin >> x;
			myList.addToFirst(x);
			break;

		case 6:
			cout << "Enter an element to delete: ";
			cin >> x;
			myList.remove(x);
			break;
		
		case 7:
			cout << "Enter an element to count the occurances: ";
			cin >> x;
			cout << endl << "Number of occurances: " << myList.count(x) << endl;
			break;

		case 8:
			cout << "All done!" << endl;
			break;

		default: cout << "Invalid choice!" << endl;
		}

	} while (option != 8);

	return 0;
}