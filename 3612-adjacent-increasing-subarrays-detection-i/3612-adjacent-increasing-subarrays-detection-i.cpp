class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        for (int i = 0; i < nums.size() - 2 * k + 1; i++) {
            bool inc1 = true;
            bool inc2 = true;

            for (int j = i; j < i + k - 1; j++) {
                if (nums[j + 1] <= nums[j]) {
                    inc1 = false;
                    break;
                }
            }

            for (int j = i + k; j < i + 2 * k - 1; j++) {
                if (nums[j + 1] <= nums[j]) {
                    inc2 = false;
                    break;
                }
            }

            if (inc1 && inc2) {
                return true;
            }

        }
        return false;
    }
};