class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numsIndex = 0;  // Index to track the position where non-zero elements should be placed

        // Iterate through the array to move non-zero elements to the front
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                // If the current element is non-zero, move it to the front and update the index
                nums[numsIndex++] = nums[i];
            }
        }

        // Fill the remaining elements with zeros from the last non-zero index to the end
        for (int i = numsIndex; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};