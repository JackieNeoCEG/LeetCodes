class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<vector<int>> res;

        for (int n : nums) {
            int row = count[n]; //no. of arrays needed
            if (res.size() == row) {
                res.push_back({});
            }

            res[row].push_back(n); //add curr integer to array
            count[n]++;
        }

        return res;
    }
};