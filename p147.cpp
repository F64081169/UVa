# include <bits/stdc++.h>
using namespace std;
# include <cstdio>
vector<int> price = {5,10,20,50,100,200,500,1000,2000,5000,10000};

int main(){
    float n;
    while(cin >> n && n != 0){
        unsigned long long dp[30001] = {0};
        dp[0] = 1;
        n *= 100;
        int a = n;

        for(int i = 0;i<price.size();i++){
            for(int j = price[i];j<=a;j++){
                dp[j] += dp[j-price[i]];
            }
        }
        printf("%6.2f%17llu\n",a/100.0,dp[a]);
        
    }
}
