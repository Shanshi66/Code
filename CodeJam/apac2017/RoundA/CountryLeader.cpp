#include <bits/stdc++.h>

using namespace std;

struct Person{
    string name;
    int cnt;
};

bool cmp(const Person &a, const Person &b){
    if(a.cnt != b.cnt)return a.cnt > b.cnt;
    else return a.name < b.name;
}

int main(){
    freopen("A-large-practice.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int t, tcase = 0;
    cin >> t;
    while(t--){
        tcase++;
        int n;
        cin >> n;
        getchar();
        vector<Person> persons(n);
        for(int i = 0; i < n; i++){
            int len; set<char> stat;
            getline(cin, persons[i].name);
            len = persons[i].name.length();
            for(int j = 0; j < len; j++){
                if(persons[i].name[j]!=' ')
                    stat.insert(persons[i].name[j]);
            }
            persons[i].cnt = stat.size();
        }
        sort(persons.begin(), persons.end(), cmp);
        cout << "Case #" << tcase << ": " <<persons[0].name << endl;
    }
}
