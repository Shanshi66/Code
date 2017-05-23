/*
题目：给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。

思路：开两个数组分别保存从前往后，和从后往前的指针
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
    	vector<int> prodFromBegin(len, 1);
        vector<int> prodFromEnd(len, 1);
        vector<int> prod(len, 0);
        for(int i = 0; i < len; i++) {
           	if(i == 0) {
                prodFromBegin[i] = A[i];
                prodFromEnd[len - i - 1] = A[len - i - 1];
            } else {
                prodFromBegin[i] = A[i] * prodFromBegin[i - 1];
                prodFromEnd[len - i - 1] = A[len - i - 1] * prodFromEnd[len - i];
            }
        }
        for(int i = 0; i < len; i++) {
        	if(i == 0) prod[i] = prodFromEnd[i + 1];
            else if(i == len - 1) {
                prod[i] = prodFromBegin[i - 1];
            } else {
                prod[i] = prodFromBegin[i - 1] * prodFromEnd[i + 1];
            }
        }
        return prod;
    }
};