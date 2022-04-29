#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int n, m, ans;
vector<int> v[101];
bool visited[101];

void dfs(int st) {
	visited[st] = 1;
	ans++;
	for (int i = 0; i < v[st].size(); i++) {
		int next = v[st][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	cout << ans-1;
}