#include <iostream>
#include <cstdlib>
using namespace std;
void Error(string s) { cerr << s; exit(-1); }
const int STACK_SIZE = 100;
template <typename Data>


class StackTemplate {
    Data data[STACK_SIZE];
    int top;
public:
    StackTemplate() { top = -1; }

    void Push(Data d) {
        if (IsFull()) Error("Stack is full");
        data[++top] = d;
    }

    Data Pop() {
        if (IsEmpty()) Error("Stack is empty");
        return data[top--];
    }

    Data Peek() {
        if (IsEmpty()) Error("Stack is full");
        return data[top];
    }

    bool IsEmpty() { return top == -1; }
    bool IsFull() { return top == STACK_SIZE - 1; }
    void PrintStack() {
        for (int i = 0; i <= top; i++) {
            cout << data[i] << endl;
        }
        cout << endl;
    }
    int Length() { return top + 1; }
};