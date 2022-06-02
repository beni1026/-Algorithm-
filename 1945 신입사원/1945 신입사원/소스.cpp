#include <iostream>
#include <algorithm> 
using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        pair<int, int> p[100002];
        for (int i = 0; i < n; i++) {         
            cin >> p[i].first >> p[i].second;
        }
        sort(p, p + n);

        int m = p[0].second;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            m = min(m, p[i].second);
            if (m < p[i].second) {
                cnt++;
            }
        }
        cout << n-cnt << endl;
    }

}
