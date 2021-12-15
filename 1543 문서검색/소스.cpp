#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int cnt = 0;
    int pos = 0;
    int i = 0;
    while (s1.find(s2, pos) != string::npos) {
        cnt++;
        pos = s1.find(s2, pos) + s2.length();
    }
    cout << cnt;
}
