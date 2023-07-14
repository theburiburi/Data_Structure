#include <iostream>

using namespace std;
#define SWAP(a,b){int c=a;a=b;b=c;}

class SortAlgorithm {
public:
    void PrintSubArray(int a[], int low, int high) {
        for (int i = 0; i <= high; i++) {
            if (i < low)cout << " ";
            else cout << a[i] << " ";
        }
        cout << endl;
    }
    void PrintArray(int a[], int length) {
        PrintSubArray(a, 0, length - 1);
    }
    virtual void Sort(int a[], int length) = 0;
};