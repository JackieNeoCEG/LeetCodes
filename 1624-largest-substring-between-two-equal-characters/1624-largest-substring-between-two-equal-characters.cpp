class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxPair = INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j] && i != j) {
                    int pair = abs(i - j);
                    maxPair = max(maxPair, pair);
                }
            }
        } 
        if (maxPair == INT_MIN) return -1;
        return maxPair - 1;
    }
};