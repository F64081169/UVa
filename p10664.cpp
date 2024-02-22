#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // ignore the newline character after n
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        vector<int> v;
        int num;
        while (iss >> num)
            v.push_back(num);

        int sum = accumulate(v.begin(), v.end(), 0);

        vector<bool> dp(sum / 2 + 1, false);
        dp[0] = true;
        for (int j = 0; j < v.size(); j++) {
            for (int k = sum / 2; k >= v[j]; k--) {
                if (dp[k - v[j]])
                    dp[k] = true;
            }
        }

        if (sum % 2 == 1 || v.size() == 1 || !dp[sum / 2])
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
