#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int n, m, k, arr[301][301];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> k;
    for (int t = 0; t < k; t++) {
        int ans = 0;
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        for (int a = i; a <= x; a++) {
            for (int b = j; b <= y; b++) {
                ans += arr[a][b];
            }
        }
        cout << ans << "\n";
    }

}
