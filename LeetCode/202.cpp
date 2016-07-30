class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(n != 1 && n != 7){
            if(n < 10 || (s.find(n) != s.end())) return false;
            s.insert(n);
            int sum = 0;
            while(n != 0) sum += (n % 10) * (n % 10), n /= 10;
            n = sum;
        }
        return true;
    }
};