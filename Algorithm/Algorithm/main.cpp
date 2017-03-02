#include "utils.h"
#include "Sort/HeapSort.h"
#include "Sort/QuickSort.h"
#include "Sort/MergeSort.h"
#include "Sort/CountingSort.h"
#include "Sort/InsertSort.h"
#include "Random/ReservoirSampling.h"

using namespace std;

int main() {
    const int len = 17;
	int arr[len] = {3,21,2,45,3,64,32,1,4,6,6,23,12,34,23,124,46};
	vector<int> array;
	for (int i = 0; i < len; i++) {
		array.push_back(arr[i]);
	}
    vector<int> sample = reservoirSamplingByHeap(array, 6);
    printArray(sample, 0, sample.size());
	getchar();
	return 0;
}