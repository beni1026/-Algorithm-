#include <iostream>
#include <algorithm> 
#include <queue>
using namespace std;

#define INF 987654321
int v, e, k;
vector<pair<int, int>> graph[20010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> v >> e >> k;

    int x, y, w;
    for (int i = 0; i < e; i++) {
        cin >> x >> y >> w;
        graph[x].push_back(make_pair(y, w));
    }


    vector<int> dist(v + 1, INF);
    priority_queue<pair<int, int>> pq;
    dist[k] = 0;
    pq.push(make_pair(0, k));

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        int cost = -cur.first; //가중치
        int here = cur.second; //다음번 원소
        pq.pop();

        if (cost > dist[here]) continue;

        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here][i].first;
            int nextcost = graph[here][i].second;
            if (dist[next] > nextcost + cost ){
                dist[next] = nextcost + cost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    for (int i = 1; i < v + 1; i++) {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    return 0;
}
