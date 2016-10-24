#include <bits/stdc++.h>

using namespace std;

void dfs(string cur_code, int one_left, int zero_left){
    if(zero_left < one_left - 1) return;
    if(zero_left == 0 && one_left == 0){
        cout << cur_code + '0' << endl;
    }
    if(zero_left > 0){
        dfs(cur_code + '0', one_left, zero_left - 1);
    }
    if(one_left > 0){
        dfs(cur_code + '1', one_left - 1, zero_left);
    }
}

int main(){
    int n;
    cin >> n;
    dfs("1", n - 2, n - 2);
    return 0;
}