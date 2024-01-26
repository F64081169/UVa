#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> ans(51);
	ans[0]=1;
	ans[1]=1;
	for(int i = 2;i<51;i++)
		ans[i] = ans[i-1]+ans[i-2];

	int input = 0;
	while(cin >> input && input != 0){
		cout<<ans[input]<<endl;
	}
}
