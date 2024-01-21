class Solution {
public:
    int rob(vector<int>& nums) {
        //Keep track of max amt when robbing/not robbing 
        int rob = 0; int notRob = 0;
        for (int i = 0; i < nums.size(); i++) {
            //update new maxes 
            int newRob = notRob + nums[i];
            int newNoRob = max(notRob, rob);
            
            //update the variables
            rob = newRob;
            notRob = newNoRob;
        }
        //return max of scenarios
        return max(rob, notRob);
    }
};