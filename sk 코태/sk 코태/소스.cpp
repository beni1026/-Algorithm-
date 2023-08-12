#include <string>
#include <iostream>
#include <algorithm> 

#include <vector>

using namespace std;


int money[300005];
vector<int> solution(int n, vector<string> plans, vector<string> clients) {
    vector<int> answer;
    int c_len = clients.size();
    vector<vector <int>> service(n, vector <int>(n, 0));
    for (int i = 0; i < c_len; i++) {
        answer.push_back(0);
    }

    for (int i = 0; i < plans.size(); i++) {
        int idx = 0;
        for (int j = 0; j < plans[i].size(); j++) {
            if (plans[i][j] == ' ' || j == plans[i].size()-1) {
                int num = stoi(plans[i].substr(idx, j));
                cout << num << " ";
                if (idx == 0) {
                    money[i] = num;
                    idx = j + 1;
                    continue;
                }
                for (int k = i; k < plans.size(); k++) {
                   service[k][num] = 1;
                }
                idx = j + 1;
            }
        }
    }
    for (int i = 0; i < c_len; i++) {
        int c_money, idx = 0;
        bool c_service[300000] = { 0, };
        for (int j = 0; j < c_len; j++) {
            if (clients[i][j] == ' ' || j == c_len - 1) {
                int num = stoi(clients[i].substr(idx, j - 1));
                if (idx == 0) {
                    c_money = num;
                    idx = j + 1;
                    continue;
                }
                c_service[i] = true;
                idx = j + 1;
            }
        }

        bool chk = 1;
        for (int j = 0; j < clients.size(); j++) {
            if (c_money >= money[j]) {
                for (int l = 0; l < n; l++) {
                    if (service[j][l] == 0 && c_service[l] == 1) {
                        chk = 0;
                        break;
                    }
                }
            }
            if (chk == 1) {
                answer[i] = j + 1;
                break;
            }
        }
    }
    
    return answer;
}

int main() {
    vector<string> plans = { "100 1 3", "500 4", "2000 5" };
    vector<string> clients = { "300 3 5", "1500 1", "100 1 3", "50 1 2" };
    solution(5, plans, clients);
}