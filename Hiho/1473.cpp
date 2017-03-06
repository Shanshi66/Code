/*
题目：小Ho在一条笔直的街道上散步。街道上铺着长度为L的石板，所以每隔L距离就有一条石板连接的缝隙，如下图所示。
小Ho在散步的时候有奇怪的强迫症，他不希望脚踩在石板的缝隙上。（如果小Ho一只脚的脚尖和脚跟分别处于一条缝隙的两侧，我们就认为他踩在了缝隙上。如果只有脚尖或脚跟接触缝隙，不算做踩在缝隙上）  

现在我们已知小Ho两只脚的长度F以及每一步步伐的长度D。如果小Ho可以任意选择起始位置，请你判断小Ho能否保持不踩缝隙散步至无穷远处？

http://hihocoder.com/problemset/problem/1473
*/

/*

分析：假设脚后跟起点在石板中的位置是S, 走K步后是(S + KD) % L， 叫前跟是(S+KD) % L + F, 
则不踩线的条件是

(S + KD) % L + F <= L

S < L

则 S + (KD) % L <= L - F

t = gcd(L, D)

KD = KAt
L = Bt

KD = ML + x
=> KAt = MBt + x
=> KAt % t = 0 = (MBt + x) % t
=> 则x是t的倍数，且 0 <= x < L

S + (KD) % L <= L - F

取 S = 0，(KD) % L = L - gcd(d, l) ,可得到最终条件

F <= gcd(d, l)

*/

#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y){
    if(x < y) swap(x, y);
    if(x % y == 0) return y;
    return gcd(y, x % y);
}

int main()
{
    freopen("in.txt", "r", stdin);
    int l, f, d, n;
    cin >> n;
    while(n--){
        bool flag = false;
        cin >> l >> f >> d;
        if(f <= gcd(d, l)) puts("YES");
        else puts("NO");
    }
    return 0;
}