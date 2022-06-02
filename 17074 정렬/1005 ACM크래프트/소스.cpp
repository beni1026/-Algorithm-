#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

int t;
int main() {
	cin >> t;
	while (t--) {
		int n, k, d[1002], w, ans[1002];
		vector<int> v[1002];
		int len[32002] = { 0, };
		queue<int> q;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> d[i];
			ans[i] = d[i];
		}
		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			v[x].push_back(y);
			len[y]++;
		}
		for (int i = 1; i <= n; i++) {
			if (len[i] == 0) q.push(i);
		}
		cin >> w;

		while (!q.empty()) {
			int now = q.front();
			cout << now << "¹æ¹®ÇÔ ";
			q.pop();
			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i];
				if (ans[now] + d[next] > ans[next]) {
					ans[next] = ans[now] + d[next];
				}
				len[next]--;
				if (len[next] == 0) {
					q.push(next);
				}
			}
		}

		cout << ans[w] << "\n";

	}

}