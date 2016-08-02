#include <iostream>
#include <map>
#include <sstream>
#include <stdio.h>

using namespace std;

int main(){
	map<string, string> mapper;
	string str;
	bool flag = false;
    while(getline(cin, str)){
		if(str != ""){
			if(flag){
				if(mapper.find(str) == mapper.end()) cout << "eh" << endl;
				else cout << mapper[str] << endl;
			}else{
				string a, b;
				istringstream str_input(str);
				str_input >> a >> b;
				mapper[b] = a;
			}
		}else flag = true;
    }
    return 0;
}