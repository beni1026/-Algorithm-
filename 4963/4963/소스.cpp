#include <iostream>
#include <algorithm> 
#include <vector> 
using namespace std;

int w, h, arr[55][55];
int dx[8] = { 0,0, 1, -1, -1, 1, -1, 1 };
int dy[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
vector<int> v;

int bfs(int x, int y) {
    if (arr[x][y] != 1) return 0;

    arr[x][y] += 1;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < h && ny < w && arr[nx][ny] == 1) {
            bfs(nx, ny);
        }
    }

    return 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int ans = 0;
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        for (int i = 0; i < 55; i++) {
            memset(arr[i], 0, sizeof(int) * 55);
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (arr[i][j] == 1) {
                    ans += bfs(i, j);

                }
            }
        }

        cout << ans << "\n";

    }


}
