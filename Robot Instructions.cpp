#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;   
    for (int i = 0; i < n; i++) {
        int step;
        int pos = 0;
        cin >> step;
        string instruction;
        vector<int> direction(1, 0); 
        for (int j = 0; j < step; j++) {
            cin >> instruction;
            if (instruction == "LEFT") {
                pos--;
                direction.push_back(-1);
            } else if (instruction == "RIGHT") {
                pos++;
                direction.push_back(1);
            } else {
                int index;
                cin >> instruction; 
                cin >> index;
                pos += direction[index];
                direction.push_back(direction[index]);
            }
        }
        cout << pos << endl;
    }
}
