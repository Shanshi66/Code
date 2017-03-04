#pragma once

#include "../utils.h"

int binarySearch(const vector<int> &arr, int x) {
    int left = 0, right = arr.size() - 1;
    int index = -1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (arr[mid] == x) {
            index = mid;
            break;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return index;
}

/*
int binarySearchUpbound(const vector<int> &arr, int x) {
    int left = 0, right = arr.size();
    while (left + 1 < right) {
        int mid = (right - left) / 2 + left;
        if (arr[mid] > x) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    if (arr[left] == x) return left;
    else return -1;
}

int binarySearchLowbound(const vector<int> &arr, int x) {
    int left = -1, right = arr.size() - 1;
    while (left + 1 < right) {
        int mid = (right - left) / 2 + left;
        if (arr[mid] >= x) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    if (arr[right] == x) return right;
    return -1;
}
*/

int binarySearchUpbound(const vector<int> &arr, int x) {
    int left = 0, right = arr.size();
    while (left + 1 < right) {
        int mid = (right - left) / 2 + left;
        if (arr[mid] <= x) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    if (arr[left] == x) return left;
    else return -1;
}

int binarySearchLowbound(const vector<int> &arr, int x) {
    int left = -1, right = arr.size() - 1;
    while (left + 1 < right) {
        int mid = (right - left) / 2 + left;
        if (arr[mid] >= x) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    if (arr[right] == x) return right;
    return -1;
}