#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int m, n, k, arr[101][101], ans;
vector<int> cnt;
bool v[101][101];

int dx[] = { 0, 0, 1, -1 };   //µ¿¼­³²ºÏ
int dy[] = { 1, -1, 0, 0 };


int t = 1;
int dfs(int sx, int sy) {
    if (arr[sx][sy] == 1 || v[sx][sy] == 1) return 0;
    v[sx][sy] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || arr[nx][ny] == 1) continue;
        else {
            if (!v[nx][ny]) {
                t++;
                dfs(nx, ny);
            }
        }
    }
   

    return 1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int x = b; x < d; x++) {
            for (int y = a; y < c; y++) {
                arr[x][y] = 1;
            }
        }
    }
    //for (int i = 0; i < m; i++) {
    //    for (int j = 0; j < n; j++) {
    //        cout << arr[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(i, j) == 1) {
                //cout << i << "," << j << endl;
                cnt.push_back(t);
                t = 1;
                ans++;
            }
            else continue;
        }
    }

    
    cout << ans << endl;

    sort(cnt.begin(), cnt.end());
    for (int i = 0; i < cnt.size(); i++) {
        cout << cnt[i] << " ";
    }
    
    

    


}
