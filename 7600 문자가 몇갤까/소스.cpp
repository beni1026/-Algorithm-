#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

	while (1) {
		string s;
		getline(cin, s);
		if (s[0] == '#' && s.length()==1) break;
		int cnt[26] = { 0, };
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			s[i] = tolower(s[i]);
			cnt[s[i] - 97]++;
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i]) ans++;
		}
		cout << ans << "\n";
	}
}
