class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> uniqueSet;
        int index = 0;

        for (int num : nums) {
            //uniqueSet.insert(num) inserts when num is absent
            //.second access next element, returns true if element is unique
            if (uniqueSet.insert(num).second) {
                nums[index++] = num;
            }
        }

        // Resize the vector to remove the elements beyond index
        nums.resize(index);

        return index;
    }
};