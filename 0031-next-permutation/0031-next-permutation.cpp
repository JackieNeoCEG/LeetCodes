class Solution {
public:
    // arr =   [1, 2, 3, 4]
    // perms = [[1, 2, 3, 4], [1, 2, 4, 3], [1, 3, 2, 4], [1, 3, 4, 2], 
    //          [1, 4, 2, 3], [1, 4, 3, 2], [2, 1, 3, 4], [2, 1, 4, 3], 
    //          [2, 3, 1, 4], [2, 3, 4, 1], [2, 4, 1, 3], [2, 4, 3, 1]... ]
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool isDescending = true;
        int i;

        // Step 1: Find pivot from right
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                isDescending = false;
                break;  // Found pivot at i
            }
        }

        if (isDescending) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find smallest number that's greater than nums[i]
        int j;
        for (j = n - 1; j > i; j--) {
            if (nums[j] > nums[i])
                break;
        }

        // Step 3: Swap pivot and successor
        swap(nums[i], nums[j]);

        // Step 4: Reverse the suffix (from i+1 to end)
        reverse(nums.begin() + i + 1, nums.end());
    }
};