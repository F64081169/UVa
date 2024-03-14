#include <iostream>
using namespace std;
 
unsigned int n, l, u, ans;
 
int main() {
    while (cin >> n >> l >> u){
        ans = 0;
        for (int i = 31; i >= 0; i--){
            if ((ans | (1<<i)) > u) continue;
            if ((ans | (1<<i)) <= l || !(n & (1<<i))){
                ans |= (1<<i);
            }
        }
        cout << ans << "\n";
    }
}
