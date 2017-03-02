/*
题目：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007 

归并排序，但是很奇怪非递归版本的居然不行
*/

class Solution {
public:
    const int MOD = 1000000007;
    int merge(vector<int> &arr, int begin, int mid, int end) {
        vector<int> tmp(end - begin, 0);
        int i = begin, j = mid, k = 0;
        int ans = 0;
        while (i < mid && j < end) {
            if (arr[i] > arr[j]) {
                tmp[k++] = arr[i++];
                ans = (ans + end - j) % MOD;
            }
            else {
            	tmp[k++] = arr[j++];
            }
        }
        while (i < mid) tmp[k++] = arr[i++];
        while (j < end) tmp[k++] = arr[j++];
        for (int i = 0; i < tmp.size(); i++) {
            arr[begin + i] = tmp[i];
        }
        return ans;
	}

    int mergeSort(vector<int> &arr, int begin, int end){
        if (begin == end - 1) return 0;
    	int mid = (end - begin) / 2 + begin;
    	int left = mergeSort(arr, begin, mid);
    	int right = mergeSort(arr, mid, end);
    	int cnt = merge(arr, begin, mid, end);
    	return (left + right + cnt) % MOD;
    }
    
    int InversePairs(vector<int> data) {
        int begin = 0, end = data.size();
        return mergeSort(data, begin, end);
    }
};