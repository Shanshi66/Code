#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

const int N = 1e5+5;


int main(){
    int t,tt=0;
    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while(t--){
        string str;
        int k;
        getchar();
        getline(cin, str);
        scanf("%d", &k);
        int row = str.length() / k;
        int full_col = str.length() % k;
        if(full_col)row += 1;
        else full_col += k;
        string ori_str;
        int col_sum[k];
        for(int i=0; i<k; i++){
            if(i==0)col_sum[i] = row;
            else if(i<full_col)col_sum[i] = col_sum[i-1] + row;
            else col_sum[i] = col_sum[i-1] + row - 1;
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<k; j++){
                if(i==row-1 && j>=full_col)break;
                if(j==0)ori_str += str[i];
                else ori_str += str[col_sum[j-1]+i];
            }
        }
        cout<<ori_str<<endl;
    }
    return 0;
}
