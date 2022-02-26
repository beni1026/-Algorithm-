#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

vector<int> g[1001];
bool visited1[1001];
bool visited2[1001];
void dfs(int n) {
    visited1[n] = true;
    cout << n << " ";
    for (int i = 0; i < g[n].size(); i++) {
        int next = g[n][i];
        if (!visited1[next]) dfs(next);
    }
}

void bfs(int n) {
    queue<int> q;
    q.push(n);
    visited2[n] = true;
    while (!q.empty()) {
        int now = q.front();
        cout << now << " ";
        q.pop();
        for (int i = 0; i < g[now].size(); i++) {
            int next = g[now][i];
            if (!visited2[next]) {
                q.push(next);
                visited2[next] = true;
            }
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(v);
    cout << "\n";
    bfs(v);

}
