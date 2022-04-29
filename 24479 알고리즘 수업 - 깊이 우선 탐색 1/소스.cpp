#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;


int n, m, r;
vector<int> v[100001];
bool visited[100001];
int ans[100001];

int cnt = 1;
void dfs(int r) {
    visited[r] = true;
    ans[r] = cnt;
    for (int i = 0; i < v[r].size(); i++) {
        int n = v[r][i];
        if (!visited[n]) {
            cnt++;
            dfs(n);
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
        sort(v[i].begin(), v[i].end(), greater<>());
    }

    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }

}
