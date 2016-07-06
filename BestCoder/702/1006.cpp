#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 8005;
int n, arr[N];
int cnt[N];

int main(){
    freopen("in.txt", "r", stdin);
    while(scanf("%d\n", &n)!=EOF){
        for(int i=0; i<n; i++)cnt[i]=0;
        for(int i=0; i<n; i++)scanf("%d",&arr[i]);
        for(int i=0; i<n;i++){
            for(int j=i+1; j<=n; j++){
                if(((j-i+1)&1)==0)continue;
                else{
                    int tmp[j-i];
                    for(int s=0, k=i; k<j; k++){
                        tmp[s++]=arr[k];
                    }
                    sort(tmp, tmp+j-i);
                    int md = tmp[(j-i)/2];
                    for(int k=i; k<j; k++){
                        if(arr[k]==md)cnt[k]++;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            printf("%d\n", cnt[i]);
        }
    }
    return 0;
}
