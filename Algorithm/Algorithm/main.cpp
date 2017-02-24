#include "utils.h"
#include "Sort/HeapSort.h"
#include "Sort/QuickSort.h"

using namespace std;

int main() {
	int arr[11] = {3,21,2,45,3,64,32,1,4,6,6};
	vector<int> array;
	for (int i = 0; i < 11; i++) {
		array.push_back(arr[i]);
	}
	printArray(array, 0, array.size() - 1);
	// heapSort(array);
	quickSort(array, 0, array.size() - 1);
	printArray(array, 0, array.size() - 1);
	getchar();
	return 0;
}