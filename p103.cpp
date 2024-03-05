# include <bits/stdc++.h>

using namespace std;

struct Box {
    int id;
    vector<int> dimensions;

    Box(int i = 0, int n = 0, int value = 0) {
        id = i;
        dimensions = vector<int>(n, value);
    }
};

bool compareBoxes(const Box &a, const Box &b) {
    for (int i = 0; i < a.dimensions.size(); ++i) {
        if (a.dimensions[i] < b.dimensions[i])
            return true;
        if (a.dimensions[i] > b.dimensions[i])
            return false;
    }
    return true;
}


bool canContain(const Box &a, const Box &b) {
    for (int i = 0; i < a.dimensions.size(); ++i) {
        if (a.dimensions[i] <= b.dimensions[i])
            return false;
    }
    return true;
}


void printNesting(const vector<int> &prevNesting, const vector<Box> &boxSequence, int lastBox, bool printSpace) {
    if (lastBox == -1)
        return;

    printNesting(prevNesting, boxSequence, prevNesting[lastBox], true);
    cout << boxSequence[lastBox].id;
    if (printSpace)
        cout << " ";
}

int main() {
    int k, n;
    while (cin >> k >> n) {
        vector<Box> boxSequence;
        
        
        for (int i = 0; i < k; ++i) {
            Box box(i + 1, n, 0);
            for (int j = 0; j < n; ++j) {
                cin >> box.dimensions[j];
            }
            sort(box.dimensions.begin(), box.dimensions.end());
            boxSequence.push_back(box);
        }

        
        sort(boxSequence.begin(), boxSequence.end(), compareBoxes);

        
        vector<int> maxNesting(k, 1), prevNesting(k, -1);
        int maxLength = 1, lastBox = 0;
        for (int i = 0; i < boxSequence.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (canContain(boxSequence[i], boxSequence[j])) {
                    if (maxNesting[j] + 1 > maxNesting[i]) {
                        maxNesting[i] = maxNesting[j] + 1;
                        prevNesting[i] = j;
                        if (maxNesting[i] > maxLength) {
                            maxLength = maxNesting[i];
                            lastBox = i;
                        }
                    }
                }
            }
        }

        // output
        cout << maxLength << endl;
        printNesting(prevNesting, boxSequence, lastBox, false);
        cout << endl;
    }
    return 0;
}
