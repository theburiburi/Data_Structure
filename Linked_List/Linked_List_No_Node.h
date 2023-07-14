#include <iostream>

using namespace std;

typedef int Data;

class LinkedList
{
    Data data;
	LinkedList* next;
	
public:
	LinkedList(int d = 0) { data = d; next = NULL; }

	void PrintList()
	{
		if (next == NULL) cout << "=>[null]\n";
		else { cout << " => " << next->data; next->PrintList(); }
	}

	void InsertRear(Data d)
	{
		if (next == NULL) next = new LinkedList(d);
		else next->InsertRear(d);
	}


	Data Search(int key)
	{
		if (next == NULL) cout << "Not Found\n";
		else if (next->data == key)
			cout << "Found\n";
		else next->Search(key);
	}


};