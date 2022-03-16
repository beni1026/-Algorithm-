#include <iostream>
#include <algorithm> 
using namespace std;

int m;
string s[5];
string ans;
int main() {
	for (int i = 0; i < 5; i++) {
		cin >> s[i];
		int len = s[i].length();
		m = max(m,len);
	}

	for (int i = 0; i < 5; i++) {
		int cnt = (m - s[i].length());
		for (int j = 0; j < cnt; j++) {
			s[i] += '+';
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 5; j++) {
			if (s[j][i] == '+') continue;
			else ans += s[j][i];
		}	
	}

	cout << ans;
}
