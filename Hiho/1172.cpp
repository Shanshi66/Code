#include <bits/stdc++.h>

using namespace std;

int main(){
    int sum = 0, n;
    char coin;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> coin;
        if(coin == 'H') sum = sum ^ i;
    }
    if(sum == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
    return 0;
}