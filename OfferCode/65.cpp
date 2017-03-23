/*
题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如[a b c e s f c s a d e e]是3*4矩阵，其包含字符串"bcced"的路径，但是矩阵中不包含“abcb”路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
    	int len = strlen(str);
        if(rows * cols < len) return false;
        bool flag = false;
        vector<char> path;
        vector< vector<bool> > visit(rows, vector<bool>(cols, false));
        set<char> chars;
        for(int i = 0; i < len; i++) chars.insert(str[i]);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                flag = dfs(visit, matrix, rows, cols, i * cols + j, len, str, path, chars);
                if(flag) return flag;
            }
        }
        return flag;
    }

	bool dfs(vector< vector<bool> > &visit, const char* matrix, int rows, int cols, int index, int len, char *str, vector<char> &path, const set<char> &chars){
        if(chars.find(matrix[index]) == chars.end()) return false;
        int r = index / cols, c = index % cols;
        visit[r][c] = true;
        path.push_back(matrix[index]);
        len--;
        bool flag = false;
        if(len == 0) {
            if(compare(str, path)) flag = true;
            else flag = false;
            for(auto x : path) cout << x;
            cout << " " << string(str) << " " << flag << endl;
        } else {
            int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        	for(int i = 0; i < 4; i++) {
            	int x = r + dir[i][0], y = c + dir[i][1];
            	if(x >= rows || x < 0 || y >= cols || y < 0) continue;
            	if(visit[x][y]) continue;
            	flag = dfs(visit, matrix, rows, cols, x * cols + y, len, str, path, chars);
            	if(flag) break;
        	}
        }
        visit[r][c] = false;
        path.pop_back();
        return flag;
    }

//    bool compare(char* str, vector<char> &path){
//        map<char, int> count;
//        int len = strlen(str);
//        for(int i = 0; i < len; i++) {
//            if(count.find(str[i]) == count.end()) count[str[i]] = 1;
//            else count[str[i]] += 1;
//        }
//        for(auto x : path) {
//            if(count.find(x) == count.end()) return false;
//            else count[x]--;
//        }
//        for(auto x : count) {
//            if(x.second != 0) return false;
//        }
//        return true;
//    }
    bool compare(char *str, vector<char> &path){
        int len = strlen(str);
        for(int i = 0; i < len; i++) {
            if(str[i] != path[i]) return false;
        }
        return true;
    }
};