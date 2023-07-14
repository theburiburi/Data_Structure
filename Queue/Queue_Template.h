#include <iostream>
#include <cstdlib>
using namespace std;
void Error(string s) { cerr << s; exit(-1); }
const int QUEUE_SIZE = 100;
template <typename Data>


class QueueTemplate {
    Data data[QUEUE_SIZE];
    int length;
    int front, rear;
public:
    QueueTemplate() { front = 0; rear = -1; length = 0; }

    void Insert(Data d) {
        if (IsFull());
        else {
            rear = (rear + 1) % QUEUE_SIZE;
            data[rear] = d; length++;
        }
    }

    Data Delete() {
        if (IsEmpty());
        else{
            Data out = data[front];
            front = (front + 1) % QUEUE_SIZE; length--;
            return out;
        }
    }

    Data Peek() {
        if (IsEmpty()) break;
        return data[front];
    }

    bool IsEmpty() { return length == 0; }
    bool IsFull() { return length == QUEUE_SIZE ; }
    void PrintQueueTemplate() {
        for (int i = 0; i < length; i++) {
            cout << data[(front + i) % QUEUE_SIZE];
            cout << " ";
        }
        cout << endl;
    }
    int Length() { return length; }
};