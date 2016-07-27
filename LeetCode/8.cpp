class Solution {
public:
    int myAtoi(string str) {
        const long long MAX_INT = 2147483647, MIN_INT = -2147483648;
        int size_s = str.size(), i = 0;
        bool sign = true;
        while(str[i] == ' ') i++;
        if(str[i] == '-' || str[i] == '+'){
            sign = str[i] == '-' ? false : true;
            i++;
        }
        long long sum = 0;
        bool overflow = false;
        for( ; i < size_s; i++){
            if(str[i] >= '0' && str[i] <= '9'){
                sum *= 10;
                sum += str[i] - '0';
            }else break;
            if(sign && (sum > MAX_INT)){
                overflow = true;
                sum = MAX_INT;
                break;
            }
            if(!sign && (sum > -MIN_INT)){
                overflow = true;
                sum = MIN_INT;
                break;
            }
        }
        if(!overflow) sum = sign ? sum : -sum;
        return sum;
    }
};