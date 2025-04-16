#include <iostream>
#include "MaxHeap.h"
using namespace std;



int main() {

	cout << "******** TEST Insert() and Remove() **********" << endl << endl;

	MaxHeap newHeap;

	for (int i = 0; i < 10; i++) {
		newHeap.Insert(i);
	}

	cout << newHeap.GetHeapArrayString();
	cout << endl;

	newHeap.Remove();
	newHeap.Remove();

	cout << newHeap.GetHeapArrayString();
	cout << endl;


	cout << "*********** TEST + ***********" << endl << endl;

	MaxHeap heap1;
	MaxHeap heap2;

	for (int i = 100; i < 110; i++) {
		heap1.Insert(i);
	}
	cout << heap1.GetHeapArrayString() << endl;

	for (int i = 200; i < 210; i++) {
		heap2.Insert(i);
	}
	cout << heap2.GetHeapArrayString() << endl;

	MaxHeap newHeap2;

	newHeap2 = heap1 + heap2;

	cout << newHeap2.GetHeapArrayString() << endl;



}// end of main()