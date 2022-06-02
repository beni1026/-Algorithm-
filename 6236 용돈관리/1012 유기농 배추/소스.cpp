#include <iostream>
#include <algorithm> 
using namespace std;

int t, m , n, k, arr[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[51][51];

void dfs(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == 1) {
            if (!visited[nx][ny]) {
                dfs(nx, ny);               
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        for (int i = 0; i < 51; i++) {
            memset(arr[i], 0, sizeof(int) * 51);
            memset(visited[i], 0, sizeof(bool) * 51);
        }
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            arr[b][a] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0 || visited[i][j] == 1) continue;
                dfs(i, j);
                cnt++;
            }
        }

        cout << cnt << "\n";

    }

}