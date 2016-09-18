#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
    //freopen("A-small-attempt1.in", "r", stdin);
    
    // freopen("in.txt", "r", stdin);
    //freopen("ans.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("large_ans.out", "w", stdout);
    int T, case_cnt = 0;
    cin >> T;
    while(T--){
        cin >> n;
        map<string, int> dict; int cnt = 0;
        for(int i = 0; i < n; i++){
            string str;
            getline(cin, str);
            int len = str.length(), s;
            for(int b = 0, i = 1; i < len; i++){
                string cur; 
                if(str[i] == '='){
                    cur = string(str, b, i);
                    if(dict.find(cur) == dict.end()) dict[cur] = cnt++;
                    s = dict[cur];
                    b = i;
                }
                if(str[i] == '(')
            }
        }
        printf("Case #%d: %.7lf\n", ++case_cnt, ans);
    }
    return 0;
}