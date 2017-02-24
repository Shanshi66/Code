#pragma once
#include "../utils.h"

using namespace std;

inline int parent(int i) {
	return (i - 1) >> 1;
}
inline int lChild(int i) {
	return (i << 1) + 1;
}
inline int rChild(int i) {
	return (i << 1) + 2;
}


/*
节点i的子树上最多有2n/3的节点（左子树，最后一层满，右子树最后一层没有节点）
则T(n) <= T(2n/3) + O(1), 运用主定理知复杂度为O(lgn)
*/
void maxHeapify(vector<int> &heap, int i, int heap_size) {
	int l = lChild(i), r = rChild(i), largest = i;
	if (l < heap_size && heap[l] > heap[i]) largest = l;
	if (r < heap_size && heap[r] > heap[largest]) largest = r;
	if (largest != i) {
		swap(heap[i], heap[largest]);
		maxHeapify(heap, largest, heap_size);
	}
}

/*
可以证明时间复杂度上界是O(n)
*/
void buildHeap(vector<int> &heap) {
	int heap_size = heap.size();
	int last_parent = parent(heap_size - 1);
	for (int i = last_parent; i >= 0; i--) {
		maxHeapify(heap, i, heap_size);
	}
}

void heapSort(vector<int> &heap) {
	buildHeap(heap);
	int heap_size = heap.size();
	while (heap_size > 1) {
		swap(heap[heap_size - 1], heap[0]);
		heap_size--;
		maxHeapify(heap, 0, heap_size);
	}
}



