/*
题目： 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

思路：定义一个比较函数，对数字进行排序

cmp定义：如果ab < ba, 则a < b;
为什么：如果a比所有元素都小，那么a必定排在最左边，否则最终就不是最小的了
*/

class Solution {
public:
    string to_string(int x){
        stringstream str_stream;
        string xstr;
        str_stream << x;
        str_stream >> xstr;
        return xstr;
    }
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strs;
        int size = numbers.size();
        for(int i = 0; i < size; i++) {
            strs.push_back(to_string(numbers[i]));
        }
        sort(strs.begin(), strs.end(), cmp);
        string res;
        for(auto s: strs) {
            res += s;
        }
        return res;
    }
    static bool cmp(const string &a, const string &b) {
        string ab = a + b;
        string ba = b + a;
        return ab < ba;
    }
};