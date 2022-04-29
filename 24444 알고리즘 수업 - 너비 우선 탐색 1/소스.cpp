#include <iostream>
#include <algorithm> 
#include <queue>
#include <vector>
using namespace std;


int n, m, r;
vector<int> v[100001];
bool visited[100001];
int ans[100001];

int cnt = 1;
void bfs(int r) {
    visited[r] = true;
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
        int n = q.front();
        ans[n] = cnt;
        cnt++;
        q.pop();
        for (int i = 0; i < v[n].size(); i++) {
            int next = v[n][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }    
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    bfs(r);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }

}
