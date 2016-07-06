#include <cstdio>
#include <cstdlib>
#include <iostream>
#define LC(i) (i<<1)
#define RC(i) ((i<<1)+1)

using namespace std;

const int N = 100005;
const int MOD = 9973;
int tree[N*4], n;
int res;
string str;

void buildTree(int root, int l, int r){
    int m = (l+r)/2;
    if(l+1==r){
        tree[root] = (str[l] - 28);
        return;
    }
    buildTree(LC(root), l, m);
    buildTree(RC(root), m, r);
    tree[root] = (tree[LC(root)]*tree[RC(root)])%MOD;
}

int search(int root ,int l, int r, int lq, int rq){
    if(l==lq && r==rq)return tree[root];
    int m = (l+r)/2;
    int ans;
    if(rq <= m){
        ans = search(LC(root), l, m, lq, rq);
    }
    else if(rq <= r && lq<m){
        ans = (search(LC(root), l, m, lq, m)*search(RC(root), m, r, m, rq))%MOD;
    }
    else{
        ans = search(RC(root), m, r, lq, rq);
    }
    return ans;
}

int main(){
    freopen("in.txt", "r", stdin);
    while(scanf("%d", &n)!=EOF){
        getchar();
        getline(cin, str);
        buildTree(1, 0, str.length());
        int l, r;
        for(int i=0; i<n; i++){
            scanf("%d%d",&l, &r);
            if(l>=1 && r<=str.length())res = search(1, 0, str.length(), l-1, r);
            printf("%d\n", res);
        }
    }
    return 0;
}
