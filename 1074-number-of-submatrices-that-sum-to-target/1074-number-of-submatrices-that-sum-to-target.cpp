class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0; int sum = 0;
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) {
                count++;
            }
            if (mp.find(sum - k) != mp.end()) {
             count += mp[sum - k];  
            }
            mp[sum]++;
        }
        return count;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
       int count = 0; int n = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++) {
            vector<int> sum(n, 0);
            for(int j = i; j < matrix.size(); j++) {
                for(int k = 0; k < n; k++) {
                    sum[k] += matrix[j][k];
                }
                count += subarraySum(sum, target);
            }
        }
       
    return count;
    }
}; 