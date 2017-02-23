/*
题目：输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

注意：
有个误区，不一定需要生成的时候按字典序的顺序生成，可以最后对result数组排个序
*/


class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str == "") return result;
        sort(str.begin(), str.end());
        string res;
        dfs(result, res, str.begin(), str.end());
        return result;
    }

    void dfs(vector<string> &result, string &res, string::iterator begin, string::iterator end){
        if(begin == end) {
            result.push_back(res);
            return;
        }
        for(string::iterator iter = begin; iter != end; iter++){
            if(iter > begin && *iter == *(iter - 1)) continue;
            char head = *iter;
            res.push_back(head);
            if(iter != begin){
                for(string::iterator iter2 = iter - 1; iter2 >= begin; iter2--) {
                	*(iter2 + 1) = *iter2;
            	}
            }
            dfs(result, res, begin + 1, end);
            if(iter != begin){
				for(string::iterator iter2 = begin; iter2 != iter; iter2++){
                    *iter2 = *(iter2 + 1);
                }
            }
            res.pop_back();
            *iter = head;
        }
    }
};

/*
排列生成后再排序，复杂度貌似差不多
*/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str == "") return result;
        string res;
        dfs(result, res, str.begin(), str.end());
        sort(result.begin(), result.end());
        return result;
    }

    void dfs(vector<string> &result, string &res, string::iterator begin, string::iterator end){
        if(begin == end) {
            result.push_back(res);
            return;
        }
        for(string::iterator iter = begin; iter != end; iter++){
            bool occured = false;
            for(string::iterator iter2 = begin; iter2 < iter; iter2++){
                if(*iter2 == *iter) occured = true;
            }
            if(occured) continue;
            res.push_back(*iter);
            swap(*iter, *begin);
            dfs(result, res, begin + 1, end);
            res.pop_back();
            swap(*iter, *begin);
        }
    }
};