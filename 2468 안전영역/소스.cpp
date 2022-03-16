#include <iostream>
#include <algorithm> 
#include <string>
#include <queue>
using namespace std;

int n, m, ans = -1e9;
int arr[102][102];
bool visited[102][102];

int dx[] = { 0, 0, 1, -1 }; //동서남북
int dy[] = { 1, -1, 0, 0 }; //동서남북

int bfs(int i, int j) {
    if (visited[i][j] == 1 || arr[i][j] <= 0) return 0;
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push(make_pair(i, j));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (arr[nx][ny] <= 0 || nx < 0 || ny < 0 || nx >= n || ny >= n) {
                continue;
            }
            else {
                if (!visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            arr[i][j]++;
        }
    }




    while (true) {
        int num = 0;
        bool flag = false;

        // 1년이 지났을 때
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j]--;
            }
        }

        //다 잠겼는지 확인
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > 0) flag = 1;
            }
        }

        // 다 잠겼으면 종료
        if (flag == 0) break;



        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (bfs(i, j) == 0) continue;
                else {
                    num++;
                }
            }
        }

        ans = max(num, ans);

        //방문배열 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }
    }

    cout << ans;

}
