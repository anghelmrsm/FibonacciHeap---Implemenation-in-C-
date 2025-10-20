///Proiect SD - implementare FibonacciHeap

#include <iostream>
#include "FibonacciHeap.h"

using namespace std;

int main() {
    FibonacciHeap heap1;
    FibonacciHeap heap2;

    heap1.insertNode(10);
    heap1.insertNode(3);
    heap1.insertNode(15);

    heap2.insertNode(6);
    heap2.insertNode(1);
    heap2.insertNode(9);

    cout << "Minimum in heap1: " << heap1.findMin() << endl;
    cout << "Minimum in heap2: " << heap2.findMin() << endl;

    heap1.unionHeaps(heap2);

    cout << "Minimum after union: " << heap1.findMin() << endl;

    cout << "Minimum removed: " << heap1.deleteMin() << endl;

    cout << "New minimum after deleteMin operation: " << heap1.findMin() << endl;

    return 0;
}
