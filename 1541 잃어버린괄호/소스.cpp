#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;

string s;
int ans;
int main() {
	cin >> s;
	bool flag = 0;

	string num;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] == '-' || s[i] == '+' || i == s.size()) {
			if (flag == 1) {
				ans -= stoi(num);
				num = "";
			}
			else {
				ans += stoi(num);
				num = "";
			}
		}
		else {
			num += s[i];
		}


		// - ��ȣ�� ���� �ڴ� ��� �׳� �������ָ��
		if (s[i] == '-') {
			flag = 1;
		}	
	}

	cout << ans;
}
