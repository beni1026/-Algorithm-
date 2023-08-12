#include <iostream>
#include <string>
using namespace std;

int public_pwd, n;
int pwd_arr[105][2];
string user;
int main() {
	cin >> public_pwd >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pwd_arr[i][0] = a;
		pwd_arr[i][1] = b;
	}

	cin >> user;

	for (int i = 0; i < user.length();i++) {
		if (user[i] == '*') {

		}
	}
	
	return 0;
}