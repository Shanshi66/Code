#pragma once

#include "../utils.h"

void insertSort(vector<int> &array) {
    int len = array.size();
    for (int i = 1; i < len; i++) {
        int key = array[i], j = i - 1;
        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}