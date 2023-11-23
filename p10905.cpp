#include <bits/stdc++.h>
using namespace std;

bool cmp(string x,string y){
	return x+y > y+x;
}
int main(){
	int num;
	while(num !=0){
		cin >> num;
		
		vector<string> rec;
		for(int i = 0;i<num;i++){
			
			string str;
			cin >> str;
			rec.push_back(str);

			
		}
		sort(rec.begin(),rec.end(),cmp);

		for(int j = 0;j<rec.size();j++)
			cout<<rec[j];
		if(num != 0) 
			cout << endl;
	}
}
