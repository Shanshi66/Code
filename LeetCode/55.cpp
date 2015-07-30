/*
  给你一个数组，从前往后跳，每个位置上都给定最大能跳的步数，问能否跳到最后
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int len=nums.size();
    bool *flag=new bool[len*2];
    for(int i=0;i<len;i++)flag[i]=false;
    int b=0;
    if(nums[0]||len==1)flag[0]=true;
    else return false;
    for(int i=0;i<len-1;i++){
      if(flag[i]){
        int j=b+1;
        for(;j<=i+nums[i];j++){
          flag[j]=true;
          if(j==len-1)return true;
        }
        if(i+nums[i]>b)b=i+nums[i];
      }
    }
    if(flag[len-1])return true;
    else return false;
    delete [] flag;
  }
};

int main(){
  freopen("in.txt","r",stdin);
  int n;
  cin>>n;
  vector<int> v;
  for(int i=0;i<n;i++){
    int temp;
    cin>>temp;
    v.push_back(temp);
  }
  Solution ans;
  cout<<ans.canJump(v)<<endl;
  return 0;
}

