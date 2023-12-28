class Solution {
public:
    int minOperations(string s) {
        int ans = 0;

        // Check for alternating pattern
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != (i % 2 == 0 ? '0' : '1')) {
                ans++;
            }
        }

        // Return the minimum of the two counts
        return std::min(ans, static_cast<int>(s.size()) - ans);
    }
};
