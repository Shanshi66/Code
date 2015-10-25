#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

map<int,string> places;

void init(){
  places[33]="Zhejiang";
  places[11]="Beijing";
  places[71]="Taiwan";
  places[81]="Hong Kong";
  places[82]="Macao";
  places[54]="Tibet";
  places[21]="Liaoning";
  places[31]="Shanghai";
}

int main(){
  init();
  int n;
  freopen("in.txt","r",stdin);
  while(scanf("%d",&n)!=EOF){
    string idNo;
    for(int i=0;i<n;i++){
      cin>>idNo;
      string place,day,month,year;
      place=places[(idNo[0]-'0')*10+(idNo[1]-'0')];
      year+=idNo[6],year+=idNo[7],year+=idNo[8],year+=idNo[9];
      month+=idNo[10],month+=idNo[11];
      day+=idNo[12],day+=idNo[13];
      cout<<"He/She is from "<<place<<",and his/her birthday is on "
          <<month<<","<<day<<","<<year<<" based on the table."<<endl;
    }
  }
  return 0;
}
