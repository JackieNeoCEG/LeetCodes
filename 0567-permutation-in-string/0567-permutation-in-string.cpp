class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        
        // USe frequency char arrays in s1 and sliding window in s2
        vector<int> freq_s1(26, 0), freq_window(26, 0);
        
        for (char ch: s1) {
            freq_s1[ch - 'a']++;
        }
        
        for (int i = 0; i < n; i++) {
            freq_window[s2[i] - 'a']++;
        }
        
        if (freq_s1 == freq_window) return true;
        
        // sliding window
        for (int i = n; i < m; i++) {
            freq_window[s2[i] - 'a']++;
            freq_window[s2[i - n] - 'a']--;
            
            if (freq_s1 == freq_window) return true;
        }
        return false;
        
        
    }
};