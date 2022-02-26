#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int n, a, b, m, ans;
vector<int> v[101];
bool visited[101];

void dfs(int n) {
    visited[n] = true;
    cout << n << " ";
    for (int i = 0; i < v[n].size(); i++) {
        int next = v[n][i];
        if (!visited[next]) dfs(next);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(a, b, 0);
    if (ans != 0) {
        cout << ans;
    }
    else cout << "-1";
}
