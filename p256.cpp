#include <bits/stdc++.h>

using namespace std;

int main(){
    int input;
    vector<int> two,four,six,eight;

    for(int i = 0;i<100;i++){
        if(i>9){
            if(i == pow((i%10)+(i/10),2)) two.push_back(i);
        }else{
            if(i == pow(i,2)) two.push_back(i);
        }
    }

    for(int i = 0;i<10000;i++){
        if(i>99){
            if(i == pow((i%100)+(i/100),2)) four.push_back(i);
        }else{
            if(i == pow(i,2)) four.push_back(i);
        }
    }

    for(int i = 0;i<1000000;i++){
        if(i>999){
            if(i == pow((i%1000)+(i/1000),2)) six.push_back(i);
        }else{
            if(i == pow(i,2)) six.push_back(i);
        }
    }

    for(int i = 0;i<100000000;i++){
        if(i>9999){
            if(i == pow((i%10000)+(i/10000),2)) eight.push_back(i);
        }else{
            if(i == pow(i,2)) eight.push_back(i);
        }
    }
    while(cin >> input){
        switch(input){
            case 2:
                for(int i = 0;i<two.size();i++)
                    printf("%02d\n",two[i]);
                break;
            case 4:
                for(int i = 0;i<four.size();i++)
                    printf("%04d\n",four[i]);
                break;
            case 6:
                for(int i = 0;i<six.size();i++)
                    printf("%06d\n",six[i]);
                break;
            case 8:
                for(int i = 0;i<eight.size();i++)
                    printf("%08d\n",eight[i]);
                break;
            default:
                break;
        }
    }
}
