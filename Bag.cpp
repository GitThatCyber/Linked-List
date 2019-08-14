/*******************************
*  Week 2 lesson:              *
*   a simple Bag class  *
*******************************/

#include <iostream>
#include "Bag.h"

using namespace std;

int size = 0;

/*
* Initializes the list to empty creating a dummy header node.
*/
Bag::Bag()
{
	first = new Node;
	first->next = NULL;
	first->prev = NULL;
	last = new Node;
	last->prev = NULL;
	last->next = NULL;
}

/*
* Destructor. Deallocates all the nodes of the linked list,
* including the header node.
*/
Bag::~Bag()
{
	Node *temp;   
	while (first != NULL)
	{
		temp=first;
		first=first->next;
		delete temp;
	}
}

/*
* Determines whether the list is empty.
*
* Returns true if the list is empty, false otherwise.
*/
bool Bag::isEmpty()
{
	return first->next == NULL;
}

/*
* Prints the list elements in forward order.
*/
void Bag::printFwd()
{
	Node *current = first->next;
	while(current->next != NULL)
	{
		cout << current->info << " ";
		current = current->next;
	}
	cout << endl;
}


/*
* Prints the list elements in reverse order.
*/

void Bag::printRev()
{
	Node *current = last->prev;
	while(current->prev != NULL)
	{
		cout << current->info << " ";
		current = current->prev;
	}
	cout << endl;
}


/*
* Returns size of Bag
*/
int Bag::getSize()
{
	return size;
}

/*
* Clears contents in bag
*/
void Bag::clear()
{
	Node *current = first->next;
	while(current != NULL)
	{
		current->prev->info = NULL;
		current = current->next;
	}
	size = 0;
}


/*
* Adds the element x to the beginning of the list.
*
* x: element to be added to the list.
*/
void Bag::addToFirst(char x)
{
	Node *newNode = new Node;
	Node *temp = new Node;
	newNode->info = x;

	if(first->next == NULL)
	{
		first->next = last;
		last->prev = first;
		newNode->next = first->next;
		first->next = newNode;
		last->prev = newNode->prev;
		newNode->prev = first;
		newNode->next = last;
		last->prev = newNode;
	}
	else
	{
		temp = first->next;
		newNode->next = first->next;
		first->next = newNode;
		newNode->prev = temp->prev;
		newNode->prev = first;
		newNode->next = temp;
		temp->prev = newNode;
	}
	size++;
}

/*
* Adds the element x to the beginning of the list.
*
* x: element to be added to the list.
*/
void Bag::addToLast(char x)
{
	Node *newNode = new Node;
	Node *temp = new Node;
	newNode->info = x;

	if(last->prev == NULL)
	{
		first->next = last;
		last->prev = first;
		newNode->next = first->next;
		first->next = newNode;
		last->prev = newNode->prev;
		newNode->prev = first;
		newNode->next = last;
		last->prev = newNode;
	}
	else
	{
		temp = last->prev;
		newNode->prev = last->prev;
		last->prev = newNode;
		newNode->next = temp->next;
		newNode->next = last;
		newNode->prev = temp;
		temp->next = newNode;
	}
	size++;
}

/*
* Removes the first occurrence of x from the list. If x is not found,
* the list remains unchanged.
*
* x: element to be removed from the list.
*/
void Bag::remove(char x)
{
	Node * old = first->next,
		 * p = first;

	//Finding the address of the node before the one to be deleted
	bool found = false;
	while (old != NULL && !found)
	{
		if (old->info == x) found = true;
		else
		{
			p = old;
			old = p->next;
		}
	}
	
	//if x is in the list, remove it.
	if (found)
	{
		p->next = old->next;
		delete old;
	}
	size--;
}

/*
* Counts elements in Bag
*/
int Bag::count(char item)
{
	int count = 0;
	Node *temp = first->next;
	while(temp->next != last)
	{
		if(temp->info == item)
		{
			count++;
		}
		temp = temp->next;
	}
	return count;
}
