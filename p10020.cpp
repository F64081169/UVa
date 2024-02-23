# include <bits/stdc++.h>
using namespace std;

int M;

struct Segment {
    int start;
    int end;
};

bool cmp(Segment a, Segment b) {
    if (a.start < b.start) return true;
    return false;
}

int main() {
    int testcase;
    int temp, left, right;
    Segment input;
    vector<Segment> lines, answer;

    while (cin >> testcase) {
        for (int i = 0; i < testcase; i++) {
            if (i) cout << "\n";

            cin >> M;

            lines.clear();
            while (cin >> input.start >> input.end && (input.start != 0 || input.end != 0))
                lines.push_back(input);

            sort(lines.begin(), lines.end(), cmp);

            answer.clear();
            left = 0;
            right = 0;
            for (int i = 0; i < lines.size(); i++) {
                temp = -1;
                for (; i < lines.size() && lines[i].start <= left; i++)
                    if (lines[i].end > right) {
                        right = lines[i].end;
                        temp = i;
                    }

                if (temp == -1) break;
                answer.push_back(lines[temp]);
                if (right >= M) break;
                left = right;
                i--;
            }

            if (right < M) {
                cout << "0\n";
                continue;
            }
            cout << answer.size() << "\n";
            for (int i = 0; i < answer.size(); i++)
                cout << answer[i].start << " " << answer[i].end << "\n";
        }
    }
    return 0;
}
