#include <bits/stdc++.h>

using namespace std;
 
int t[20] = {0,1,5,2,8,3,9,2,8,7,7,8,4,7,3,8,4,1,5,4};
 
int main()
{
string s;
while(cin>>s){
    int l=s.length();
    if(l==1&&s[0]=='0')break;
    int a=s[l-1]-'0';
    if(l>1)a+=(s[l-2]-'0')*10;
    cout<<(t[a%20]+a/20*4)%10<<endl;
}
return 0;
}
