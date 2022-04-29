#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int n, k, ans;
vector<pair<pair<int, int>, pair<int, int>>> v;

bool op(const pair<pair<int, int>, pair<int, int>>& a, pair<pair<int, int>, pair<int, int>>& b) {
    if (a.first.second == b.first.second) {
        if (a.second.first == b.second.first) {
            return a.second.second > b.second.second;
        }
        else return a.second.first > b.second.first;
    }
    else return a.first.second > b.first.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int k, g, s, b;
        cin >> k >> g >> s >> b;
        v.push_back(make_pair(make_pair(k, g), make_pair(s, b)));
    }

    sort(v.begin(), v.end(), op);

    //for (int i = 0; i < n; i++) {    
    //    cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second.first << " " << v[i].second.second << endl;
    //}

    for (int i = 0; i < n; i++) {
        if (k == v[i].first.first) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                else {
                    if (v[i].first.second == v[j].first.second) {
                        if (v[i].second.first == v[j].second.first) {
                            if (v[i].second.second == v[j].second.second) {
                                cout << j + 1;
                                return 0;
                            }
                        }
                    }
                }
            }
            cout << i + 1;
        }
    }



}
