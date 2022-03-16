#include <iostream>
#include <algorithm> 
#include <string>
#include <queue>
using namespace std;

int n, arr[26][26], cnt;
bool v[26][26];
int dx[] = { 0, 0 , 1, -1 };
int dy[] = { 1, -1, 0 , 0 };
vector<int> vec;

int bfs(int i, int j) {
    int ans = 1;
    if (v[i][j] == 1 || arr[i][j] == 0) return 0;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    v[i][j] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] == 0) continue;
            else {
                if (arr[nx][ny] == 1 && v[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    v[nx][ny] = 1;
                    ans++;
                }
            }
        }
    }
    vec.push_back(ans);
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n;
    string k[1001];
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = k[i].at(j) - 48;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bfs(i, j) == 0) continue;
            else {
                cnt++;
                bfs(i, j);
            }
        }
    }
    cout << cnt << "\n";
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\n";
    }


}
