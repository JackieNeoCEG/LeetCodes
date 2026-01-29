class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++) {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }

        // Second loop pass for greedy solution
        for (int j = 0; j < arr.size() - 1; j++) {
            if (minDiff == arr[j + 1] - arr[j]) {
                vector<int> pair = {arr[j], arr[j + 1]};
                res.push_back(pair);
            }
        }
        return res;
    }
};