class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        //iterative approach to skip the higher cost
        for(int i = 2; i < n; i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        
        return min(cost[n - 1], cost[n - 2]);
    }
};