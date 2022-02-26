#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
int main() {
    int n, cnt=0;
    bool chk;
    cin >> n;
    vector<pair<int, int> > p(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p[i].first = a; 
        p[i].second = b;
    }
    for (int i = 0; i < n; i++) {
        chk = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (p[i].first > p[j].first) {
                    if (p[i].second >= p[j].second) {
                        chk = 1;
                        break;
                    }
                }
                else if (p[i].second > p[j].second) {
                    if (p[i].first >= p[j].first) {
                        chk = 1;
                        break;
                    }
                }
            }
        }
        if (!chk) cnt++;
    }
    cout << cnt;
}
