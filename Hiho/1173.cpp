#include <bits/stdc++.h>

using namespace std;

const int MAX_STONE = 20000;
int SG[MAX_STONE];

void preCalculateSG(){
    for(int i = 0; i <= MAX_STONE; i++){
        if(i == 0) SG[i] = 0;
        else{
            bool mex[2 * i + 1];
            for(int j = 0; j <= 2 * i; j++) mex[j] = false;
            for(int j = 0; j < i; j++) mex[SG[j]] = true;
            for(int j = 1; j < i; j++) mex[SG[j] ^ SG[i - j]] = true;
            for(int j = 0; j <= 2 * i; j++){
                if(mex[j] == false){
                    SG[i] = j;
                    break;
                }
            }
        }
    }
}

int main()
{
    preCalculateSG();
    int n, sg = 0, stone_num;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> stone_num;
        sg ^= SG[stone_num];
    }
    if(sg > 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    return 0;
}

/*
对于一个游戏可能发生的局面x，我们如下定义它的sg值：
(1)若当前局面x为终结局面，则sg值为0。
(2)若当前局面x非终结局面，其sg值为：sg(x) = mex{sg(y) | y是x的后继局面}。
mex{a[i]}表示a中未出现的最小非负整数。举个例子来说：
mex{0, 1, 2} = 3, mex{1, 2}=0, mex{0,1,3}=2

可以发现，若一个局面x为P局面，则有sg(x)=0；否则sg(x)>0。同样sg值也满足N、P之间的转换关系：
若一个局面x，其sg(x)>0，则一定存在一个后续局面y，sg(y)=0。
若一个局面x，其sg(x)=0，则x的所有后续局面y，sg(y)>0。

由上面的推论，我们可以知道用N、P-Position可以描述的游戏用sg同样可以描述。并且在sg函数中还有一个非常好用的定理，叫做sg定理：
对于多个单一游戏，X=x[1..n]，每一次我们只能改变其中一个单一游戏的局面。则其总局面的sg值等于这些单一游戏的sg值异或和。
即：
sg(X) = sg(x[1]) xor sg(x[2]) xor … xor sg(x[n])
要证明这一点我们只要证明：
(1) 假设sg(x[1]) xor sg(x[2]) xor … xor sg(x[n]) = A，对于任意一个0 <= B < A，总存在一个X的后续局面Y，使得sg(Y) = B。
(2) 假设sg(x[1]) xor sg(x[2]) xor … xor sg(x[n]) = A，不存在一个X的后续局面Y，使得sg(Y) = A。
下先证明(1)：
假设M = A xor 
B，设M表示为二进制之后最高位的1为第k位。所以A的第k位为1，B的第k位为0。又因为A的第k位为1，至少存在一个i，sg(x[i])的第k位也为1。那么一定有sg(x[i]) xor M < sg(x[i])，即一定通过某个操作使x[i]变为x[i’]，且sg(x[i’]) = sg(x[i]) xor M。那么：
sg(x[i’]) xor Other = sg(x[i]) xor M xor Other = M xor A = B
下证明(2)：
若sg(X) = A，sg(Y) = A。不妨设我们改变的游戏为x[i]，则X=x[1..n], Y=x[1…i’…n]。有sg(x[i]) = sg(x[i’])，产生矛盾，所以sg(Y)不可能等于A。

现在让我们回到我们的题目上：
局面上一共有N堆石子，每一次我们只能改变一堆石子。那么我们可以将每一堆石子看作一个单一游戏。
对于一堆石子，若该堆石子数量为0，就达到了终止状态，所以sg(0) = 0。
若其石子数量为k，接下来我们从k=1开始枚举递推每一个sg(k)。对于k，其可能的后继状态有：
(1)不分堆：石子数量为k’=0..k-1，则sg(k’)
(2)分堆：石子变为2堆，数量为(1,k-1),(2,k-2),…,(k-1,1)。设第一堆的石子数量为i，则sg值为sg(i) xor sg(k-i)。(这里用到了sg定理)
那么可以推算出sg(k) = mex{sg(0), sg(i), sg(i) xor sg(k - i) | i = 1..k-1}。

对于N堆石子，其sg值则为这N堆各自的sg值异或和。
*/

