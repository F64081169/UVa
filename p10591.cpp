#include <bits/stdc++.h>
using namespace std;

int main(){
	int round;
    int count = 1;
    cin >>round;
    for(int j = 0;j<round;j++){
            int num;
            cin >> num;
            cout<<"Case #"<<count<<": "<<num<<" ";
            count++;
            vector <int> rec;
            int sum = 0;
            bool not_happy = false;
            while(sum!=1){
                sum = 0;
                while(num != 0){
                    sum += (num%10)*(num%10);
                    num/=10;
                }
                num = sum;
                for(int i = 0;i<rec.size();i++){
                    if(rec[i]==sum) {
                        not_happy = true;  
                        break; 
                    }
                }
                if(not_happy) break;
                rec.push_back(sum);
            }
            if(not_happy)cout<<"is an Unhappy number."<<endl;
            else cout<<"is a Happy number."<<endl;
        
    }
}
