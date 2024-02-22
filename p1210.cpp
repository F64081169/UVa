# include <bits/stdc++.h>

using namespace std;
int main(){
    // build prime table
    vector<int> prime;
    for(int i = 2;i<10000;i++){
        bool is_prime = true;
        for(int j = 2;j*j<=i;j++){
            if(i%j==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            prime.push_back(i);
        }
    }
    int n;
    // sliding window  
    while(cin>>n && n!=0){
        int sum = 0,ans = 0,left = 0;
        for(int i = 0;prime[i] <= n;i++){
            sum += prime[i];
            while(sum > n)
                 sum -= prime[left++];
            if(sum == n)
                ans++;
        }
        cout<<ans<<endl;
    }
}
