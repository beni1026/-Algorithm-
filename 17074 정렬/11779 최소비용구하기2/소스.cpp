#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
#define INF 1e9
using namespace std;

int n, m, st, ed, route[1003];
vector<pair<int, int>> v[1003];
vector<int> ans;	
int main() {
	cin >> n >> m;

	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		v[x].push_back(make_pair(y, z));
	}

	cin >> st >> ed;
	vector<int> dist(n+1, INF);
	dist[st] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, st));


	while (!q.empty()) {
		pair<int, int> cur = q.top();
		int here = cur.second;
		int cost = -cur.first;

		//cout << here << " ";
		q.pop();

		if(cost > dist[here]) continue;
		if (here == ed) break;

		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].first;
			int nextcost = v[here][i].second;

			if (dist[next] > nextcost + cost) {
				route[next] = here; //만약에 업데이트 되면 route에 저장되는 값은 전 인덱스 값이다.
				dist[next] = nextcost + cost;
				
				q.push(make_pair(-dist[next], next));
			}
		}

	}

	cout << dist[ed] << "\n";
	
	int t = ed;
	while (t) {
		ans.push_back(t);
		t = route[t]; //route에 저장 된 값은 전 인덱스 값이므로 t가 0이 될때까지 경로를 찾음
	}
	cout << ans.size() << "\n";

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
}