#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    // make prime table
    vector<int> prime;
    for(int i = 2;i<=35000;i++){
        bool isPrime = true;
        for(int j = 2;j<=sqrt(i);j++){
            if(i%j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            prime.push_back(i);
        }
    }
    // start program
    while (cin >> n && n != 0) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans = (ans + prime[n-i]) % i;
        }
        cout << ans +1<< endl;
    }
}
