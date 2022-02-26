#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

int n, m, cnt;
vector<int> v[1001];
bool visited[1001];

int bfs(int n) {
	if (visited[n] == 1) return 0;
	queue<int> q;
	visited[n] = true;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = 1;
			}
		}
	}
	return 1;
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

	for (int i = 1; i <= n; i++) {
		cnt += bfs(i);
	}
	cout << cnt;

}