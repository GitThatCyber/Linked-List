/*******************************
*  Week 2 lesson:              *
*   a simple Ba class  *
*******************************/

/*
* Linked list node.
*/
struct Node
{
	char info;		//element stored in this node
	Node *next;		//link to next node
	Node *prev;		//link to previous node
};

/*
* Class implementing a linked list.
*/
class Bag
{
public:
	Bag();
	~Bag();
	bool isEmpty();
	void printFwd();
	void printRev();
	int getSize();
	void clear();
	void addToFirst(char);
	void addToLast(char);
	void remove(char);
	int count(char);
	void removeDuplicates();

private:
	Node *first;	//pointer to header (dummy) node
	Node *last;		//pointer to last (dummy) node
};