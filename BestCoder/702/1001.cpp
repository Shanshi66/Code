#include <cstdio>
#include <cstdlib>
#include <iostream>
#define LC(i) (i<<1)
#define RC(i) ((i<<1)+1)

using namespace std;

const int N = 100005;
int arr[N], n, res;

struct TreeNode{
    int seg_max, seg_min;
};
TreeNode tree[N*4];

void buildTree(int root, int l, int r){
    int m = (l+r)/2;
    if(l+1==r){
        tree[root].seg_max = tree[root].seg_min = arr[l];
        return;
    }
    buildTree(LC(root), l, m);
    buildTree(RC(root), m, r);
    tree[root].seg_max = max(tree[LC(root)].seg_max, tree[RC(root)].seg_max);
    tree[root].seg_min = min(tree[LC(root)].seg_min, tree[RC(root)].seg_min);
}

TreeNode search(int root ,int l, int r, int lq, int rq){
    if(l==lq && r==rq)return tree[root];
    int m = (l+r)/2;
    TreeNode ans;
    if(rq <= m){
        ans = search(LC(root), l, m, lq, rq);
    }
    else if(rq <= r && lq<m){
        TreeNode lnode = search(LC(root), l, m, lq, m);
        TreeNode rnode = search(RC(root), m, r, m, rq);
        ans.seg_max = max(lnode.seg_max, rnode.seg_max);
        ans.seg_min = min(lnode.seg_min, rnode.seg_min);
    }
    else{
        ans = search(RC(root), m, r, lq, rq);
    }
    return ans;
}

int main(){
    freopen("in.txt", "r", stdin);
    while(scanf("%d", &n)!=EOF){
        for(int i=0; i<n; i++)scanf("%d", &arr[i]);
        buildTree(1, 0, n);
        int r;
        for(int i=0; i<n; i++){
            TreeNode tmp = search(1, 0, n, 0, i);
            printf("%lld\n", (long long)tmp.seg_max*tmp.seg_min);
        }
    }
    return 0;
}
