#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;

	while(cin >> n){
		vector<int> v(n);
		for(int i = 0;i<n;i++){
			cin >> v[i];
		}
		sort(v.begin(),v.end());
		int cnt;
		if(n%2 == 0){
			cout<<v[(n-1)/2]<<" ";
			cnt = 0;
			for(int i = 0;i<n;i++){
				if(v[i] == v[(n-1)/2]) cnt++;
				if(v[i] == v[n/2] && v[n/2]!=v[(n-1)/2]) cnt++;
			}
			if(v[n/2] == v[(n-1)/2]) cout<<cnt<<" 1"<<endl;
			else cout<<cnt<<" "<<v[n/2]-v[(n-1)/2]+1<<endl;
		}
		else{
			cout<<v[(n-1)/2]<<" ";	
			cnt = 0;
			for(int i = 0;i<n;i++){
				if(v[i] == v[(n-1)/2]) cnt++;
			}
			cout<<cnt<<" 1"<<endl;
		}
	}
}
