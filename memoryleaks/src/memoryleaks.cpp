#include <iostream>
#include <cstring>

int main() {
	// 1) Reading uninitialized memory
	int x;
	
	if (x > 0) { // ERROR: x was never initialized
		std::cout << "x is positive\n";
	}
	
	// 2) Out-of-bounds access

	int* arr = new int[5];

	for (int i = 0; i <= 5; ++i) { // ERROR: should be i <5, not <= 5
		arr[i] = i * 10;
	}

	// 3) Use-after-free
	delete[] arr;
	std::cout << "arr[2] after delete = " << arr[2] << "\n"; // ERROR: accessing memory after it was freed

	// 4) Memory leak

	char* buffer = new char[10];
	std::strcpy(buffer, "hello"); // OK here
	// Missing: delete[] buffer; + memory leak
	
	return 0;
}