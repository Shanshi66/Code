/*
题目： 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

思路：使用两个栈，第二个栈维护前n个数的最小值
*/

class Solution {
public:
    void push(int value) {
        st.push(value);
        if(!min_st.empty()) {
            if(value > min_st.top()) min_st.push(min_st.top());
            else min_st.push(value);
        } else {
            min_st.push(value);
        }
    }
    void pop() {
        if(!st.empty()) st.pop();
        if(!min_st.empty()) min_st.pop();
    }
    int top() {
		return st.top();
    }
    int min() {
        return min_st.top();
    }
private:
    stack<int> st;
    stack<int> min_st;
};