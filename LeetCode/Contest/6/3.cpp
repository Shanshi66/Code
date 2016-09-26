class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first != b.first) return a.first < b.first;
        else return a.second < b.second;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        int size = people.size();
        for(int i = size - 1; i >= 0; i--){
            for(int j = i - 1; j >= 0; j--){
                if(people[j].first < people[i].first) break;
                people[i].second--;
            }
        }
        for(int i = size - 1; i >= 0; i--){
            if(people[i].second == 0) continue;
            else{
                move(people, i, people[i].second);
            }
        }
        for(int i = size - 1; i >= 0; i--){
            people[i].second = 0;
            for(int j = i - 1; j >= 0; j--){
                if(people[j].first >= people[i].first) people[i].second++;
            }
        }
        return people;
    }
    void move(vector< pair<int, int> > &arr, int index, int offset){
        pair<int, int> tmp;
        tmp = arr[index];
        for(int i = index + 1; i <= index + offset; i++){
            arr[i - 1] = arr[i];
        }
        arr[index + offset] = tmp;
    }
};