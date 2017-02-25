#include "utils.h"
#include "Sort/HeapSort.h"
#include "Sort/QuickSort.h"
#include "Sort/MergeSort.h"
#include "Sort/CountingSort.h"
#include "Sort/InsertSort.h"

using namespace std;

int main() {
    const int len = 17;
	int arr[len] = {3,21,2,45,3,64,32,1,4,6,6,23,12,34,23,124,46};
    //int arr[len] = {21, 2};
	vector<int> array;
	for (int i = 0; i < len; i++) {
		array.push_back(arr[i]);
	}
	printArray(array, 0, array.size());
	// heapSort(array);
	// quickSort(array, 0, array.size() - 1);
    // mergeSortRecursive(array, 0, array.size());
    // mergeSortNonRecursive(array);
    // countingSort(array, 200);
    insertSort(array);
    printArray(array, 0, array.size());
	getchar();
	return 0;
}