#include <bits/stdc++.h>

using namespace std;

int catalan_number(int n){
    if(n==0) return 1;
    else {
        long long result = 1;
        for (int i = 0; i < n; ++i) {
            result *= (2*n - i);
            result /= (i + 1);
        }
        return result / (n + 1);
    }
}


int main(){
	int input,ans;
	bool first = false;

	while(cin >> input){
		if(!first) first = true;
		else cout<<endl;
		ans = catalan_number(input);
		cout << ans << endl;		
	}
}
