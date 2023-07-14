#include <iostream>
#include <cstdlib>
using namespace std;
const int HEAP_SIZE = 10000;
void Error(string s) { cerr << s; exit(-1); }

template <typename Data>
class HeapTemplate {
    Data data[HEAP_SIZE];
    int length;
    void InsertRear(Data d);
    Data DeleteRear();
    void Swap(int i, int j) {
        Data temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    virtual int Key(Data d) = 0;
public:
    HeapTemplate() { length = 0; }
    void Insert(Data d);
    Data Delete();
    Data Peek() { return data[1]; }
    int Length() { return length == 0; }
    void PrintTree();
    bool IsEmpty() { return length == 0; }
    bool IsFull() {
        return length == HEAP_SIZE - 1;
    }
};
class MaxHeap : public HeapTemplate<int> {
    int Key(int d) { return d; }
};
class MinHeap : public HeapTemplate<int> {
    int Key(int d) { return -d; }
};

template <class Data>
void HeapTemplate<Data>::InsertRear(Data d)
{
    if (IsFull()) Error("Tree is full");
    data[++length] = d;
}

template <class Data>
void HeapTemplate<Data>::PrintTree()
{
    for (int i = 1; i <= length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class Data>
Data HeapTemplate<Data>::DeleteRear()
{
    if (IsEmpty()) Error("Tree is empty");
    return data[length--];
}

template <class Data>
void HeapTemplate<Data>::Insert(Data d)
{
    InsertRear(d);
    int child = length, parent = child / 2;
    while (child > 1) {
        if (Key(data[parent]) >= Key(data[child]))
            break;
        Swap(child, parent);
        child = parent, parent = child / 2;
    }
}

template <class Data>
Data HeapTemplate<Data>::Delete()
{
    Swap(1, length);
    Data result = DeleteRear();
    int parent = 1, child = parent * 2;
    while (child <= length) {
        child += (child < length && Key(data[child]) < Key(data[child + 1]));
        if (Key(data[parent]) >= Key(data[child])) break;
        Swap(child, parent);
        parent = child; child = parent * 2;
    }
    return result;
}