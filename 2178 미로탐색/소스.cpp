#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

int n, m, arr[101][101];
int dx[] = { 0, 0 , 1, -1 };
int dy[] = { 1, -1, 0 , 0 };

int bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 0) continue;
            else {
                if (arr[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    arr[nx][ny] = arr[x][y] + 1;
                }
            }
        }
    }
    return arr[n - 1][m - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &arr[i][j]);
        }
    }

    
    cout << bfs(0, 0);

}