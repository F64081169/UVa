# include <bits/stdc++.h>   
using namespace std;

int cmp(int a, int b){
    return a > b;
}

int main(){
    int n;
    while(cin >> n && n != 0){
        vector<int> v(n);
        for(int i = 0;i<n;i++){
            cin >> v[i];
        }
        // sort in descending order
        sort(v.begin(),v.end(),cmp);
        int flag = 0;
        for(int d = 0;d<n;d++){
            for(int c = 0;c<n;c++){
                for(int b = 0;b<n;b++){
                    for(int a = 0;a<n;a++){
                        if( v[c] + v[b] + v[a] == v[d] && a != b && b != c && c != d && a != d && a != c && b != d){
                            cout << v[d] << endl;
                            flag = 1;
                            goto END_Loop;
                        }
                    }
                }
            }
        }
END_Loop:
        if(flag == 0){
            cout << "no solution" << endl;
        }
    }
}
