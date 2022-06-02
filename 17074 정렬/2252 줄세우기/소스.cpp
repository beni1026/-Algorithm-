#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;


int n, m;
vector<int> v[32002];
int degree[32002];
queue<int> q;
int main() {
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		degree[y]++;
	}

	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int here = q.front();
		cout <<  here << " ";
		q.pop();
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i];
			degree[next]--;
			if(degree[next] == 0) q.push(next);
		}
	}
}