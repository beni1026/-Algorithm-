#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int n, cnt[5001], ans;
vector<pair<int, int>> v;\

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b, a)); //»ö±ò, ÁÂÇ¥·Î ÀúÀå
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (v[i+1].first == v[i].first) {
                cnt[i] = v[i+1].second - v[i].second;
            }
            else {
                cnt[i] = 0;
            }
            
        }
        else if(i>0 && i<n-1){
            if (v[i + 1].first == v[i].first) {
                if (v[i].first == v[i - 1].first) {
                    cnt[i] = min(v[i].second - v[i - 1].second, v[i + 1].second - v[i].second);
                }
                else {
                    cnt[i] = v[i + 1].second - v[i].second;
                }
            }
            else if(v[i].first == v[i - 1].first) {
                cnt[i] = v[i].second - v[i - 1].second;
            }
            else {
                cnt[i] = 0;
            }       
        }
        else {
            if (v[i].first == v[i-1].first) {
                cnt[i] = v[i].second - v[i - 1].second;
            }
            else {
                cnt[i] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans += cnt[i];
    }

    cout << ans;
}
