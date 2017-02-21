/*
题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int size_push = pushV.size(), size_pop = popV.size();
        if(size_push != size_pop) return false;
        int i = 0, j = 0;
        stack<int> st;
        for(int i = 0; i < size_push; i++) {
            st.push(pushV[i]);
            while(!st.empty() && st.top() == popV[j]) {
                st.pop();
                j++;
            }
        }
        if(j < size_pop) return false;
        return true;
    }
};