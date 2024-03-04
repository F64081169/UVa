#include <bits/stdc++.h>
using namespace std;
// rod cutting problem
int dp[55][55];
vector<int> price(55);

int solve(int l,int r){
    if(l+1 == r) return 0;
    if(dp[l][r] != 0) return dp[l][r];
    int ans = 1e9;
    for(int i = l+1;i<r;i++){
        ans = min(ans,solve(l,i)+solve(i,r)+price[r]-price[l]);
    }
    return dp[l][r] = ans;
}
int main(){
    int length, num;
    
    while(cin >> length && length != 0){
        cin >> num;
         for(int i = 0;i<=num+1;i++){
            price[i] = 0;
            for(int j = 0;j<=num+1;j++){
                dp[i][j] = 0;
            }
        }
        
        price[0] = 0;
        price[num+1] = length;
        for(int i = 1;i<=num;i++){
            cin >> price[i];
        }

        cout <<"The minimum cutting is "<< solve(0,num+1)<<"." << endl;
    }
    return 0;
}
