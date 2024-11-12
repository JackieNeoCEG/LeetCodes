class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        const int n = items.size(), m = queries.size();
        vector<int> maxB(n), answer(m);

        maxB[0] = items[0][1];

        // Build array of max beauty before price
        for (int i = 1; i < n; i++) {
            maxB[i] = max(maxB[i-1], items[i][1]);
        }

        for (int i = 0; i < m; i++) {
            int q = queries[i];
            vector<int>&& target = {q, INT_MAX};

            // Upper bound selects first item satisfying price condition
            int j = upper_bound(items.begin(), items.end(), target) - items.begin();

            if (j != 0) {
                answer[i] = maxB[j - 1];
            } else {
                // No such item exists
                answer[i] = 0;
            }
        }
        return answer;

    }
};