# include<bits/stdc++.h>
using namespace std;

int main(){
	int left = 0,right = 0;
	int num = 0;
	string input = "";
	int case_cnt = 1;

	while(cin >> input && input[1] != ' '){
		cin >> num;
		cout<<"Case "<<case_cnt<<":"<<endl;
		case_cnt++;
		for(int i = 0;i<num;i++){
			cin>>left>>right;
			if(left>right){
				int tmp = left;
				left = right;
				right = tmp;
			}
			char c = input[left];
			bool flag = false;
			for(int l=left;l<=right;l++){
				if(input[l]!=c){
					flag = true;
					break;
				}
			}
			if(!flag) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}
