#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> 
using namespace std;

int t;
vector<int> adj[20002];
int visited[20002];

void dfs(int n) {
    if (!visited[n]) {
        visited[n] = 1;
    }
    for (int i = 0; i < adj[n].size(); i++) {
        int next = adj[n][i];
        if (!visited[next]) {
            if (visited[n] == 1) {
                visited[next] = 2;
            }
            else if (visited[n] == 2) {
                visited[next] = 1;
            }
            dfs(next);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;

        
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) dfs(i);
        }

        bool ans = true;
        for (int i = 1; i <= v; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int next = adj[i][j];
                if (visited[i] == visited[next]) {
                    ans = false;
                    break;
                }
            }
        }

        if (ans == true) cout << "YES" << "\n";
        else cout << "NO" << "\n";

        for (int i = 0; i <= v; i++) {
            adj[i].clear();
        }

        memset(visited, 0, 20002 * sizeof(int));

    }
}