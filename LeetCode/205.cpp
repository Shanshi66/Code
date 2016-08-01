class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mapper;
        string tmp = s;
        int s_len = s.length(), t_len = t.length();
        if(s_len != t_len) return false;
        for(int i = 0; i < s_len; i++){
            if(mapper.find(s[i]) == mapper.end()) mapper[s[i]] = t[i];
            s[i] = mapper[s[i]];
        }
        if(s != t) return false;
        s = tmp;
        mapper.clear();
        for(int i = 0; i < t_len; i++){
            if(mapper.find(t[i]) == mapper.end()) mapper[t[i]] = s[i];
            t[i] = mapper[t[i]];
        }
        return s == t;
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mapper;
        string tmp = s;
        int s_len = s.length(), t_len = t.length();
        if(s_len != t_len) return false;
        for(int i = 0; i < s_len; i++){
            if(mapper.find(s[i]) == mapper.end()) mapper[s[i]] = t[i];
            s[i] = mapper[s[i]];
        }
        if(s != t) return false;
        set<char> filter;
        for(map<char, char>::iterator iter = mapper.begin(); iter != mapper.end(); iter++){
            filter.insert(iter->second);
        }
        if(mapper.size() != filter.size()) return false;
        return true;
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mapper;
        string tmp = s;
        int s_len = s.length(), t_len = t.length();
        if(s_len != t_len) return false;
        for(int i = 0; i < s_len; i++){
            if(mapper.find(s[i]) != mapper.end()){
                if(mapper[s[i]] != t[i])return false;
            }else{
                if(mapper.find(t[i]) != mapper.end()) return false;
                else mapper[s[i]] = t[i];
            }
        }
        return true;
    }
};