class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // Check if the complement is in the map
            auto it = indexMap.find(complement);
            if (it != indexMap.end()) {
                // Found a pair that sums to the target
                return {it->second, i};  // Return the indices of the pair
            }

            // Add the current number and its index to the map
            indexMap[nums[i]] = i;
        }

        // If no such pair is found
        return {-1, -1};  // Return {-1, -1} to indicate no pair found
    }
};