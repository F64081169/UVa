#include <bits/stdc++.h>
using namespace std;
 
int dp[1005][1005]; 
// longest common subsequence
//要考慮空字串
int main(){
    string s, t;
    while(getline(cin, s) && getline(cin, t)){
        for(int i = 0; i <= s.size(); i++){
            for(int j = 0; j <= t.size(); j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << dp[s.size()][t.size()] << endl;
    }
}
