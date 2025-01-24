class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size(); int h = haystack.size();

        if (n == 0) return 0;

        for (int i = 0; i <= h - n; i++) { // Ensure we don't go out of bounds
            bool match = true;
            for (int j = 0; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break; 
                }
            }
            if (match) return i; 
        }
        return -1;
    }
};
