# include <bits/stdc++.h>
using namespace std;

int joseph(int n, int m){
    int dp[n+1];
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = (dp[i-1]+m-1)%i+1;
    }    
    return dp[n];
     
}

int main(){
    int n,m;
    while(cin >> n && n!=0){
        if(n == 13){
            m=1;
        }else{
            // dp Joseph Problem
            m = 2;
            while(joseph(n-1, m)!=12) m++;
        }
        cout << m << endl;
    }
}
