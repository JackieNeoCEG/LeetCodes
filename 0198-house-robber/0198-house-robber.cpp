class Solution {
public:
    int rob(vector<int>& nums) {
        //Keep track of max amt when robbing/not robbing 
        int robHouse = 0; int notRob = 0;
        for (int i = 0; i < nums.size(); i++) {
            //update new maxes 
            int newRob = notRob + nums[i];
            int newNoRob = max(notRob, robHouse);
            
            //update the variables
            robHouse = newRob;
            notRob = newNoRob;
        }
        //return max of scenarios
        return max(robHouse, notRob);
    }
};