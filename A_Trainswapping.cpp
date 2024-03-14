# include <bits/stdc++.h>
using namespace std;

int main() {
    int round,size;
    cin >> round;
    for (int i = 0; i < round; i++) {
        vector<int> v;
        cin >> size;
        for (int j = 0; j < size; j++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        // solve train swapping by reverse table
        vector<int> reverse_table(size,0);
        for (int j = 0; j < size; j++) {
            for(int p = j-1;p>=0;p--){
                if(v[p]>v[j]){
                    reverse_table[j]++;
                }
            }
        }
        int sum = 0;
        for (int j = 0; j < size; j++) {
            sum += reverse_table[j];
        }
        
        cout << "Optimal train swapping takes " << sum << " swaps." << endl;
    }
}
