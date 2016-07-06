#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int LEN = 45;
int n;
string str;

int main(){
    freopen("in.txt", "r", stdin);
    cin>>n;
    map<string, int> dict;
    for(int i=0; i<n; i++){
        cin>>str;
        sort(str.begin(), str.end());
        if(dict.find(str)==dict.end()){
            cout<<"0"<<endl;
            dict[str] = 1;
        }else{
            cout<<dict[str]<<endl;
            dict[str] += 1;
        }
    }
    return 0;
}
