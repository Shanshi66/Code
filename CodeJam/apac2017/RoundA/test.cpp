#include<bits/stdc++.h>
using namespace std;
int R, C;
int H[64][64];
bool v[64][64];

int cnt, h;
bool out;

void dfs(int i, int j) {
	if(!i || !j || i > R || j > C || h <= H[i][j] || v[i][j] ) return;
	if(i == 1 || j == 1 || R == i || j == C)
		out = true;
	v[i][j] = true;
	++cnt;
	dfs(i, j -1);
	dfs(i-1, j);
	dfs(i + 1, j);
	dfs(i, j+1);
}

int solve() {
	cin >> R >> C;
	memset(H, 0, sizeof(H));
	for(int i = 1; i <= R; ++i)
		for(int j = 1; j <= C; ++j)
			cin >> H[i][j];
	int res = 0;
	for(h = 2; h <= 1000; ++h) {
		memset(v, 0, sizeof(v));
		for(int i = 2; i < R; ++i)
			for(int j = 2; j < C; ++j)
				if(h > H[i][j] && !v[i][j]) {
					cnt = 0;
					out = false;
					dfs(i, j);
					if(!out) res += cnt;
				}
	}
	return res;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("ans1.out", "w", stdout);
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i)
		cout << "Case #" << i << ": " << solve() << endl;
}
