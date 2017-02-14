/*
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

思路：正常情况下，前面一段的数都比后面一段大，通过这个条件可以判断出mid是属于那一段，从而可以用二分来做。

有以下特殊情况：
1. 前面一段长度为0
2. left = right = mid 时无法分辨，需顺序查找。

*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int arr_len = rotateArray.size();
        int left = 0, right = arr_len - 1;
        int mid = left;
        while(left < right) {
            if(left + 1 == right) {
                break;
            }
            mid = (right - left) / 2 + left;
            if(rotateArray[left] == rotateArray[mid] && rotateArray[mid] == rotateArray[right]) {
                return minNumberInArray(rotateArray);
            } else if(rotateArray[mid] >= rotateArray[left]) {
                left = mid;
            } else if(rotateArray[mid] <= rotateArray[right]) {
                right = mid;
            }
        }
        return rotateArray[right];
    }
     
    int minNumberInArray(const vector<int> array){
        int min_number = array[0];
        for(auto x : array) {
            min_number = min(min_number, x);
        }
        return min_number;
    }
};