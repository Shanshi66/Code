#include <bits/stdc++.h>

using namespace std;

/*
Nim游戏是经典的公平组合游戏(ICG)，对于ICG游戏我们有如下定义：
1、两名选手；
2、两名选手轮流行动，每一次行动可以在有限合法操作集合中选择一个；
3、游戏的任何一种可能的局面(position)，合法操作集合只取决于这个局面本身；局面的改变称为“移动”(move)。
4、若轮到某位选手时，该选手的合法操作集合为空，则这名选手判负。

对于第三条，我们有更进一步的定义Position，我们将Position分为两类：
P-position：在当前的局面下，先手必败。
N-position：在当前的局面下，先手必胜。

他们有如下性质：
1.合法操作集合为空的局面是P-position；
2.可以移动到P-position的局面是N-position；
3.所有移动都只能到N-position的局面是P-position。

在这个游戏中，我们已经知道A[] = {0,0,...,0}的局面是P局面，那么我们可以通过反向枚举来推导出所有的可能局面，总共的状态数量为A[1]*A[2]*...*A[N]。并且每一次的状态转移很多。
虽然耗时巨大，但确实是一个可行方法。

当然，我们这里会讲这个题目就说明肯定没那么复杂。没错，对于这个游戏有一个非常神奇的结论：

对于一个局面，当且仅当A[1] xor A[2] xor ... xor A[N] = 0时，该局面为P局面。

对于这个结论的证明如下：
1. 全0状态为P局面，即A[i]=0，则A[1] xor A[2] xor ... xor A[N] = 0。
2. 从任意一个A[1] xor A[2] xor ... xor A[N] = k != 0的状态可以移动到A[1] xor A[2] xor ... xor A[N] = 0的状态。由于xor计算的特殊性，我们知道一定有一个A[i]最高位与k最高位的1是相同的，那么必然有A[i] xor k < A[i]的，所以我们可以通过改变A[i]的值为A[i]'，使得A[1] xor A[2] xor ... xor A[i]' xor ... xor A[N] = 0。
3. 对于任意一个局面，若A[1] xor A[2] xor ... xor A[N] = 0，则不存在任何一个移动可以使得新的局面A[1] xor A[2] xor ... xor A[N] = 0。由于xor计算的特殊性，我们可以知道，一定是存在偶数个1时该位置的1才会被消除。若只改变一个A[i]，无论如何都会使得1的数量发生变化，从而导致A[1] xor A[2] xor ... xor A[N] != 0。
以上三条满足ICG游戏中N,P局面的转移性质，所以该结论的正确性也得到了证明。

*/

int main(){
    int sum = 0, stone_num, n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> stone_num;
        sum = sum ^ stone_num;
    }
    if(sum == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
    return 0;
}