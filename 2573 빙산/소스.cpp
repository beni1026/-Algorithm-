#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

int n, m, ans=1;
int arr[301][301];
int new_arr[301][301];
bool visited[301][301];

int dx[] = { 0, 0, 1, -1 }; //동서남북
int dy[] = { 1, -1, 0, 0 }; //동서남북

int bfs(int i, int j) {
    if (visited[i][j] == 1 || new_arr[i][j] <=0) return 0;
    queue<pair<int,int>> q;
    visited[i][j] = true;
    q.push(make_pair(i,j));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (new_arr[nx][ny] == 0 || nx < 0 || ny < 0) {
                continue;
            }
            else {
                if (!visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int num; //연결 요소의 개수
    while (true) {
        num = 0;

        // 1년이 지났을 때
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (arr[i][j] == 0 || nx < 0 || ny < 0) {
                        continue;
                    }
                    else {
                        if (arr[nx][ny] == 0) {
                            cnt++;
                        }
                    }
                }
                if (arr[i][j] - cnt < 0) {
                    new_arr[i][j] = 0;
                }
                else {
                    new_arr[i][j] = arr[i][j] - cnt;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (bfs(i, j) == 1) {
                    num++;
                }
            }
        }

        //배열 바꿈
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = new_arr[i][j];
            }
        }
        //방문배열 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = 0;
            }
        }

        if (num == 0) {
            ans = 0;
            break;
        }

        if (num >= 2) break;
        else ans++;

    }
    cout << ans;

}
