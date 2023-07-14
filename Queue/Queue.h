#include <iostream>
#include <cstdlib>
using namespace std;
void Error(string s) { cerr << s; exit(-1); }
const int QUEUE_SIZE = 100;
template <typename Data1, typename Data2>


class QueueTemplate {
    Data1 data1[QUEUE_SIZE];
    Data2 data2[QUEUE_SIZE];

    int front1, rear1; 
    int length1;
    
    int front2, rear2;
    int length2;

public:
    QueueTemplate() { front1 = 0; rear1 = -1; length1 = 0; front2 = 0; rear2 = -1; length2 = 0;}
    

    void Insert(Data1 d, Data2 f) {
        if (IsFull()) Error("Queue is full");
        rear1 = (rear1 + 1) % QUEUE_SIZE;
        data1[rear1] = d; length1++;
        rear2 = (rear2 + 1) % QUEUE_SIZE;
        data2[rear2] = f; length2++;
    }

    void Delete() {
        if (IsEmpty()) Error("Queue is empty");
        
        cout << "ID : " << data1[front1] << endl;
        front1 = (front1 + 1) % QUEUE_SIZE; 
        length1--;

        cout << "name : " << data2[front2] << endl;
        front2 = (front2 + 1) % QUEUE_SIZE;
        length2--;
    }

    void Peek() {
        if (IsEmpty()) break;
        cout << "ID_Peek : " << data[front1] << endl;
        cout << "name : " << data[front2] << endl;
    }

    bool IsEmpty() { return length1 == 0; }
    bool IsFull() { return length1 == QUEUE_SIZE; }
    void PrintQueueTemplate() {
        for (int i = 0; i < length1; i++) {
            cout << data1[(front1 + i) % QUEUE_SIZE];
            cout << " ";
        }
        for (int i = 0; i < length2; i++) {
            cout << data2[(front2 + i) % QUEUE_SIZE];
            cout << " ";
        }

        cout << endl;
    }
    int Length() { return length1; }
};