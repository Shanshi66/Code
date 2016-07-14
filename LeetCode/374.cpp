int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n, m;
        while(l <= r){
            m = (r - l) / 2 + l;
            int g = guess(m);
            if(g < 0) r = m - 1;
            else if(g > 0) l = m + 1;
            else break;
        }
        return m;
    }
};