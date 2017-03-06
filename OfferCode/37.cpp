/*
题目： 统计一个数字在排序数组中出现的次数。

使用二分查找寻找上下边界
*/


class Solution {
public:
    
    int findUpbound(const vector<int> &data, int x){
        int left = 0, right = data.size();
        while(left + 1 < right) {
            int mid = (right - left) / 2 + left;
            if(data[mid] > x) right  = mid;
            else left = mid;
        }
		if(data[left] == x) return left;
        else return -1;
    }
    
    int findLowbound(const vector<int> &data, int x){
		int left = -1, right = data.size() - 1;
        while(left + 1 < right) {
            int mid = (right - left) / 2 + left;
            if(data[mid] >= x) right = mid;
            else left = mid;
        }
        if(data[right] == x) return right;
        else return -1;
    }
    
    
    
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0) return 0;
        int upbound = findUpbound(data, k);
        int lowbound = findLowbound(data, k);
    	if(upbound == -1 || lowbound == -1) return 0;
        return upbound - lowbound + 1;
	}
};