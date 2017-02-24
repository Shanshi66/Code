#pragma once

#include "../utils.h"

using namespace std;

/*
这种方法看上去是稳定的，但是如果有元素相同
且选择相同元素中的一个作为key，则会不稳定
还有，如果数组...7....7...2...2...，key是3，
如果最终key放在两个7之间，则这是不稳定的
*/

inline int randIndex(const int &begin, const int &end) {
	return rand() % (end - begin + 1) + begin;
}

int partion(vector<int> &array, int begin, int end) {
	int small = begin - 1;
	int pivot = randIndex(begin, end);
	swap(array[pivot], array[end]);
	for (int i = begin; i <= end; i++) {
		if (array[i] <= array[end]) {
			small++;
			if (i == small) continue;
			swap(array[i], array[small]);
		}
	}
	return small;
}

int partion2(vector<int> &array, int begin, int end) {
	int pivot = randIndex(begin, end);
	swap(array[pivot], array[end]);
	int l = begin, r = end;
    while (l < r) {
        while (l < r && array[l] <= array[r]) l++;
        swap(array[l], array[r]);
        while (l < r && array[l] <= array[r]) r--;
        swap(array[l], array[r]);
    }
    return l;
}

void quickSort(vector<int> &array, int begin, int end) {
	if (begin >= end) return;
	int index = partion2(array, begin, end);
	quickSort(array, begin, index - 1);
	quickSort(array, index + 1, end);
}
