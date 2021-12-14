#include <iostream>
#include <algorithm> 
using namespace std;

int n, ans;
int p[1001], t[1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            t[i] += p[j];
        }
        ans += t[i];
    }

    cout << ans;

}
