#include <bits/stdc++.h>

using namespace std;
int main(){
	int M, N, i, j, k, max;
	while(cin >> M >> N){
		if(M == 0 || N == 0)
            break;
		int map[M][N], input;
		max = 0;
		for(i = 0; i < M; i++){
			for(j = 0; j < N; j++){
				cin >> input;
				map[i][j] = (input == 1) ? 0 : ((i > 0) ? (map[i-1][j] + 1) : 1);
			}
			for(j = 0; j < N; j++){
				int sum = map[i][j];
				for(k = j-1; k >= 0 && map[i][k] >= map[i][j]; k--) sum += map[i][j];
				for(k = j+1; k < N && map[i][k] >= map[i][j]; k++) sum += map[i][j];
				max = (max > sum) ? max : sum;
			}
		}
		cout << max << endl;
	}
	return 0;
}
