#include<bits/stdc++.h>

using namespace std;

string s = "";

int main() {
    string line;
    vector<string> rec;
    
    while (getline(cin, line) && line != "0") {
        s += line + "\n"; 
    }

    istringstream ss(s); 
    
    string word;
    while (ss >> word) {
        string cleanedWord;
        string cleanedWord2;
        int num1 = 0;
        int num2 = 0;
        int flag = 0;
        for (char c : word) {
            if (isalpha(c) && c!='\n') {
                if(flag == 0)
                    cleanedWord += c;
                else cleanedWord2 += c;
            }else if(isdigit(c)){
                if(flag == 0){
                    num1 *= 10;
                    num1 += c-'0';
                }
                else{
                    num2 *= 10;
                    num2 += c-'0';
                }
            }
            else{
                flag = 1;
                continue;
            }
        }

        if(cleanedWord != "")
            rec.push_back(cleanedWord);
        if(cleanedWord2 != "")
            if(flag) rec.push_back(cleanedWord2);
        
        num1 = 0;
        num2 = 0;
    }
    int num = 0;
    int is_num = 0;
    int word_cnt = 0;
    bool f = 0;
    for(char c : s){
        if(isdigit(c)){
            num *= 10;
            num += c-'0';
            is_num = 1;
        }else{
            if(!isalpha(c)) {               
                if(f == 0){                  
                    if(c==' '||c=='\''||c=='-')
                        word_cnt++;
                }
                f = 1;
            }else{
                f = 0;
            }
            if(is_num){
                cout << rec[word_cnt-num+2];
                auto it = rec.begin();
                rec.insert(it+word_cnt,rec[word_cnt-num+2]);
                word_cnt++;
                num = 0;
                is_num = 0;
            }
            cout << c;
        }
    }

    return 0;
}
