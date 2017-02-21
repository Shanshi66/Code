/*
题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

  

*/


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		int len = sequence.size();
        if(len == 0) return false;
        if(len <= 2) return true;
        return VerifyBackOrderSequenceOfBST(sequence, 0, len - 1);
    }
    
    bool VerifyBackOrderSequenceOfBST(const vector<int> &sequence, int begin, int end){
        int split_index = 0;
        if(end - begin <= 0) return true;
        while(sequence[split_index] < sequence[end]) {
            split_index++;
        }
        
        if(VerifyBackOrderSequenceOfBST(sequence, begin, split_index - 1) == false) return false;
        
       	for(int i = split_index; i < end; i++) {
            if(sequence[i] < sequence[end]) {
                return false;
            }
        }
        if(VerifyBackOrderSequenceOfBST(sequence, split_index, end - 1) == false) return false;
        return true;
    }
};