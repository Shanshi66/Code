#pragma once

#include "../utils.h"

vector<int> reservoirSampling(vector<int> &nums, int k) {
    for (int i = k; i < nums.size(); i++) {
        int r = rand() % (i + 1);
        if (r < k) swap(nums[r], nums[i]);
    }
    return vector<int>(nums.begin(), nums.begin() + k);
}

vector<int> reservoirSamplingByHeap(vector<int> &nums, int k) {
    priority_queue< pair<int, int> > heap;
    for (int i = 0; i < nums.size(); i++) {
        int r = rand();
        cout << r << endl;
        if (heap.size() < k) heap.push(make_pair(nums[i], r));
        else {
            if (heap.top().second > r) {
                heap.pop();
                heap.push(make_pair(nums[i], r));
            }
        }
    }
    vector<int> sample;
    while (!heap.empty()) {
        sample.push_back(heap.top().first);
        heap.pop();
    }
    return sample;
}