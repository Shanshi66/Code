#pragma once
#include "../utils.h"

using namespace std;

void merge(vector<int> &array, int begin, int mid, int end) {
    vector<int> tmp;
    int i = begin, j = mid;
    while (i < mid && j < end) {
        if (array[i] < array[j]) tmp.push_back(array[i++]);
        else tmp.push_back(array[j++]);
    }
    while (i < mid) tmp.push_back(array[i++]);
    while (j < end) tmp.push_back(array[j++]);
    for (int i = 0; i < tmp.size(); i++) {
        array[begin + i] = tmp[i];
    }
}

void mergeSortRecursive(vector<int> &array, int begin, int end) {
    if (begin == end - 1) return;
    int mid = (end - begin) / 2 + begin;
    mergeSortRecursive(array, begin, mid);
    mergeSortRecursive(array, mid, end);
    merge(array, begin, mid, end);
}

void mergeToArray(vector<int> &from, vector<int> &to, int begin, int mid, int end) {
    int i = begin, j = mid, k = begin;
    while (i < mid && j < end) {
        if (from[i] < from[j]) to[k++] = from[i++];
        else to[k++] = from[j++];
    }
    while (i < mid) to[k++] = from[i++];
    while (j < end) to[k++] = from[j++];
}

void mergeSortNonRecursive(vector<int> &array) {
    int step = 1, len = array.size();
    vector<int> tmp_array(len, 0);
    bool inArray = true;
    while (step < len) {
        // midµÄÎ»ÖÃ
        for (int i = 0; i <= len - step; i += step * 2) {
            int l = i, m = l + step, r = m + step;
            if (inArray) mergeToArray(array, tmp_array, l, m, min(r, len));
            else mergeToArray(tmp_array, array, l, m, min(r, len));
        }
        step <<= 1;
        inArray = !inArray;
    }
    if (!inArray) array.swap(tmp_array);
}


