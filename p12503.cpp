#include <bits/stdc++.h>

using namespace std;

int main(){
	int round;

	cin >> round;
	for(int i = 0;i<round;i++){
		int n;
		cin >> n;
		vector <int> rec;
		int p = 0;
		for(int i = 0;i<n;i++){
			string str;
			int num;
			cin >> str;
			switch(str[0]){
				case 'L':
				p--;
				rec.push_back(-1);
				break;
				case 'R':
				p++;
				rec.push_back(1);
				break;
				default:
				cin >> str >> num;
				p += rec[num-1];
				rec.push_back(rec[num-1]);
				break;
			}
		}
		cout << p << endl;
	}
}
