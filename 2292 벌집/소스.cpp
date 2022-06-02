#include <iostream>
#include <algorithm> 
using namespace std;

int n, m, arr[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);
    // 1 , 2~7, 8~19, 20~37, 38~61
    cin >> n;

    int i = 2, j = 5, cnt = 2;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    while (1) {
        if (i <= n && i + j >= n) {
            cout << cnt;
            break;
        }
        i = i + j + 1;
        j += 6;
        cnt++;
    }
}