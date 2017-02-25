#pragma once

#include "../utils.h"

void countingSort(vector<int> &array, int k) {
    int len = array.size();
    vector<int> tmp_array(len, 0), count(k, 0);
    for (int i = 0; i < len; i++) {
        count[array[i]] += 1;
    }
    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }
    for (int i = len - 1; i >= 0; i--) {
        tmp_array[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    array.swap(tmp_array);
}