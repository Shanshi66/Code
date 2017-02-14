/*
题目：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

思路：两个栈导两次就是正序了。往stack1里压，从stack2里弹。
*/


class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
 
    int pop() {
        if(stack2.empty()){
            //if(stack1.empty()) throw new std::exception("empty queue!");
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int top = stack2.top();
        stack2.pop();
        return top;
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};