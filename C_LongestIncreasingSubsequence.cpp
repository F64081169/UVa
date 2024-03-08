# include<bits/stdc++.h>
using namespace std;

int findLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> LIS(n, 1); 

    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] < nums[i] && LIS[j] + 1 > LIS[i]) {
                LIS[i] = LIS[j] + 1;
            }
        }
    }

    int maxLIS = *max_element(LIS.begin(), LIS.end());
    return maxLIS;
}

int main() {
    int size;
    cin>>size;
    vector<int> nums;
    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    int length = findLIS(nums);
    cout  << length << endl;
    return 0;
}
