#include <bits/stdc++.h>
using namespace std;

int main(){
	int num;
	map<string,int> m;
	vector<int> all_course(5);

	while(cin>>num && num!=0){
		m.clear();
		for(int i = 0;i<num;i++){
			for(int j=0;j<5;j++){
				int course;
				cin>>course;
				all_course[j]=course;
			}
			
			sort(all_course.begin(),all_course.end());
			string all_c="";
			
			for(int j=0;j<5;j++){
				all_c+=to_string(all_course[j]);
			}
			
			if(m.find(all_c)==m.end())
				m[all_c]=1;
			else
				m[all_c]++;
		} 

		int max = 0;
		int accumulate_max = 0;
		for(auto it = m.begin();it!=m.end();it++){
			if(it->second > max){
				max = it->second;
				accumulate_max=it->second;
			}
			else if(it->second == max){
				accumulate_max+=it->second;
			}
		}				
		cout<<accumulate_max<<endl;
	}
}
