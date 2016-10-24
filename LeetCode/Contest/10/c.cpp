class Solution {
public:
    string parseTernary(string expression) {
        int expr_len = expression.length();
        if(expr_len == 0) return string();
        if(expr_len == 1) return expression;
        stack<char> questionMask;
        bool isLeft = (expression[0] == 'T');
        string ans;
        for(auto iter = expression.begin(); iter != expression.end(); iter++){
            if(*iter == '?') {
                questionMask.push(*iter);
            }
            if(*iter == ':') {
                questionMask.pop();
                if(questionMask.empty()){
                   if(isLeft) ans = parseTernary(string(expression.begin() + 2, iter));
                   else ans = parseTernary(string(iter + 1, expression.end()));
                   break; 
                }
            }
        }
        return ans;
    }
};