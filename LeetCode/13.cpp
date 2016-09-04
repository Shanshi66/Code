class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        map<char, int> mapper;
        mapper['I'] = 1;
        mapper['V'] = 5;
        mapper['X'] = 10;
        mapper['L'] = 50;
        mapper['C'] = 100;
        mapper['D'] = 500;
        mapper['M'] = 1000;
        for(int i = 0; i < s.length(); i++){
            if(i == 0) sum = mapper[s[i]];
            else{
                if(mapper[s[i]] > mapper[s[i - 1]]) sum = mapper[s[i]] - sum;
                else sum += mapper[s[i]];
            }
        }
        return sum;
    }
};