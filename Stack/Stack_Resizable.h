#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Data;
void Error(string s) { cerr << s; exit(-1); }

class StackResizable {
	Data* data;
	int top;
	int stackSize;
	bool IsFull() { return top == stackSize - 1; }
public:

	StackResizable() { top = -1; }

	bool IsEmpty() { return top == -1; }

	void Push(Data d) {
		if (IsFull())IncreaseStackSize();
		data[++top] = d;
	}
		
	Data Pop()
	{
		if (IsEmpty())Error("Stack is empty");
		return data[top--];
	}

	Data Peek() {
		if (IsEmpty())Error("Stack is empty");
		return data[top];
	}

	void StackRes() {
		top = -1; stackSize = 3;
		data = new Data[stackSize];
		cout << "Stack size = " << stackSize << endl;
	}

	void IncreaseStackSize() {
		Data* old = data;
		stackSize *= 3;
		data = new Data[stackSize];
		for (int i =0; i <= top; i++){
			data[i] = old[i];
		}
		delete[] old;
		cout << "Stack size = " << stackSize << endl;
	}
};