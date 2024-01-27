# include<bits/stdc++.h>
using namespace std;

int main(){
	int n;

	while(cin >> n && n != 0){
		int tmp=0,x;
		int ans = 0;
		for(int i = 0;i<n;i++){
			cin >> x;
			tmp += x;
            if(tmp < 0)
                tmp = 0;
            if(tmp > ans)
                ans = tmp;
			
		}

		if(ans>0)
			cout<<"The maximum winning streak is "<<ans<<"."<<endl;
		else 
			cout<<"Losing streak."<<endl;
		
	}

}
