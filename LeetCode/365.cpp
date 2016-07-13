#include <iostream>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) return true;
        if (z > x + y) return false;
        if (x > y) swap(x, y);
        if (x == 0) {
            if (x + y == z) return true;
            else return false;
        }
        int n = y / x, tmp = y;
        // X往Y里倒
        if((z % x == 0) && (z / x <= n + 1))return true;
        // Y往X里倒
        bool vis[x];
        for(int i = 0; i < x; i++) vis[i] = false;
        while(1){
            if(z == tmp) return true;
            if(tmp < x) {
                if(vis[x - tmp])break;
                vis[x - tmp] = true;
                if(tmp + y == z) return true;
                tmp = y - (x - tmp);
                if(tmp == z) return true;  
            }else tmp -= x;
        }
        return false;
    }
};

int main(){
    Solution a;
    cout << a.canMeasureWater(34, 5, 6) << endl;
    return 0;
}