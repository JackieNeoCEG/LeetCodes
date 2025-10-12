class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<char> used(nums.size(), false); // avoid vector<bool>

        backtrack(nums, res, path, used);

        return res;


    }

    void backtrack(vector<int>& nums, vector<vector<int>>& res, 
                   vector<int>& path, vector<char>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums, res, path, used);  // explore further

            path.pop_back();          // undo the choice
            used[i] = false;  
        }
    }
};

