class Solution {
public:
    int compareVersion(string version1, string version2) {
        string v1, v2;
        while(version1 != "" || version2 != ""){
            string::iterator iter = version1.begin();
            while(iter != version1.end() && *iter != '.') iter++;
            v1 = string(version1.begin(), iter); 
            if(iter != version1.end() && *iter == '.') iter++;
            version1 = string(iter, version1.end());
            iter = version2.begin();
            while(iter != version2.end() && *iter != '.') iter++;
            v2 = string(version2.begin(), iter);
            if(iter != version2.end() && *iter == '.') iter++;
            version2 = string(iter, version2.end());
            int ans = compare(v1, v2);
            if(ans > 0) return 1;
            if(ans < 0) return -1; 
        }
        return 0;
    }

    int compare(string &a, string &b){
        string::iterator iter = a.begin();
        while(iter != a.end() && *iter == '0') iter++;
        a = string(iter, a.end());
        iter = b.begin();
        while(iter != b.end() && *iter == '0') iter++;
        b = string(iter, b.end());
        int len_a = a.length(), len_b = b.length();
        if(len_a > len_b) return 1;
        if(len_a < len_b) return -1;
        if(a > b) return 1;
        if(a < b) return -1;
        return 0;
    }
};