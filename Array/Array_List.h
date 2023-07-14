#include <iostream>
#include <cstdlib>

using namespace std;
const int LIST_SIZE = 1000;
const int SEARCH_FAILED = -1000;

typedef int Data;
void Error(string s) { cerr << s; exit(-1); }

class ArrayList 
{
protected:
	Data data[LIST_SIZE];
	int length;
	virtual int Key(Data d) { return d; }
public:
	ArrayList() { length = 0; }

	void CheckPos(int pos, int maxPos)
	{
		if (pos <0 || pos>maxPos)
			Error("Illegal position");
	}

	void InsertPos(int pos, Data d)
	{
		CheckPos(pos, length);
		if (IsFull()) Error("List is full");
		for (int i = length; i > pos; i--) {
			data[i] = data[i - 1];
		}
		data[pos] = d; length++;
	}

	Data DeletePos(int pos)
	{
		CheckPos(pos, length - 1);
		Data d = data[pos];
		for (int i = pos; i < length; i++) {
			data[i] = data[i + 1];
		}
		length--;  return d;
	}

	void DeleteAll(int key)
	{
		for (int i = 0; i < length; i++) {
			if (Key(data[i]) == key) {
				for (int j = i; j < length; j++) {
					data[j] = data[j + 1];
				}
				i = 0;
				length--;
			}
		}
	}

	Data PeekPos(int pos) 
	{
		CheckPos(pos, length - 1);
		return data[pos];
	}

	Data Search(int key) 
	{
		for (int i = 0; i < length; i++) {
			if (Key(data[i]) == key) return data[i];
		}
		cout << key << "is not found" << endl;
		return SEARCH_FAILED;
	}
			
	void PrintList()
	{
		for (int i = 0; i < length; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}

	bool IsEmpty() { return length == 0; }
	bool IsFull() { return length == LIST_SIZE; }
	int Length() { return length; }
};