class Solution {
public:
    // 2 5 3 1 1 1 4 trace backwards till i find an immediate jump (pos 1, 5)
    // 2 1 1 1 1 1 4
    int jump(vector<int>& nums) {
        int jumps = 0, maxLength = 0, last = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            
            maxLength = max(maxLength, nums[i] + i);
            if (i == last) {
                // need jump
                jumps++;
                last = maxLength;

            }

        }
        return jumps;
    }
};