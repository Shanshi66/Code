#include "utils.h"
#include "Sort/HeapSort.h"
#include "Sort/QuickSort.h"
#include "Sort/MergeSort.h"
#include "Sort/CountingSort.h"
#include "Sort/InsertSort.h"
#include "Random/ReservoirSampling.h"
#include "Search/BinarySearch.h"
#include "Tree/Travel.h"

using namespace std;

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,};
	vector<int> array;
	for (auto x : arr) {
		array.push_back(x);
	}
    TreeNode *root = createTree(array, 0);
    middleOrderRecursive(root);
    cout << endl;
    middleOrderNonRecursive(root);
    cout << endl;
    beforeOrderRecursive(root);
    cout << endl;
    beforeOrderNonRecursive(root);
    cout << endl;
    afterOrderRecursive(root);
    cout << endl;
    afterOrderNonRecursive(root);
    cout << endl;
	getchar();
	return 0;
}