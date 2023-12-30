class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        // Count the frequency of each character
        unordered_map<char, int> charVal = {
            {'I', 1},{'V', 5},{'X', 10},{'L', 50},
            {'C', 100},{'D', 500},{'M', 1000}
        };
        
        for (int i = s.size() - 1; i >= 0; i--) { //backtracking from smallest
            char currCh = s[i];
            int currVal = charVal[currCh];
            
            if (i > 0) { //so prevCh isn't improperly accessed
                char prevCh = s[i - 1];
                int prevVal = charVal[prevCh];
                
                if (currVal > prevVal) {
                    ans += currVal - prevVal;
                    i--;
                } else {
                    ans += currVal;
                }
            } else {
                ans += currVal;
            }
        }
        return ans;
    }
};