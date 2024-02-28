# include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin >> s && s != "."){       
        string a = "";
        a += s[0];
        int cnt = 1;
        int max_cnt = 1;
        bool repeat = false;
        for(int i = 1;i<(s.size()/2);i++){
            a += s[i];
            cnt = 0;
            if(s.size()%a.size()==0){
                repeat = true;
                for(int j = 0;j<s.size();j+=a.size()){
                    // cout << s.substr(j,a.size()) << " " << a << endl;
                    cnt++;
                    if(s.substr(j,a.size()) != a){
                        repeat = false;
                        break;
                    }      
                }
                if(repeat) max_cnt = max(cnt,max_cnt);
            }
        }
        bool flag = false;
        for(int i = 1;i<s.size();i++){
            if(s[0]!= s[i]){
                flag = true;
                break;
            }
        }
        if(flag)cout << max_cnt << endl;
        else cout << s.size() << endl;
    }
    
}
