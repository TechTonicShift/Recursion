#include <iostream>
#include <vector>

using namespace std;

void solution(int i, int n, int k, int rssf, vector<vector<int>>& ans, int& counter) {
    if (i == n + 1) {
        if (rssf == k) {
            cout << counter << ". ";
            counter++;
            for (const vector<int>& a : ans) {
                cout << "[";
                for (int num : a) {
                    cout << num << " ";
                }
                cout << "] ";
            }
            cout << endl;
        }
        return;
    }

    for (int j = 0; j < ans.size(); j++) {
        if (ans[j].empty()) {
            ans[j].push_back(i);
            solution(i + 1, n, k, rssf + 1, ans, counter);
            ans[j].pop_back();
            break;
        } else {
            ans[j].push_back(i);
            solution(i + 1, n, k, rssf, ans, counter);
            ans[j].pop_back();
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> ans(k);
    int counter = 1;

    solution(1, n, k, 0, ans, counter);

    return 0;
}
