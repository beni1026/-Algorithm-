#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
#define INF 99999999
using namespace std;

int t, n, d, c;
vector<pair<int, int>> v[100002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> d >> c;
  
        memset(v, 0, sizeof(pair<int,int>)*100002);
        int x, y, z, cnt = 0, mx = -1;
        for (int i = 0; i < d; i++) {
            cin >> x >> y >> z;
            v[y].push_back(make_pair(x, z));
        }
        vector<int> dist(n + 1, INF);
        dist[c] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, c));

        while (!pq.empty()){
            pair<int,int> cur = pq.top();
            int cost = -cur.first;
            int here = cur.second;
            pq.pop();

            if (cost > dist[here]) continue;

            for (int i = 0; i < v[here].size(); i++) {
                int next = v[here][i].first;
                int nextcost = v[here][i].second;
                if (dist[next] > nextcost + cost) {
                    dist[next] = nextcost + cost;
                    pq.push(make_pair(-dist[next], next));
                }

            }
        }

        for (int i = 1; i <= n; i++) {
            if (dist[i] != INF) {
                cnt++;
                mx = max(dist[i], mx);
            }
        }

        cout << cnt << " " << mx << "\n";
    }
}
