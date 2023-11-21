#include <bits/stdc++.h>

using namespace std;
#define LOSE false
#define WIN true

int main() {
    int num, size;

    while (cin >> num >> size) {
        vector<int> rec;
        int n;
        for (int i = 0; i < size; i++) {
            cin >> n;
            rec.push_back(n);
        }
        vector<bool> status(num + 1, LOSE);

        for (int i = 1; i <= num; i++) {
            for (int j = 0; j < size; j++) {
                if (i - rec[j] >= 0 && status[i - rec[j]] == LOSE) {
                    status[i] = WIN;
                }
            }
        }

        if (status[num] == LOSE)
            cout << "Ollie wins" << endl;
        else
            cout << "Stan wins" << endl;
    }

    return 0;
}
