class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Perform binary search using lower_bound
        auto it = lower_bound(nums.begin(), nums.end(), target);
        //lower_bound returns iterator pointing to the first element that is ≥ the target.
        //so there is no need for cases where the target cant be found
        return distance(nums.begin(), it);
    }
};